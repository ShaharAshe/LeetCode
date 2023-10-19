/* -- Id = 200 -- */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

void check_bfs(int r, int c,
         const std::vector<std::vector<char>>& grid,
         std::unordered_map<std::string, size_t>& checked,
         std::queue<std::pair<size_t, size_t>>& q){
    if(grid[r][c] != '0')
        if(checked.find(std::to_string(r)+","+std::to_string(c)) == checked.end())
        {
            q.emplace(std::make_pair(r, c));
            checked.emplace(std::to_string(r)+","+std::to_string(c), 1);
        }
}

void bfs(int r, int c,
         const std::vector<std::vector<char>>& grid,
         std::unordered_map<std::string, size_t>& checked) {
    
    std::queue<std::pair<size_t, size_t>> q;

    q.emplace(std::make_pair(r, c));
    checked.emplace(std::to_string(r)+std::to_string(c), 1);

    while (!q.empty())
    {
        int new_r = q.front().first,
            new_c = q.front().second;

        if (new_r+1<grid.size())
            check_bfs(new_r+1, new_c, grid, checked, q);
        if (new_c+1<grid[0].size())
            check_bfs(new_r, new_c+1, grid, checked, q);
        if (0<new_r)
            check_bfs(new_r-1, new_c, grid, checked, q);
        if (0<new_c)
            check_bfs(new_r, new_c-1, grid, checked, q);
        q.pop();
    }
}

int numIslands(std::vector<std::vector<char>>& grid) {
    int num_of_islands = 0;
    std::unordered_map<std::string, size_t> checked = {};

    for (size_t r = 0; r < grid.size(); ++r)
    {
        for (size_t c = 0; c < grid[r].size(); ++c)
        {
            if (grid[r][c] == '1')
                if(checked.find(std::to_string(r)+","+std::to_string(c)) == checked.end())
                {
                    bfs(r, c, grid, checked);
                    ++num_of_islands;
                }
        }
    }
    return num_of_islands;
}

int main(int argc, char const *argv[])
{
std::vector<std::vector<char>> v = {
        {'1', '0', '0', '1', '1', '1', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'1', '0', '0', '1', '1', '0', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '0', '1', '0'},
        {'0', '0', '0', '1', '1', '1', '1', '0', '1', '0', '1', '1', '0', '0', '0', '0', '1', '0', '1', '0'},
        {'0', '0', '0', '1', '1', '0', '0', '1', '0', '0', '0', '1', '1', '1', '0', '0', '1', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '1', '0', '1', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
        {'0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
        {'0', '0', '0', '1', '0', '1', '0', '0', '1', '1', '0', '1', '0', '1', '1', '0', '1', '1', '1', '0'},
        {'0', '0', '0', '0', '1', '0', '0', '1', '1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
        {'0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '1', '0'},
        {'1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '1', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '1', '0', '1', '1', '1', '0', '1', '1', '0', '0'},
        {'1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
        {'0', '1', '0', '0', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0'},
        {'1', '0', '0', '1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '1'},
        {'1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0'},
        {'0', '1', '1', '0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '0', '1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1', '1', '0', '0', '0'}
    };
    
    std::cout << numIslands(v) << std::endl;
    
    return EXIT_SUCCESS;
}
