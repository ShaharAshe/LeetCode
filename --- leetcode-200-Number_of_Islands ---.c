/* -- Id = 200 -- */

#include <stdio.h>

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int num_of_islands = 0,
        i, j;

    for (i = 0; i < gridSize; ++i)
    {
        for (j = 0; j < gridColSize[i]; ++j)
        {
            if(i == 0 && j == 0) {
                ++num_of_islands;
            } else if(i == 0 && grid[i][j] == '1' && grid[i][j] == '0') {
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
    char grid[4][5] = {{'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int gridColSize[] = {5, 5, 5, 5};
    printf("%d\n", numIslands((char**)grid, 4, gridColSize));

    return 0;
}
