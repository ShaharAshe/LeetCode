/* -- Id = 909 -- */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>


enum QUEUE_CELL{CELL_NUMBER,
                COUNTER
};

const size_t DICE = 6;

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    size_t queue_max_size = boardSize*boardSize;

    //  --- initial counter grid for BFS ---
    int **queue_grid = NULL;
    queue_grid = (int**) malloc(queue_max_size * sizeof(int*));
    if (!queue_grid)
    {
        perror("failed\n: ");
        exit(1);
    }

    for (size_t r = 0; r < queue_max_size; ++r)
    {
        queue_grid[r] = NULL;
        queue_grid[r] = (int*) malloc(2 * sizeof(int));
        if (queue_grid[r] == NULL)
        {
            perror("failed\n: ");
            exit(1);
        }

        for (size_t c = 0; c < 2; ++c)
        {
            queue_grid[r][c] = 0;
        }
    }
    // --------------------------------------
    
    
    size_t queue_size = 0,
           front_i = 0,
           back_i = 0;
           
    if (0 < boardSize)
    {
        queue_grid[front_i][CELL_NUMBER] = 1;
        ++queue_size;
    }

    while (0 < queue_size)
    {
        if (queue_grid[back_i][CELL_NUMBER] == queue_max_size)
        {
            return(queue_grid[back_i][COUNTER]);
        }
        
        int a = queue_grid[back_i][CELL_NUMBER];
        size_t curr_row = (boardSize-1)-queue_grid[back_i][CELL_NUMBER] / (boardSize+1),
               curr_coll = (queue_grid[back_i][CELL_NUMBER] % (boardSize+1))-1;
        if (curr_row % 2 == 0)
        {
            curr_coll = boardSize - curr_coll;
            --curr_coll;
            ++queue_size;
        }
        
        if (board[curr_row][curr_coll] != 0)
        {
            if (board[curr_row][curr_coll] == -1)
            {
                for (size_t i = 1; i <= DICE && (queue_grid[back_i][CELL_NUMBER] + i) < queue_max_size; ++i)
                {
                    size_t next_row = (boardSize-1)-(queue_grid[back_i][CELL_NUMBER]+i) / (boardSize+1),
                           next_coll = ((queue_grid[back_i][CELL_NUMBER]+i) % (boardSize+1))-1;
                           
                    if (next_row % 2 == 0)
                    {
                        next_coll = boardSize - next_coll;
                        --next_coll;
                        ++queue_size;
                    }

                    if(board[next_row][next_coll] != 0)
                    {
                        ++queue_size;
                        ++front_i;
                        front_i %= queue_max_size;
                        
                        a = queue_grid[back_i][CELL_NUMBER];
                        queue_grid[front_i][CELL_NUMBER] = queue_grid[back_i][CELL_NUMBER] + i;
                        queue_grid[front_i][COUNTER] = queue_grid[back_i][COUNTER] + 1;
                    }
                }
            }
            else{
                size_t next_row = (boardSize-1)-(board[curr_row][curr_coll]) / (boardSize+1),
                       next_coll = ((board[curr_row][curr_coll]) % (boardSize+1))-1;
                
                if (next_row % 2 == 0)
                {
                    next_coll = boardSize - next_coll;
                    --next_coll;
                    ++queue_size;
                }
                
                if(board[next_row][next_coll] != 0)
                {
                    ++queue_size;
                    ++front_i;
                    front_i %= queue_max_size;
                    
                    queue_grid[front_i][CELL_NUMBER] = board[curr_row][curr_coll];
                    queue_grid[front_i][COUNTER] = queue_grid[back_i][COUNTER];
                }
            }

            board[curr_row][curr_coll] = 0;
        }

        --queue_size;
        ++back_i;
        back_i %= queue_max_size;
    }
    
    
    // --- free the counter grid - the BFS grid ---
    for (size_t r = 0; r < boardSize; ++r)
    {
        free(queue_grid[r]);
        queue_grid[r] = NULL;
    }
    free(queue_grid);
    queue_grid = NULL;
    // --------------------------------------


    return(-1);
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




/*
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
*/