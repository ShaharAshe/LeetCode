/* -- Id = 909 -- */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>


int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    //  --- initial counter grid for BFS ---
    int **count_grid = NULL;
    count_grid = (int**) malloc(boardSize* sizeof(int*));
    if (!count_grid)
    {
        perror("failed\n: ");
        exit(1);
    }

    for (size_t r = 0; r < boardSize; ++r)
    {
        count_grid[r] = NULL;
        count_grid[r] = (int*) malloc(boardColSize[r] * sizeof(int));
        if (count_grid[r] == NULL)
        {
            perror("failed\n: ");
            exit(1);
        }

        for (size_t c = 0; c < boardColSize[0]; ++c)
        {
            count_grid[r][c] = 0;
        }
    }
    // --------------------------------------

    // bool is_right = true;
    
    for (size_t curr = 1; curr < boardSize*boardSize; ++curr)
    {
        size_t row_first = (boardSize-1) - curr/boardSize,
               col_first = (row_first%2==0)? (boardSize-1) - (curr-1)%boardSize : ((curr-1)%boardSize);

        for (size_t throw = 0; throw <= 6 && throw+curr < boardSize*boardSize; ++throw)
        {
            size_t new_curr = curr+throw,
                   new_curr_1 = (new_curr%boardSize == 0)? new_curr-1 : new_curr;
            int num_of_throws = (new_curr_1/boardSize)+1;

            size_t row_curr = (boardSize-1) - (new_curr_1/boardSize),
                   col_curr = (row_curr%2==0)? (boardSize) - (new_curr)%boardSize : ((new_curr-1)%boardSize);
            if (col_curr == boardSize)
            {
                col_curr = 0;
            }
            
            int val = board[row_curr][col_curr];
            int count_val = count_grid[row_first][col_first];
            
            if (throw != 0)
            {
                if (count_grid[row_curr][col_curr] == 0 ||
                    count_val+1 < count_grid[row_curr][col_curr] ||
                    num_of_throws < count_grid[row_curr][col_curr])
                {
                    count_grid[row_curr][col_curr] = count_val+1;
                }
                
            }
            if (val != -1)
            {
                size_t row_next = val/boardSize,
                       col_next = (row_next%2==0)? val%boardSize : boardSize - (val%boardSize);
                
                if (count_grid[row_next][col_next] == 0 || count_val < count_grid[row_next][col_next])
                {
                    count_grid[row_next][col_next] = count_val;
                }
            }
        }
    }

    return (count_grid[0][boardSize-1] == 0)?-1:count_grid[0][boardSize-1];

    // --- free the counter grid - the BFS grid ---
    for (size_t r = 0; r < boardSize; ++r)
    {
        free(count_grid[r]);
        count_grid[r] = NULL;
    }
    free(count_grid);
    count_grid = NULL;
    // --------------------------------------
}

int main(int argc, char const *argv[])
{
    // [[-1,-1,-1,-1,-1,-1],
    // [-1,-1,-1,-1,-1,-1],
    // [-1,-1,-1,-1,-1,-1],
    // [-1,35,-1,-1,13,-1],
    // [-1,-1,-1,-1,-1,-1],
    // [-1,15,-1,-1,-1,-1]]
    int **board = NULL;
    int line_1 [6] = {-1,-1,-1,-1,-1,-1};
    int line_2 [6] = {-1,-1,-1,-1,-1,-1};
    int line_3 [6] = {-1,-1,-1,-1,-1,-1};
    int line_4 [6] = {-1,35,-1,-1,13,-1};
    int line_5 [6] = {-1,-1,-1,-1,-1,-1};
    int line_6 [6] = {-1,15,-1,-1,-1,-1};

    board = (int**) malloc(6* sizeof(int*));
    board[0] = line_1;
    board[1] = line_2;
    board[2] = line_3;
    board[3] = line_4;
    board[4] = line_5;
    board[5] = line_6;
    

    // int board [][6] = {{-1,-1,-1,-1,-1,-1},
    //                   {-1,-1,-1,-1,-1,-1},
    //                   {-1,-1,-1,-1,-1,-1},
    //                   {-1,35,-1,-1,13,-1},
    //                   {-1,-1,-1,-1,-1,-1},
    //                   {-1,15,-1,-1,-1,-1}};
    
    int gridColSize[] = {6, 6, 6, 6, 6, 6};

    printf("%d\n", snakesAndLadders(board, 6, gridColSize));

    return 0;
}
