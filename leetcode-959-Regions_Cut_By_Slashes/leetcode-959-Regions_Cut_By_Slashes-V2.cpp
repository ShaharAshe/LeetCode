#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>


void bfs_process(size_t r, size_t c,
                 std::vector<std::string>& new_grid,
                 std::queue<std::pair<size_t, size_t>>& bfs_stack) {
    if(new_grid[r][c] == ' ')
    {
        bfs_stack.emplace(std::make_pair(r, c));
        new_grid[r][c] = '.';
    }
}



int regionsBySlashes(std::vector<std::string>& grid) {
    std::vector<std::string> new_grid;

    new_grid.resize((grid.size())*3);

    for (size_t r = 0; r<grid.size();++r)
    {
        for (size_t c = 0; c<grid[r].size();++c)
        {
            switch(grid[r][c])
            {
                case ' ':
                {
                    new_grid[(r*3)] += ' ';
                    new_grid[(r*3)] += ' ';
                    new_grid[(r*3)] += ' ';

                    new_grid[(r*3)+1] += ' ';
                    new_grid[(r*3)+1] += ' ';
                    new_grid[(r*3)+1] += ' ';

                    new_grid[(r*3)+2] += ' ';
                    new_grid[(r*3)+2] += ' ';
                    new_grid[(r*3)+2] += ' ';
                    break;
                }
                case '/':
                {
                    new_grid[(r*3)] += ' ';
                    new_grid[(r*3)] += ' ';
                    new_grid[(r*3)] += '/';

                    new_grid[(r*3)+1] += ' ';
                    new_grid[(r*3)+1] += '/';
                    new_grid[(r*3)+1] += ' ';

                    new_grid[(r*3)+2] += '/';
                    new_grid[(r*3)+2] += ' ';
                    new_grid[(r*3)+2] += ' ';
                    break;
                }
                case '\\':
                {
                    new_grid[(r*3)] += '\\';
                    new_grid[(r*3)] += ' ';
                    new_grid[(r*3)] += ' ';

                    new_grid[(r*3)+1] += ' ';
                    new_grid[(r*3)+1] += '\\';
                    new_grid[(r*3)+1] += ' ';

                    new_grid[(r*3)+2] += ' ';
                    new_grid[(r*3)+2] += ' ';
                    new_grid[(r*3)+2] += '\\';
                    break;
                }
            }
        }
    }

    int num_of_regions = 0;
    std::queue<std::pair<size_t, size_t>> bfs_stack;
    for (size_t r = 0; r<new_grid.size();++r)
    {
        for (size_t c = 0; c<new_grid[r].size();++c)
        {
            if(new_grid[r][c] == ' ')
            {
                bfs_stack.emplace(std::make_pair(r, c));
                new_grid[r][c] = '.';

                while(!bfs_stack.empty())
                {
                    size_t temp_r = bfs_stack.front().first,
                           temp_c = bfs_stack.front().second;
                    
                    if(temp_r<new_grid.size()-1)
                    {
                        bfs_process(temp_r+1, temp_c, new_grid, bfs_stack);
                    }
                    if(temp_c<new_grid.size()-1)
                    {
                        bfs_process(temp_r, temp_c+1, new_grid, bfs_stack);
                    }
                    if(temp_r>0)
                    {
                        bfs_process(temp_r-1, temp_c, new_grid, bfs_stack);
                    }
                    if(temp_c>0)
                    {
                        bfs_process(temp_r, temp_c-1, new_grid, bfs_stack);
                    }

                    bfs_stack.pop();
                    if(bfs_stack.empty())
                    {
                        ++num_of_regions;
                    }
                }
            }
        }
    }

    return num_of_regions;
}

int main(){
    // std::vector<std::string> vec = {"/\\","\\/"};
    // std::vector<std::string> vec = {"\\/","/\\"};
    // std::vector<std::string> vec = {"//","/ "};
    std::vector<std::string> vec = {" /\\"," \\/","\\  "};

    int res = regionsBySlashes(vec);

    std::cout << res << std::endl;
}