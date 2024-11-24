#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>


class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::unordered_set<std::string> op{"+", "-", "*","/"};
        std::stack<int> nums;
        for(const auto& x:tokens)
        {
            if(op.find(x) == op.end()) {
                nums.push(std::stoi(x));
            } else {
                int temp_sum = nums.top();
                nums.pop();
                if(!nums.empty())
                {
                    if(x == "+") {
                        nums.top() += temp_sum;
                    } else if(x == "-") {
                        nums.top() -= temp_sum;
                    } else if(x == "*") {
                        nums.top() *= temp_sum;
                    } else if(x == "/") {
                        nums.top() = (!nums.top())? 0:(nums.top()/temp_sum);
                    }
                }
            }
        }
        return nums.top();
    }
};


int main(){
    std::vector<std::string> tokens = {"4","13","5","/","+"};
    auto res = Solution().evalRPN(tokens);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}