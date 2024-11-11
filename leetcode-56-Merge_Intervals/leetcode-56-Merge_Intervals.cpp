#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> res;

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> & a, const std::vector<int> & b)
        {
            return a[0] < b[0];
        });
        
        int start_pos = intervals[0][0],
            end_pos = intervals[0][1];

        size_t vec_size = intervals.size();
        
        for(size_t i = 0; i<vec_size; ++i)
        {
            if (((i<(vec_size-1)) && (end_pos<intervals[i+1][0])) ||
                (i==(vec_size-1)))
            {
                res.emplace_back(std::vector<int>{start_pos, end_pos});
                if (i!=(vec_size-1))
                {
                    start_pos = intervals[i+1][0];
                    end_pos = intervals[i+1][1];
                }
            }
            else
            {
                end_pos = std::max(end_pos, intervals[i+1][1]);
            }
        }
        return res;
    }
};


int main(){
    std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto res = Solution().merge(intervals);
    
    std::cout << "[";
    for(size_t r = 0; r<res.size(); ++r)
    {
        std::cout << "[";
        for(size_t c = 0; c<res[r].size(); ++c)
        {
            std::cout << res[r][c];
            if(c!=(res[r].size()-1)){
                std::cout << ",";
            }
        }
        std::cout << "]";
        if(r!=(res.size()-1)){
            std::cout << ",";
        }

    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}