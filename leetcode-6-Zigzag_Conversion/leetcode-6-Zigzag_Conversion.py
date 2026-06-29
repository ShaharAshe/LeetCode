class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        result: str = ""
        for i_begin, i_end in zip(range(1, numRows+1), range(numRows, -1, -1)):
            down_jump: int = (numRows - i_begin) * 2
            up_jump: int = (numRows - i_end) * 2
            is_down: bool = True
            i: int = i_begin - 1
            while i < len(s):
                result += s[i]
                if is_down:
                    i += up_jump if down_jump == 0 else down_jump
                else:
                    i += down_jump if up_jump == 0 else up_jump        
                is_down = not is_down
        return result



if __name__ == "__main__":
    s: str = "PAYPALISHIRING"
    numRows: int = 3
    # s: str = "PAYPALISHIRING"
    # numRows: int = 4
    # s: str = "A"
    # numRows: int = 1
    result = Solution().convert(s, numRows)
    print(result)
