#include <iostream>
#include <cstdlib>
#include <vector>


int firstMissingPositive(std::vector<int>& nums) {
    size_t min_val = 1;
    int res = 1;
    if(nums.size() != 0){
        min_val = nums[0];
    }
    for(size_t i = 0; i<nums.size(); ++i)
    {
        if(nums[i]<min_val && nums[i]>0)
        {
            min_val = nums[i];
        }
    }
    for(size_t i = 0; i<nums.size(); ++i)
    {
        bool is_change = true;
        while (is_change)
        {
            if((0<nums[i]) && (((nums[i]-min_val)) != i) && (nums[i]-min_val)<nums.size() && nums[(nums[i]-min_val)] != nums[i])
            {
                int temp = nums[(nums[i]-min_val)];
                nums[(nums[i]-min_val)] = nums[i];
                nums[i] = temp;
            }
            else{
                is_change = false;
            }
        }
    }
    for(size_t i = 0; i<nums.size(); ++i)
    {
        if(nums[i] == res)
        {
            ++res;
        }
    }
    return res;
}

    int main(){
        // std::vector<int> vec = {2147483647, 2147483646, 2147483645, 3, 2, 1, -1, 0, -2147483648};
        // std::vector<int> vec = {1,100};
        // std::vector<int> vec = {-1,4,2,1,9,10};
        std::vector<int> vec = {1,1};
        int res = firstMissingPositive(vec);

        std::cout << res << std::endl;

        return EXIT_SUCCESS;
    }