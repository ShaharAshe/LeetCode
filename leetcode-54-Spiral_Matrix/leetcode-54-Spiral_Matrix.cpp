#include <iostream>
#include <cstdlib>
#include <vector>


class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        for(int i = 0;i<=(matrix[0].size()-1)/2 && i<=(matrix.size()-1)/2; ++i)
        {
            int r = i, c = i;
            if(c<matrix[0].size()-(i))
            {
                for(;c<matrix[0].size()-(i); ++c)
                {
                    res.emplace_back(matrix[r][c]);
                }
                --c;
                ++r;
                if(r<matrix.size()-(i))
                {
                    for(; r<matrix.size()-(i); ++r)
                    {
                        res.emplace_back(matrix[r][c]);
                    }
                    --r;
                    --c;
                    if(i<=c)
                    {
                        for(;i<=c; --c)
                        {
                            res.emplace_back(matrix[r][c]);
                        }
                        ++c;
                        --r;
                        if(i<r)
                        {
                            for(; i<r; --r)
                            {
                                res.emplace_back(matrix[r][c]);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};



int main(){
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    auto res = Solution().spiralOrder(matrix);
    
    std::cout << "[" ;
    for(size_t i = 0; i<res.size(); ++i)
    {
        std::cout << res[i];
        if(i!=res.size()-1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}