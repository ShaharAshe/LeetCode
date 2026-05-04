#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> heights_blocks_stack;
        int right_i = 0,
            left_i = 0,
            max_area = INT32_MIN;

        for (size_t i = 0; i < heights.size(); ++i) {
            right_i = (!heights_blocks_stack.empty()) ? heights_blocks_stack.top() : 0;
            while (!heights_blocks_stack.empty() && heights[i] <= heights[heights_blocks_stack.top()]) {
                int current_height = heights[heights_blocks_stack.top()];
                heights_blocks_stack.pop();
                left_i = (!heights_blocks_stack.empty()) ? heights_blocks_stack.top() + 1 : 0;
                int temp_area = current_height * (right_i - left_i + 1);
                if (max_area < temp_area) {
                    max_area = temp_area;
                }
            }
            heights_blocks_stack.emplace(i);
        }
        right_i = (!heights_blocks_stack.empty()) ? heights_blocks_stack.top() : 0;
        while (!heights_blocks_stack.empty()) {
            int current_height = heights[heights_blocks_stack.top()];
            heights_blocks_stack.pop();
            left_i = (!heights_blocks_stack.empty()) ? heights_blocks_stack.top() + 1 : 0;
            int temp_area = current_height * (right_i - left_i + 1);
            if (max_area < temp_area) {
                max_area = temp_area;
            }
        }
        return max_area;
    }
};

int main() {
    std::vector<int> heights{2,1,5,6,2,3};

    auto result = Solution().largestRectangleArea(heights);

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}