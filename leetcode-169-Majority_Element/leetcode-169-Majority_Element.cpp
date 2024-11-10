#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> vals_count;
        size_t half_size = nums.size()/2;
        
        for(const auto& x:nums)
        {
            if(half_size<(++vals_count[x]))
            {
                return x;
            }
        }
        return 0;
    }
};

int main() {
    std::vector<int> nums = {3,2,3};
    
    auto res = Solution().majorityElement(nums);

    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}