/* -- Id = 909 -- */

#include <stdio.h>
#include <stdbool.h>

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int curr = 1,
        min = (boardSize*2)+1,
        temp_min,
        queueSize = 1,
        next, next_end,
        r = 0,c = 0, i;

    int* queue = NULL;
    bool reached = false;

    queue = (int *) malloc(queueSize);
    queue[0] = board[r][c];

    while(queueSize != 0){
        next = curr+1;
        next_end = (curr+6 < boardSize*2)? curr+6 : boardSize*2;
        while(r < boardSize && r >= 0 && next != next_end+1)
        {
            while(c < boardColSize[r] && c>=0 && next != next_end+1)
            {
                if(board[r][c] != -1 || next == next_end)
                {
                    queue = (int *) malloc(queueSize);
                    queue[queueSize-1] = board[r][c];
                    ++queueSize;
                }
                c = (r%2==0 && c < boardColSize[r] && c>=0)? c+1 : c-1;
            }
            ++r;
        }

        for(i = 0; i<queueSize; ++i)
        {
            temp_min = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    char grid[][3] = {{'1', '1', '1'},
                      {'0', '1', '0'},
                      {'1', '1', '1'}};
    // [["1","1","1","1","1","0","1","1","1","1"],
    //  ["1","0","1","0","1","1","1","1","1","1"],
    //  ["0","1","1","1","0","1","1","1","1","1"],
    //  ["1","1","0","1","1","0","0","0","0","1"],
    //  ["1","0","1","0","1","0","0","1","0","1"],
    //  ["1","0","0","1","1","1","0","1","0","0"],
    //  ["0","0","1","0","0","1","1","1","1","0"],
    //  ["1","0","1","1","1","0","0","1","1","1"],
    //  ["1","1","1","1","1","1","1","1","0","1"],
    //  ["1","0","1","1","1","1","1","1","1","0"]]
    int gridColSize[] = {5, 5, 5, 5};
    printf("%d\n", numIslands((char**)grid, 4, gridColSize));

    return 0;
}
