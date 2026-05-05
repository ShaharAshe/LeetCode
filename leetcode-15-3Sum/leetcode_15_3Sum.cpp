#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (1 <= i && nums[i] == nums[i - 1]) {
                continue;
            }
            int left_i = i + 1,
                right_i = nums.size() - 1;
            
            while (left_i < nums.size() && left_i < right_i) {
                int sum = nums[i] + nums[left_i] + nums[right_i];
                if (sum == 0) {
                    std::vector<int> temp_vector{nums[i], nums[left_i], nums[right_i]};
                    result.emplace_back(temp_vector);
                    ++left_i;
                    while (left_i < nums.size() && nums[left_i] == nums[left_i - 1]) {
                        ++left_i;
                    }
                }
                if (sum < 0) {
                    ++left_i;
                } else {
                    --right_i;
                }
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums{-1,0,1,2,-1,-4};
    // std::vector<int> nums{0,0,0,0};

    auto result = Solution().threeSum(nums);

    for (auto &arr : result) {
        for (auto &c : arr) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}