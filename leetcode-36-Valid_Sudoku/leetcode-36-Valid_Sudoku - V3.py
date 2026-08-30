class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for i in range(9):
            values: dict[str, set[str]] = {"row": set(), "col": set(), "square": set()}
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in values["row"]:
                        return False
                    values["row"].add(board[i][j])
                if board[j][i] != '.':
                    if board[j][i] in values["col"]:
                        return False
                    values["col"].add(board[j][i])
                r: int = ((i // 3) * 3) + (j // 3)
                c: int = ((i % 3) * 3) + (j % 3)
                if board[r][c] != '.':
                    if board[r][c] in values["square"]:
                        return False
                    values["square"].add(board[r][c])
        return True


if __name__ == "__main__":
    board: list[list[str]] = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    result = Solution().isValidSudoku(board)
    print(result)
