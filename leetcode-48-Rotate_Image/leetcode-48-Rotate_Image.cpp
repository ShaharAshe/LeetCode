#include <iostream>
#include <cstdlib>
#include <vector>


class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int r_c_len = matrix.size();
        for(int r = 0; r<r_c_len/2; ++r)
        {
            int temp_r = r, temp_c = 0;
            for(int c = 0; c<(r_c_len+1)/2; ++c)
            {
                int temp_val = matrix[temp_r][temp_c];
                for(size_t i = 0; i<=4; ++i)
                {
                    int tt_r = temp_r;
                    temp_r = temp_c;
                    temp_c = (r_c_len-(1+tt_r))%r_c_len;
                    
                    int t = matrix[temp_r][temp_c];
                    matrix[temp_r][temp_c] = temp_val;
                    temp_val = t;
                }
                temp_r = r;
                temp_c = c+1;
            }
        }
    }
};


int main(){
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    
    Solution().rotate(matrix);
    
    std::cout << "[" ;
    for(size_t r = 0; r<matrix.size(); ++r)
    {
        std::cout << "[" ;
        for(size_t c = 0; c<matrix[r].size(); ++c)
        {
            std::cout << matrix[r][c];
            if(c!=matrix[r].size()-1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]" ;
        if(r!=matrix.size()-1)
        {
            std::cout << ",";
            std::cout << std::endl;
        }
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}