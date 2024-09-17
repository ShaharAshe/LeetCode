import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 */
public class leetcode_15_3Sum
{
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums == null || nums.length < 3)
            return result;

        Arrays.sort(nums);

        for(int i = 0; i < nums.length-2; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int j = i+1,
                k = nums.length-1;
            
                while(j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    
                    if(sum == 0)
                    {
                        result.add(Arrays.asList(nums[i], nums[j], nums[k]));

                        while(j < k && nums[j] == nums[++j]);
                        while(j < k && nums[k] == nums[--j]);
                        ++j;
                        --k;
                    } else if (sum < 0) {
                        ++j;
                    } else {
                        --k;
                    }
                }
        }
        return result;
    }
    public static void main(String[] args)
    {
        int[] nums = {1,-1,-1,0};
        List<List<Integer>> result = new leetcode_15_3Sum().threeSum(nums);
        System.out.println(result);
    }
}