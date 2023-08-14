/* -- Id = 36 -- */

#include <iostream>
#include <vector>

using std::vector;
bool isValidSudoku(vector<vector<char>>& board, int r, int c){
    int i = 0;
    if(r == board.size()-1 && c == board[r].size()-1)
    {
        return true;
    }
    for (size_t row = 0; row < board.size(); ++row)
    {
        for (size_t col = 0; col < board[row].size(); ++col)
        {
            if(board[row][col] == '.')
            {
                if(i == 9)
                    return false;
                    
                board[row][col] = char(++i);
                bool re = isValidSudoku(board, row, col);
                board[row][col] = '.';
                return re;
            }
            else{
                bool re = isValidSudoku(board, row, col);
                return re;
            }
        }
    }
    return false;
}
 bool isValidSudoku(vector<vector<char>>& board) {
    return isValidSudoku(board, 0, 0);
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
