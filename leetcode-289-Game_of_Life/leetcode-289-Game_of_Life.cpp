#include <iostream>
#include <cstdlib>
#include <vector>


class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int rows_size = board.size(),
            cols_size = board[0].size();

        for(size_t r = 0; r<rows_size; ++r)
        {
            for(size_t c = 0; c<cols_size; ++c)
            {
                int count_neighbors = 0;
                if(r)
                {
                    if(board[r-1][c]==1 || board[r-1][c]==2)
                    {
                        ++count_neighbors;
                    }
                    if(c)
                    {
                        if(board[r-1][c-1]==1 || board[r-1][c-1]==2)
                        {
                            ++count_neighbors;
                        }
                    }
                    if(c!=(cols_size-1))
                    {
                        if(board[r-1][c+1]==1 || board[r-1][c+1]==2)
                        {
                            ++count_neighbors;
                        }
                    }
                }
                // ------------
                if(r!=(rows_size-1))
                {
                    if(board[r+1][c]==1 || board[r+1][c]==2)
                    {
                        ++count_neighbors;
                    }
                    if(c)
                    {
                        if(board[r+1][c-1]==1 || board[r+1][c-1]==2)
                        {
                            ++count_neighbors;
                        }
                    }
                    if(c!=(cols_size-1))
                    {
                        if(board[r+1][c+1]==1 || board[r+1][c+1]==2)
                        {
                            ++count_neighbors;
                        }
                    }
                }
                // -------
                if(c)
                {
                    if(board[r][c-1]==1 || board[r][c-1]==2)
                    {
                        ++count_neighbors;
                    }
                }
                // -------
                if(c!=(cols_size-1))
                {
                    if(board[r][c+1]==1 || board[r][c+1]==2)
                    {
                        ++count_neighbors;
                    }
                }

                if(board[r][c]) {
                    if(count_neighbors<2 || 3<count_neighbors)
                    {
                        board[r][c] = 2;
                    }
                } else {
                    if(count_neighbors == 3)
                    {
                        board[r][c] = 3;
                    }
                }
            }
        }

        for(size_t r = 0; r<rows_size; ++r)
        {
            for(size_t c = 0; c<cols_size; ++c)
            {
                if(board[r][c]==2)
                {
                    board[r][c] = 0;
                } else if(board[r][c]==3) {
                    board[r][c] = 1;
                }
            }
        }
    }
};


int main(){
    std::vector<std::vector<int>> matrix = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution().gameOfLife(matrix);
    
    std::cout << "[" << std::endl;
    for(size_t r = 0; r<matrix.size(); ++r)
    {
        std::cout << "[" ;
        for(size_t c = 0; c<matrix[r].size(); ++c)
        {
            std::cout << matrix[r][c];
            if(c!=(matrix[r].size()-1))
            {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}