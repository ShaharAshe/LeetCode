#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(),points.end());
        int end_v = points[0][1];
        size_t p_len = points.size(),
               res = 0;

        for(size_t i = 0; i<p_len-1; ++i)
        {
            if(end_v<points[i+1][0])
            {
                ++res;
                end_v = points[i+1][1];
            }
            end_v = std::min(end_v,points[i+1][1]);
        }
        return ++res;
    }
};


int main(){
    std::vector<std::vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    auto res = Solution().findMinArrowShots(points);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}