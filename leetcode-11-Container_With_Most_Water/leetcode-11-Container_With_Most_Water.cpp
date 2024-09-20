#include <iostream>
#include <cstdlib>
#include <vector>


int maxArea(std::vector<int>& height) {
    size_t weight = (height.size()-1),
            res = 0,
            i = 0,
            j = weight;
    while(weight)
    {
        size_t h = (height[i]<height[j])?height[i++]:height[j--];
        size_t temp_r = (h*(weight--));
        if(res<temp_r)
        {
            res = temp_r;
        }
    }
    return res;
}


int main(){
    std::vector<int> vec = {1,8,6,2,5,4,8,3,7};

    auto res = maxArea(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}