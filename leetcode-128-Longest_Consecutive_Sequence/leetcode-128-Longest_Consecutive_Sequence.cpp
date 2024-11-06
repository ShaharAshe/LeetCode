#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>


class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> vals_set(nums.begin(),nums.end());
        int max_v = 0;
        
        for (const auto& x : nums)
        {
            int quer_val = x,
                Seq_l = 1;
            auto it = vals_set.find(++quer_val);
            while(it != vals_set.end())
            {
                vals_set.erase(it);
                ++Seq_l;
                it = vals_set.find(++quer_val);
            }
            
            quer_val = x;
            it = vals_set.find(--quer_val);
            while(it != vals_set.end())
            {
                vals_set.erase(it);
                ++Seq_l;
                it = vals_set.find(--quer_val);
            }
            
            max_v = std::max(max_v, Seq_l);
        }
        
        return max_v;
    }
};


int main(){
    std::vector<int> nums = {100,4,200,1,3,2};

    auto res = Solution().longestConsecutive(nums);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}