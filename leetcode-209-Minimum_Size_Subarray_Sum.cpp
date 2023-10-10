/* -- Id = 209 -- */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int minSubArrayLen(int target, std::vector<int>& nums) {
    size_t i = 0,
           j = 0;

    int count = 0,
        sum = 0;
    
    int min_sub = INT_MAX;
    
    for (; i < nums.size(); ++i)
    {
        sum += nums[i];
        for (; target <= sum && j <= i; ++j)
        {
            sum -= nums[j];
            count = i-j+1;
            
            min_sub = std::min(count, min_sub);
        }
    }

    return (sum == 0)?0:min_sub;
}
    

int main(int argc, char const *argv[])
{
    std::vector<int> v = {2, 3, 1, 2, 4, 3};
    std::cout << minSubArrayLen(7, v) << std::endl;
    return EXIT_SUCCESS;
}
