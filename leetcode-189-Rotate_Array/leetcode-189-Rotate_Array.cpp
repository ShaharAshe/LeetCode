#include <iostream>
#include <cstdlib>
#include <vector>


void rotate(std::vector<int>& nums, int k) {
    if(nums.size() == 1 || nums.empty())
    {
        return;
    }
    int len = (nums.size()-(k%nums.size()));
    for(size_t time = 0; time<len; ++time)
    {
        nums.emplace_back(nums[time]);
    }

    nums.erase(nums.begin(), nums.begin()+len);
}

int main(){
    // std::vector<int> vec = {1,2,3,4,5,6,7};
    // int k = 3;

    std::vector<int> vec = {-1,-100,3,99};
    int k = 2;
    
    rotate(vec, k);

    std::cout << "[";
    for(size_t i = 0; i<vec.size(); ++i)
    {
        std::cout << vec[i];
        if(i!=(vec.size()-1))
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}


//  ----- Works but not effective -----
// void rotate(std::vector<int>& nums, int k) {
// if(nums.size() == 1 || nums.empty())
//     {
//         return;
//     }
//     for(size_t time = 0; time<k; ++time)
//     {
//         int temp_num = -1;
//         int prev = temp_num;
//         size_t i = 0;
//         for(; i<(nums.size()-1); ++i)
//         {
//             prev = temp_num;
//             temp_num = nums[i];
//             nums[i] = prev;
//         }
//         prev = temp_num;
//         temp_num = nums[i];
//         nums[i] = prev;
//         nums[0] = temp_num;
//     }
// }