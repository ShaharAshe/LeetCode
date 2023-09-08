/* -- Id = 36 -- */

#include <iostream>
#include <vector>

using std::vector;

bool isValidSudoku(vector<vector<char>>& board) {
    for (size_t row = 0; row < board.size(); ++row)
    {
        for (size_t col = 0; col < board[row].size(); ++col)
        {
            for (size_t i = 0; i < board[row].size(); ++i)
                if(board[row][col] == board[row][i])
                    return false;
            
            for (size_t i = 0; i < board.size(); ++i)
                if(board[row][col] == board[i][col])
                    return false;
            
            for (size_t i = row-(row%3), step_i = 0; step_i < 3 && i < board.size(); ++i, ++step_i)
            {
                for (size_t j = col-(col%3), step_j = 0; step_j < 3 j < board[row].size(); ++j, ++step_j)
                {
                    if(board[row][col] == board[i][j])
                        return false;
                }
            }
        }
    }
    return true;
}

bool is_in_row(int val, vector<vector<char>>& board)
{

}

int main(int argc, char const *argv[])
{
    vector<vector<char>> v = { {'5','3','.','.','7','.','.','.','.'},
                               {'6','.','.','1','9','5','.','.','.'},
                               {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'},
                               {'4','.','.','8','.','3','.','.','1'},
                               {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'},
                               {'.','.','.','4','1','9','.','.','5'},
                               {'.','.','.','.','8','.','.','7','9'} };
    
    std::cout << isValidSudoku(v) << std::endl;
    
    return 0;
}
