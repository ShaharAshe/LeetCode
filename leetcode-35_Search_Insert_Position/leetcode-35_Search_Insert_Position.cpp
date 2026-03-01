#include <iostream>
#include <cstdlib>
#include <vector>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        size_t left = 0,
               right = nums.size() - 1,
               mid = (left + right) / 2;
        while (left < right) {
            int value = nums[mid];
            if (value == target) {
                return mid;
            } else if (value < target) {
                left = (mid < nums.size()) ? mid + 1 : mid;
            } else {
                right = (0 < mid) ? mid - 1 : mid;
            }
            mid = (left + right) / 2;
        }
        return (nums[mid] < target) ? mid+1 : mid;
    }
};


int main(){
    std::vector<int> nums = {1,3};
    int target = 0;

    auto res = Solution().searchInsert(nums, target);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}