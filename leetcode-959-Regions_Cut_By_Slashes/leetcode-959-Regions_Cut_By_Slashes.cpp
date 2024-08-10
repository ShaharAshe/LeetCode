#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>


void bfs_process(std::unordered_map<std::string,
                 bool>& visit,
                 size_t r, size_t c,
                 char cell,
                 std::queue<std::pair<size_t, size_t>>& dfs_stack){
    if(visit.find(std::to_string(r)+','+std::to_string(c)) == visit.end())
    {
        if(cell == ' ')
        {
            dfs_stack.emplace(std::make_pair(r, c));
        }
        visit.insert({std::to_string(r)+','+std::to_string(c), true});
    }
}


int regionsBySlashes(std::vector<std::string>& grid) {
    std::vector<std::string> temp_grid;
    std::unordered_map<std::string, bool> visit;

    temp_grid.resize((grid.size())*3);

    for (size_t r = 0; r<grid.size();++r)
    {
        for (size_t c = 0; c<grid[r].size();++c)
        {
            switch(grid[r][c])
            {
                case ' ':
                {
                    temp_grid[(r*3)] += ' ';
                    temp_grid[(r*3)] += ' ';
                    temp_grid[(r*3)] += ' ';

                    temp_grid[(r*3)+1] += ' ';
                    temp_grid[(r*3)+1] += ' ';
                    temp_grid[(r*3)+1] += ' ';

                    temp_grid[(r*3)+2] += ' ';
                    temp_grid[(r*3)+2] += ' ';
                    temp_grid[(r*3)+2] += ' ';
                    break;
                }
                case '/':
                {
                    temp_grid[(r*3)] += ' ';
                    temp_grid[(r*3)] += ' ';
                    temp_grid[(r*3)] += '/';

                    temp_grid[(r*3)+1] += ' ';
                    temp_grid[(r*3)+1] += '/';
                    temp_grid[(r*3)+1] += ' ';

                    temp_grid[(r*3)+2] += '/';
                    temp_grid[(r*3)+2] += ' ';
                    temp_grid[(r*3)+2] += ' ';
                    break;
                }
                case '\\':
                {
                    temp_grid[(r*3)] += '\\';
                    temp_grid[(r*3)] += ' ';
                    temp_grid[(r*3)] += ' ';

                    temp_grid[(r*3)+1] += ' ';
                    temp_grid[(r*3)+1] += '\\';
                    temp_grid[(r*3)+1] += ' ';

                    temp_grid[(r*3)+2] += ' ';
                    temp_grid[(r*3)+2] += ' ';
                    temp_grid[(r*3)+2] += '\\';
                    break;
                }
            }
        }
    }

    int num_of_regions = 0;
    std::queue<std::pair<size_t, size_t>> dfs_stack;
    for (size_t r = 0; r<temp_grid.size();++r)
    {
        for (size_t c = 0; c<temp_grid[r].size();++c)
        {
            if(temp_grid[r][c] == ' ')
            {
                if(visit.find(std::to_string(r)+','+std::to_string(c)) == visit.end())
                {
                    dfs_stack.emplace(std::make_pair(r, c));
                    visit.insert({std::to_string(r)+','+std::to_string(c), true});
                }
            }
            while(!dfs_stack.empty())
            {
                size_t temp_r = dfs_stack.front().first,
                       temp_c = dfs_stack.front().second;
                
                if(temp_r<temp_grid.size()-1)
                {
                    bfs_process(visit, temp_r+1, temp_c, temp_grid[temp_r+1][temp_c], dfs_stack);
                }
                if(temp_c<temp_grid.size()-1)
                {
                    bfs_process(visit, temp_r, temp_c+1, temp_grid[temp_r][temp_c+1], dfs_stack);
                }
                if(temp_r>0)
                {
                    bfs_process(visit, temp_r-1, temp_c, temp_grid[temp_r-1][temp_c], dfs_stack);
                }
                if(temp_c>0)
                {
                    bfs_process(visit, temp_r, temp_c-1, temp_grid[temp_r][temp_c-1], dfs_stack);
                }

                dfs_stack.pop();
                if(dfs_stack.empty())
                {
                    ++num_of_regions;
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