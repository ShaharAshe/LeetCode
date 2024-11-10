#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>


class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> res;
        int start = 0,
            end = 0;
        if(!nums.empty())
        {
            start = nums[0];
            end = nums[0];
        }
        
        for(size_t i = 0; i<nums.size(); ++i)
        {
            if((i<(nums.size()-1) && nums[i+1] != (end+1)) || (i==nums.size()-1))
            {
                std::string temp = std::to_string(start);
                if(start != end)
                {
                    temp += "->" + std::to_string(end);
                }
                res.emplace_back(temp);
                if(i<(nums.size()-1))
                {
                    start = nums[i+1];
                } else {
                    break;
                }
            }
            if(i<(nums.size()-1))
            {
                end = nums[i+1];
            }
        }
        return res;
    }
};


int main(){
    std::vector<int> nums = {0,1,2,4,5,7};
    auto res = Solution().summaryRanges(nums);
    
    std::cout << "[";
    for(size_t i = 0; i<res.size(); ++i)
    {
        std::cout << "\"" <<res[i] << "\"" ;
        if(i<(res.size()-1))
        {
            std::cout << "," ;
        }
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}