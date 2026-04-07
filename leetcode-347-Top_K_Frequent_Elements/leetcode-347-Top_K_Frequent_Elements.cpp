#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, size_t> nums_counter_map;
        size_t max_counter = 0;
        for (auto &num : nums){
            if (max_counter < ++nums_counter_map[num]) {
                max_counter = nums_counter_map[num];
            }
        }
        std::vector<std::vector<int>> counter_vals_map(max_counter);
        for (auto &cell : nums_counter_map) {
            counter_vals_map[cell.second-1].emplace_back(cell.first);
        }
        std::vector<int> result;
        for (int i = counter_vals_map.size() - 1; 0 <= i && result.size() < k; --i) {
            for (size_t j = 0; j < counter_vals_map[i].size() && result.size() < k; ++j) {
                result.emplace_back(counter_vals_map[i][j]);
            }
        }
        return result;
    }
};

int main() {
    // std::vector<int> nums{1,2,2,3,3,3};
    // int k = 2;

    std::vector<int> nums{7,7};
    int k = 1;

    auto result = Solution().topKFrequent(nums, k);

    for (auto &c : result) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}