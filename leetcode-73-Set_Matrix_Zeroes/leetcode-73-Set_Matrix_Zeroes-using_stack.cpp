#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>


class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::unordered_map<size_t, size_t> row_v;
        std::unordered_map<size_t, size_t> col_v;

        for(size_t r = 0; r<matrix.size(); ++r)
        {
            for(size_t c = 0; c<matrix[r].size(); ++c)
            {
                if(!matrix[r][c])
                {
                    ++row_v[r];
                    ++col_v[c];
                }
            }
        }

        for(const auto& x:row_v)
        {
            size_t r = x.first;
            for(size_t c = 0; c<matrix[r].size(); ++c)
            {
                matrix[r][c] = 0;
            }
        }

        for(const auto& x:col_v)
        {
            size_t c = x.first;
            for(size_t r = 0; r<matrix.size(); ++r)
            {
                matrix[r][c] = 0;
            }
        }
    }
};



int main(){
    std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

    // std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    
    Solution().setZeroes(matrix);
    
    std::cout << "[" ;
    for(size_t i = 0; i<matrix.size(); ++i)
    {
        std::cout << "[";
        for(size_t j = 0; j<matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j];
            if(j!=matrix[i].size()-1)
                std::cout << ",";
        }
        std::cout << "]";
        if(i!=matrix.size()-1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}