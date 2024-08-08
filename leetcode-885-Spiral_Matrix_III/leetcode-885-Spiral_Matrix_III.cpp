/* -- Id = 383 -- */

#include <cstdlib>
#include <iostream>
#include <vector>


std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int cur_r = rStart,
        cur_c = cStart;
    std::vector<std::vector<int>> visited_pass;
    size_t steps = 1;

    while(visited_pass.size()!=(rows*cols))
    {
        for(size_t i = 0; i < 4; ++i)
        {
            switch(i%4){
                case 0:
                for(size_t j = 0; j < steps; ++j){
                    if(cur_r < rows && cur_r >= 0 && cur_c < cols && cur_c >= 0)
                    {
                        visited_pass.push_back({cur_r,cur_c});
                    }
                    ++cur_c;
                }
                break;
                case 1:
                for(size_t j = 0; j < steps; ++j){
                    if(cur_r < rows && cur_r >= 0 && cur_c < cols && cur_c >= 0)
                    {
                        visited_pass.push_back({cur_r,cur_c});
                    }
                    ++cur_r;
                }
                ++steps;
                break;
                case 2:
                for(size_t j = 0; j < steps; ++j){
                    if(cur_r < rows && cur_r >= 0 && cur_c < cols && cur_c >= 0)
                    {
                        visited_pass.push_back({cur_r,cur_c});
                    }
                    --cur_c;
                }
                break;
                case 3:
                for(size_t j = 0; j < steps; ++j){
                    if(cur_r < rows && cur_r >= 0 && cur_c < cols && cur_c >= 0)
                    {
                        visited_pass.push_back({cur_r,cur_c});
                    }
                    --cur_r;
                }
                ++steps;
                break;
            }                
        }
    }

    return visited_pass;
}


int main(int argc, char const *argv[])
{
    int rows = 1,
        cols = 4,
        rStart = 0,
        cStart = 0;
    
    std::vector<std::vector<int>> result = spiralMatrixIII(rows, cols, rStart, cStart);
    
    std::cout << "[" ;
    for(size_t rc = 0; rc < rows*cols; ++rc){
        if(rc != 0)
        {
            std::cout << ", " ;
        }
        std::cout << "[" << result[rc][0] << " ";
        std::cout << result[rc][1] << "]" ;
    }
    std::cout << "]" << std::endl;
    return EXIT_SUCCESS;
}


