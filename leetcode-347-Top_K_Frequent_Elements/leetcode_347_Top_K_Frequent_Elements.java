import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class leetcode_347_Top_K_Frequent_Elements
{
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> counterMap = new HashMap<>();
        int maxValue = 0;
        for (Integer num : nums) {
            int value = counterMap.getOrDefault(num, 0) + 1;
            counterMap.put(num,  value);
            maxValue = Math.max(value, maxValue);
        }
        List<ArrayList<Integer>> bucketCounters = new ArrayList<>();
        for (int i = 0; i < maxValue; ++i) {
            bucketCounters.add(new ArrayList<>());
        }
        for (Map.Entry<Integer, Integer> cell : counterMap.entrySet()) {
            bucketCounters.get(cell.getValue() - 1).add(cell.getKey());
        }
        int[] result = new int[k];
        int place = 0;
        for (int i = bucketCounters.size() - 1; i >= 0 && place < k; --i) {
            for (int j = 0; j < bucketCounters.get(i).size() && place < k; ++j) {
                result[place++] = bucketCounters.get(i).get(j);
            }
        }
        return result;
    }

    public static void main(String[] args)
    {
        int[] nums = {1,1,1,2,2,3};
        int k = 2;
        int[] result = new leetcode_347_Top_K_Frequent_Elements().topKFrequent(nums, k);
        System.out.print("[ ");
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println("]");
    }
}