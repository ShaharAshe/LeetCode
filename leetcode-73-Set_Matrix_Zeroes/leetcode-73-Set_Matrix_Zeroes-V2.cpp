#include <iostream>
#include <cstdlib>
#include <vector>


class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        for(size_t r = 0; r<matrix.size(); ++r)
        {
            bool is_line_zero = false;
            for(size_t c = 0; c<matrix[r].size(); ++c)
            {
                if(!matrix[r][c])
                {
                    for(size_t r_i = 0; r_i<matrix.size(); ++r_i)
                    {
                        if(matrix[r_i][c])
                        {
                            if(r_i<r){
                                matrix[r_i][c] = 0;
                            } else if(r<r_i) {
                                matrix[r_i][c] = r_i+c+999;
                            }
                        }
                    }

                    for(size_t c_i = 0; c_i<matrix[r].size() && !is_line_zero; ++c_i)
                    {
                        if(matrix[r][c_i])
                        {
                            if(c_i<c){
                                matrix[r][c_i] = 0;
                            } else if(c<c_i) {
                                matrix[r][c_i] = r+c_i+999;
                            }
                        }
                    }
                    is_line_zero = true;
                } else if(matrix[r][c] == r+c+999) {
                    matrix[r][c] = 0;
                }
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