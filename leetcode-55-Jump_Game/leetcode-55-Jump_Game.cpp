#include <iostream>
#include <cstdlib>
#include <vector>


bool canJump(std::vector<int>& nums) {
    if(nums.size() == 1)
        return true;
    for(size_t i = 0; i<nums.size(); ++i)
    {
        if((nums.size()-1)<=i+nums[i])
            return true;
        int max = -1;
        for(size_t j = 0; j<nums[i] && (i+j+1)<nums.size(); ++j)
        {
            int a = nums[i+j+1];
            if(a == 0)
                continue;
            if((nums.size()-1)<=(i+j+1+a))
                return true;
            
            if(max == -1 || nums[max]<=nums[i+j+1])
            {
                for(size_t k = 1; k<=a; ++k)
                {
                    if(max == -1 && nums[i+j+1+k] != 0){
                        max = i+j+1;
                    } else if(max != -1 && nums[max]<=nums[i+j+1] && nums[i+j+1+k] != 0) {
                        max = i+j+1;
                    }
                }
            }
        }
        if(max == -1)
            return false;
        i = (--max);
    }
    return false;
}

int main(){
    // std::vector<int> vec = {2,3,1,1,4};
    // std::vector<int> vec = {3,2,1,0,4};
    // std::vector<int> vec = {2,0,0};
    // std::vector<int> vec = {5,9,3,2,1,0,2,3,3,1,0,0};
    // std::vector<int> vec = {4,2,0,0,1,1,4,4,4,0,4,0};
    // std::vector<int> vec = {1,3,2};
    std::vector<int> vec = {1,1,2,2,0,1,1};


    bool res = canJump(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}