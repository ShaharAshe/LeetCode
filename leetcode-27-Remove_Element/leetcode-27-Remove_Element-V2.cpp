#include <iostream>
#include <vector>


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int res = nums.size(),
            j = res-1;
        for(int i = 0; i<res; ++i)
        {
            if(nums[i] == val)
            {
                int temp_val = nums[i];
                nums[i--] = nums[j];
                nums[j--] = temp_val;
                --res;
            }
        }
        return res;
    }
};


int main() {
    std::vector<int> v1 = {3,2,2,3};
    int val = 3;

    auto res = Solution().removeElement(v1, val);

    std::cout << "[";
    for(int i = 0; i < res; ++i)
    {
        std::cout << v1[i];
        if(i < res-1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}