#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> monotonical_stack;
        std::vector<int> results(temperatures.size(), 0);
        for (size_t i = 0; i< temperatures.size(); ++i) {
            while (!monotonical_stack.empty() && temperatures[monotonical_stack.top()] < temperatures[i]) {
                results[monotonical_stack.top()] = i-(monotonical_stack.top());
                monotonical_stack.pop();
            }
            monotonical_stack.push(i);
        }
        return results;
    }
};

int main() {
    std::vector<int> temperatures{73,74,75,71,69,72,76,73};

    auto result = Solution().dailyTemperatures(temperatures);

    for (auto &c : result) {
        std::cout << c << " " ;
    }
    std::cout << std::endl;
    

    return EXIT_SUCCESS;
}