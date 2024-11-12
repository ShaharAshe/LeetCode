#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        if(intervals.empty())
        {
            intervals.emplace_back(newInterval);   
        }
        for(size_t i = 0; i<intervals.size(); ++i)
        {
            if(newInterval[0]<=intervals[i][1] && newInterval[1]>=intervals[i][0]) {
                intervals[i][1] = std::max(newInterval[1], intervals[i][1]);
                intervals[i][0] = std::min(newInterval[0], intervals[i][0]);
            } else if(newInterval[0]<intervals[i][0]) {
                intervals.insert((intervals.begin()+i), newInterval);
                break;
            } else if(i==(intervals.size()-1)) {
                intervals.emplace_back(newInterval);
                break;
            } else {
                continue;
            }
            
            while(i<(intervals.size()-1) && intervals[i+1][0]<=intervals[i][1])
            {
                intervals[i][1] = std::max(intervals[i+1][1], intervals[i][1]);
                intervals.erase((intervals.begin()+(i+1)));
            }
            break;
            
        }
        return intervals;
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