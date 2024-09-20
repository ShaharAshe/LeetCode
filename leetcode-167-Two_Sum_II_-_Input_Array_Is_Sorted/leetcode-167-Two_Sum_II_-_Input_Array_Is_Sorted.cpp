#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> res;

    size_t i = 0,
            j = (numbers.size()-1);
    while(i<j)
    {
        int cur_sum = (numbers[i]+numbers[j]);
        if(target<cur_sum)
        {
            --j;
        } else if(cur_sum<target) {
            ++i;
        } else {
            res.emplace_back(i+1);
            res.emplace_back(j+1);
            return res;
        }
    }
    return res;
}


int main(){
    std::vector<int> numbers = {2,7,11,15};
    int target = 9;

    auto res = twoSum(numbers, target);
    
    std::cout << "[";
    for (size_t i = 0; i<res.size(); ++i)
    {
        std::cout << res[i];
        if(i!=(res.size()-1))
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}