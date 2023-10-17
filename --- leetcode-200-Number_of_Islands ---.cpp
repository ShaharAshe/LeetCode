/* -- Id = 200 -- */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

int numIslands(std::vector<std::string>& grid) {
    int num_of_islands = 0;

    for (size_t i = 0; i < grid.size(); ++i)
    {
        for (size_t j = 0; j < grid[i].size(); ++j)
        {
            if(i == 0 && j == 0) {
                ++num_of_islands;
            } else if(i == 0 && grid[i][j] == '1' && grid[i][j-1] == '0') {
                ++num_of_islands;
            } else if(j == 0 && grid[i][j] == '1' && grid[i-1][j] == '0') {
                ++num_of_islands;
            } else if(i != 0 && j != 0 &&
                      grid[i][j] == '1' &&
                      grid[i][j-1] == '0' && grid[i-1][j] == '0') {
                ++num_of_islands;
            }
        }
    }
    return num_of_islands;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> v = {{"11000"},
                                  {"11000"},
                                  {"00100"},
                                  {"00011"}};
    
    std::cout << numIslands(v) << std::endl;
    
    return EXIT_SUCCESS;
}
