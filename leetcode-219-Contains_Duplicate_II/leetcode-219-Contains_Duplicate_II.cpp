#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>


class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> vals_ind;
        for(int i = 0; i<nums.size(); ++i)
        {
            if(vals_ind.find(nums[i]) != vals_ind.end() &&
               std::abs(i-vals_ind[nums[i]])<=k)
            {
                return true;
            }
            vals_ind[nums[i]] = i;
        }
        return false;
    }
};


int main(){
    std::vector<int> nums = {1,2,3,1};
    int k = 3;

    auto res = Solution().containsNearbyDuplicate(nums, k);

    if(res){
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return EXIT_SUCCESS;
}