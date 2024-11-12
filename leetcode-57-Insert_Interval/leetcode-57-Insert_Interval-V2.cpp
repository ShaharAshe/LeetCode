#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        size_t inter_len = intervals.size();
        for(size_t i = 0; i<inter_len; ++i)
        {
            if(newInterval[0]<intervals[i][0])
            {
                intervals.insert((intervals.begin()+i), newInterval);
                break;
            } else if(i==(inter_len-1)) {
                intervals.emplace_back(newInterval);
                break;
            }
        }
        if(!inter_len)
        {
            intervals.emplace_back(newInterval);
        }
        ++inter_len;
        std::vector<std::vector<int>> res;
        int start_v = intervals[0][0],
            end_v = intervals[0][1];

        for(size_t i = 0; i<inter_len; ++i)
        {
            if((i<(inter_len-1) && end_v<intervals[i+1][0]) || (i==(inter_len-1)))
            {
                res.emplace_back(std::vector<int>{start_v, end_v});
                if(i<(inter_len-1))
                {
                    start_v = intervals[i+1][0];
                    end_v = intervals[i+1][1];
                }
            } else {
                end_v = std::max(end_v, intervals[i+1][1]);
            }
        }
        return res;
    }
};


int main(){
    std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
    std::vector<int> newInterval = {2,5};

    auto res = Solution().insert(intervals, newInterval);
    
    std::cout << "[";
    for(size_t i = 0; i<res.size(); ++i)
    {
        std::cout << "[";
        for(size_t j = 0; j<res[i].size(); ++j)
        {
            std::cout << res[i][j];
            if(j<(res[i].size()-1))
            {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if(i<(res.size()-1))
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}