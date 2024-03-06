#include <iostream>
#include <vector>


int removeElement(std::vector<int>& nums, int val) {
    std::vector<int> temp;
    for(size_t i = 0; i < nums.size(); ++i)
        if(nums[i] != val)
            temp.emplace_back(nums[i]);
    
    nums = temp;
    return temp.size();
}


int main() {
    // [3,2,2,3]
    std::vector<int> v1;
    v1.emplace_back(3);
    v1.emplace_back(2);
    v1.emplace_back(2);
    v1.emplace_back(3);

    int val = 3;
    std::cout << removeElement(v1, val) << std::endl;
    //[2,2,_,_]

    // [0,1,2,2,3,0,4,2]
    std::vector<int> v2;
    v2.emplace_back(0);
    v2.emplace_back(1);
    v2.emplace_back(2);
    v2.emplace_back(2);
    v2.emplace_back(3);
    v2.emplace_back(0);
    v2.emplace_back(4);
    v2.emplace_back(2);
    
    val = 2;
    std::cout << removeElement(v2, val) << std::endl;
    
    return EXIT_SUCCESS;
}