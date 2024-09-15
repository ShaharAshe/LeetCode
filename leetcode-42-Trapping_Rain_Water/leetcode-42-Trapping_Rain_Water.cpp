#include <iostream>
#include <cstdlib>
#include <vector>


int trap(std::vector<int>& height) {
    int max_left_v = 0, max_right_v = -1,
        max_right_i = 0,
        res = 0;

    for(size_t i = 0; i<height.size(); ++i)
    {
        if(max_right_i == i)
        {
            max_right_v = -1;
            for(size_t j = (max_right_i+1); j<height.size(); ++j)
            {
                if(max_right_v<=height[j])
                {
                    max_right_v = height[j];
                    max_right_i = j;
                }
            }
        }
        int min_max = std::min(max_left_v,max_right_v);
        if(height[i]<min_max)
        {
            res += (min_max-height[i]);
        }
        max_left_v = std::max(max_left_v, height[i]);
    }
    return res;
}


int main(){
    std::vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    auto res = trap(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}