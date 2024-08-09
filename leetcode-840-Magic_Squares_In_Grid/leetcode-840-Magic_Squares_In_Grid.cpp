#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <string>

int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
    for(size_t r = 0; r<grid.size(); ++r)
    {
        for(size_t c = 0; c<grid[r].size(); ++c)
        {
            if(grid[r][c] > 15 || grid[r][c] < 0)
            {
                return 0;
            }
        }
    }
    int num_of_magic = 0;
    int row = grid.size()-2;
    int col = grid[0].size()-2;
    for(size_t r = 0; row > 0 && r<row; ++r)
    {
        for(size_t c = 0; col > 0 && c<col; ++c)
        {
            std::vector<bool> grid_nums(9);
            bool is_magic = true;
            for(size_t m_r_c = 0; col > 0 && m_r_c < 3; ++m_r_c)
            {
                if(grid[r][c+m_r_c] > 9 || grid[r][c+m_r_c] < 1||
                   grid[r+1][c+m_r_c] > 9 || grid[r+1][c+m_r_c] < 1||
                   grid[r+2][c+m_r_c] > 9 || grid[r+2][c+m_r_c] < 1)
                {
                    is_magic = false;
                } else if(grid_nums[grid[r][c+m_r_c]] ||
                          grid_nums[grid[r+1][c+m_r_c]] ||
                          grid_nums[grid[r+2][c+m_r_c]] )
                {
                    is_magic = false;
                } else {
                    grid_nums[grid[r][c+m_r_c]] = true;
                    grid_nums[grid[r+1][c+m_r_c]] = true;
                    grid_nums[grid[r+2][c+m_r_c]] = true;
                }
            }
            

            size_t temp = grid[r][c]+grid[r][c+1]+grid[r][c+2];
            
            
            if(temp != (grid[r+1][c]+grid[r+1][c+1]+grid[r+1][c+2])||
               temp != (grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2]))
            {
                is_magic = false;
            }

            if(temp != (grid[r][c]+grid[r+1][c]+grid[r+2][c])||
               temp != (grid[r][c+1]+grid[r+1][c+1]+grid[r+2][c+1])||
               temp != (grid[r][c+2]+grid[r+1][c+2]+grid[r+2][c+2]))
            {
                is_magic = false;
            }

            if(temp != (grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2])||
               temp != (grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]))
            {
                is_magic = false;
            }

            if(is_magic)
            {
                ++num_of_magic;
            }
        }
    }

    return num_of_magic;
}


int main(){
    // std::vector<std::vector<int>> vec = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    // std::vector<std::vector<int>> vec = {{8}};
    std::vector<std::vector<int>> vec = {{5,5,5},{5,5,5},{5,5,5}};

    int res = numMagicSquaresInside(vec);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}