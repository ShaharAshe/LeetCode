import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=228 lang=java
 *
 * [228] Summary Ranges
 */
public class leetcode_228_SummaryRanges
{
    public List<String> summaryRanges(int[] nums) {
        int startRange = 0,
            endRange;

        List<String> rangesList = new ArrayList<String>();
        
        for(int i = 0; i<nums.length; ++i)
        {
            if(i == 0)
                startRange = nums[i];
            endRange = nums[i];
            
            if(i+1 == nums.length || nums[i]+1 < nums[i+1] || nums[i] > nums[i+1])
            {
                String curRange = Integer.toString(startRange);
                
                if(startRange < endRange)
                {
                    curRange += "->";
                    curRange += Integer.toString(endRange);
                }

                rangesList.add(curRange);

                if(i+1 < nums.length)
                    startRange = nums[i+1];
            }
        }

        return rangesList;
    }

    public static void main(String[] args)
    {
        int[] nums = {2, -1};
        List<String> result = new leetcode_228_SummaryRanges().summaryRanges(nums);
        System.out.println(result);
    }
}