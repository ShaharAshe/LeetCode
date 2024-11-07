using System;
using System.Collections.Generic;


public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> vals_inds = new Dictionary<int, int>();
        int[] res = new int[2];
        
        for(int i = 0; i<nums.Length; ++i)
        {
            int diff = (target-nums[i]);
            if(vals_inds.ContainsKey(diff))
            {
                res[0] = i;
                res[1] = vals_inds[diff];
                return res;
            }
            vals_inds[nums[i]] = i;
        }
        return res;
    }
}


public class Program
{
    public static void Main(string[] args)
    {
        int[] nums = {2,7,11,15};
        int target = 9;
        
        Solution solution = new Solution();
        int[] res = solution.TwoSum(nums, target);
        
        Console.Write("[");
        for(int i = 0; i<res.Length; ++i)
        {
            Console.Write(res[i]);
            if(i<res.Length-1)
            {
                Console.Write(", ");
            }
        }
        Console.Write("]");
    }
}