#include <iostream>
#include <cstdlib>
#include <vector>


int jump(std::vector<int>& nums) {
    size_t count = 0;
    if(nums.size() == 1)
        return count;
    for(size_t i = 0; i<nums.size(); ++i)
    {
        size_t jump = nums[i];
        size_t new_i = 0;
        for(size_t j = 1; j<=jump; ++j)
        {
            if((i+j)>=nums.size()-1)
                return (++count);

            if(j == 1 || new_i+nums[new_i]<(j+i)+nums[i+j])
            {
                new_i = i+j;
            }
        }
        i = (--new_i);
        ++count;
    }
    return count;
}

int main(){
    // std::vector<int> vec = {2,3,1,1,4};
    // std::vector<int> vec = {0};
    std::vector<int> vec = {1,2,1,1,1};

    int res = jump(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}