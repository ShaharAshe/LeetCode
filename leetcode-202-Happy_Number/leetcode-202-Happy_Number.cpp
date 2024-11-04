#include <iostream>
#include <cstdlib>
#include <unordered_map>


class Solution {
public:
    bool isHappy(int n) {
        std::unordered_map<int, bool> pow_nums;

        if (n==1)
        {
            return true;
        }

        while(n!=1)
        {
            int temp_sum = 0;
            
            while(n!=0)
            {
                temp_sum += ((n%10)*(n%10));
                n /= 10;
            }
            n = temp_sum;
            if(pow_nums.find(n) != pow_nums.end())
            {
                return false;
            }
            pow_nums[n] = true;
        }
        return true;
    }
};


int main(){
    int n = 19;

    auto res = Solution().isHappy(n);

    if(res) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return EXIT_SUCCESS;
}