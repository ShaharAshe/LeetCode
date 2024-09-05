#include <iostream>
#include <cstdlib>
#include <vector>


std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res_left;
    res_left.resize(nums.size(), 1);

    std::vector<int> res_right;
    res_right.resize(nums.size(), 1);

    for(size_t i=1; i<res_left.size(); ++i){
        res_left[i] = res_left[i-1]*nums[i-1];
        res_right[res_right.size()-1-i] = res_right[res_right.size()-1-i+1]*nums[res_right.size()-1-i+1];
    }
    for(size_t i=0; i<res_left.size(); ++i){
        res_left[i] = res_left[i]*res_right[i];
    }

    return res_left;
}



int main(){
    std::vector<int> vec = {1,2,3,4};

    auto res = productExceptSelf(vec);

    std::cout << "[";
    for (size_t i = 0; i < res.size(); ++i)
    {
        std::cout << res[i];
        if(i!=res.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}