class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for i in range(9):
            row_value: set[int] = set()
            col_value: set[int] = set()
            square_value: set[int] = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in row_value:
                        return False
                    row_value.add(board[i][j])
                if board[j][i] != '.':
                    if board[j][i] in col_value:
                        return False
                    col_value.add(board[j][i])
                r: int = ((i // 3) * 3) + (j // 3)
                c: int = ((i % 3) * 3) + (j % 3)
                if board[r][c] != '.':
                    if board[r][c] in square_value:
                        return False
                    square_value.add(board[r][c])
        return True


if __name__ == "__main__":
    board: list[list[str]] = [[".",".",".",".","5",".",".","1","."],[".","4",".","3",".",".",".",".","."],[".",".",".",".",".","3",".",".","1"],["8",".",".",".",".",".",".","2","."],[".",".","2",".","7",".",".",".","."],[".","1","5",".",".",".",".",".","."],[".",".",".",".",".","2",".",".","."],[".","2",".","9",".",".",".",".","."],[".",".","4",".",".",".",".",".","."]]
    result = Solution().isValidSudoku(board)
    print(result)
