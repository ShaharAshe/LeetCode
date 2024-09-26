# class Solution:
#     def isValidSudoku(self, board: list[list[str]]) -> bool:
#         for r in range(len(board)):
#             appear:dict = {'r':{},'c':{},'b':{}}
#             for c in range(len(board[r])):
#                 if board[r][c] != '.':
#                     if board[r][c] in appear['r']:
#                         return False
#                     appear['r'][board[r][c]] = True

#                 if board[c][r] != '.':
#                     if board[c][r] in appear['c']:
#                         return False
#                     appear['c'][board[c][r]] = True
                
#                 m = ((r*3)+(c//3))%9
#                 s = (c%3)+((r//3)*3)
#                 if board[m][s] != '.':
#                     if board[m][s] in appear['b']:
#                         return False
#                     appear['b'][board[m][s]] = True
#         return True


class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for r in range(len(board)):
            appear_r:dict = {}
            appear_c:dict = {}
            appear_b:dict = {}
            help_calc_r = (r*3)
            help_calc_c = (r//3)*3
            for c in range(len(board[r])):
                if board[r][c] != '.':
                    if board[r][c] in appear_r:
                        return False
                    appear_r[board[r][c]] = True

                if board[c][r] != '.':
                    if board[c][r] in appear_c:
                        return False
                    appear_c[board[c][r]] = True
                
                b_r = (help_calc_r+(c//3))%9
                b_c = (c%3)+help_calc_c
                if board[b_r][b_c] != '.':
                    if board[b_r][b_c] in appear_b:
                        return False
                    appear_b[board[b_r][b_c]] = True
        return True


if __name__ == "__main__":
    # board:list = [["5","3",".",".","7",".",".",".","."],
    #          ["6",".",".","1","9","5",".",".","."],
    #          [".","9","8",".",".",".",".","6","."],
    #          ["8",".",".",".","6",".",".",".","3"],
    #          ["4",".",".","8",".","3",".",".","1"],
    #          ["7",".",".",".","2",".",".",".","6"],
    #          [".","6",".",".",".",".","2","8","."],
    #          [".",".",".","4","1","9",".",".","5"],
    #          [".",".",".",".","8",".",".","7","9"]]

    board:list = [[".",".",".",".",".",".","5",".","."],
             [".",".",".",".",".",".",".",".","."],
             [".",".",".",".",".",".",".",".","."],
             ["9","3",".",".","2",".","4",".","."],
             [".",".","7",".",".",".","3",".","."],
             [".",".",".",".",".",".",".",".","."],
             [".",".",".","3","4",".",".",".","."],
             [".",".",".",".",".","3",".",".","."],
             [".",".",".",".",".","5","2",".","."]]
    res: str = Solution().isValidSudoku(board)

    print(res)
