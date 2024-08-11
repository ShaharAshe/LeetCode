#include <iostream>
#include <cstdlib>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int k = nums.size();
    for(size_t i = 2; i<k; ++i)
    {
        if(nums[i] == nums[i-1] && nums[i] == nums[i-2])
        {
            for(size_t j = i+1; j<k; ++j)
            {
                nums[j-1]=nums[j];
            }
            --k;
            --i;
        }
    }
    return k;
}

int main(){
    std::vector<int> vec = {0,0,1,1,1,1,2,3,3};
    int res = removeDuplicates(vec);
    
    for(size_t i = 0; i<res; ++i){
        if(i == 0){
            std::cout << "[";
        }
        std::cout << vec[i] ;

        if(i != (res-1)){
            std::cout << ", ";
        } else {
            std::cout << "]" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}