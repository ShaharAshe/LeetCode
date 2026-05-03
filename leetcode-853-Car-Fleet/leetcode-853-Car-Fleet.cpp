#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> combined;
        for (int i = 0; i < position.size(); i++) {
            combined.push_back({position[i], speed[i]});
        }
        std::sort(combined.begin(), combined.end(),
              [](const auto& a, const auto& b) {
                  return a.first > b.first;
              });
        for (int i = 0; i < combined.size(); i++) {
            position[i] = combined[i].first;
            speed[i] = combined[i].second;
        }
        std::stack<double> fleet_stack;

        for (size_t i = 0; i < position.size(); ++i) {
            double temp_time_to_reach_target = (static_cast<double>(target - position[i]) / speed[i]);
            if (fleet_stack.empty() || fleet_stack.top() < temp_time_to_reach_target) {
                fleet_stack.push(temp_time_to_reach_target);
            }
        }
        return fleet_stack.size();
    }
};

int main() {
    // int target = 10;
    // std::vector<int> position{4,1,0,7};
    // std::vector<int> speed{2,2,1,1};

    int target = 10;
    std::vector<int> position{6,8};
    std::vector<int> speed{3,2};

    auto result = Solution().carFleet(target, position, speed);

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}