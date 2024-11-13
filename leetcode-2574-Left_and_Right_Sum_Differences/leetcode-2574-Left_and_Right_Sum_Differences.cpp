#include <iostream>
#include <cstdlib>
#include <vector>


class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        size_t arr_len = nums.size();
        std::vector<int> res_r(arr_len,0);
        std::vector<int> res_l(arr_len,0);
        
        for(size_t i=1; i<arr_len; ++i) {
            res_l[i] = res_l[i-1]+nums[i-1];
        }
        for(int i=arr_len-2; 0<=i; --i) {
            res_r[i] = res_r[i+1]+nums[i+1];
        }
        
        for(int i=0; i<arr_len; ++i) {
            nums[i] = std::abs(res_l[i]-res_r[i]);
        }
        
        return nums;
    }
};


int main(){
    std::vector<int> nums = {10,4,8,3};

    auto res = Solution().leftRightDifference(nums);

    std::cout << "[";
    for(size_t i=0; i<res.size(); ++i) {
        std::cout << res[i];
        if(i<res.size()-1) {
            std::cout << ",";
        }
    }
    std::cout << "]";

    return EXIT_SUCCESS;
}