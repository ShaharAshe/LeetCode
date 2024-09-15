class Solution:
    def romanToInt(self, s: str) -> int:
        roman_vals = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
            }
        s_len = len(s)
        res: int = roman_vals[s[s_len-1]]
        for i in range(s_len-2,-1,-1):
            if roman_vals[s[i+1]]>roman_vals[s[i]]:
                res -= roman_vals[s[i]]
            else:
                res += roman_vals[s[i]]
        return res


if __name__ == "__main__":
    s: str = "III"
    res: int = Solution().romanToInt(s)
    
    print(res)
