class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        i = 0
        j = 1
        max_l = 1
        letters:dict = {s[i]:True}
        res:int = 0
        while j<len(s):
            if s[j] in letters:
                while s[i] != s[j]:
                    del letters[s[i]]
                    i+=1
                i+=1
            else:
                letters[s[j]] = True
            max_l = max(max_l, ((j-i)+1))
            j+=1
        return max_l
    

if __name__ == "__main__":
    s:str = "abcabcbb"
    res: str = Solution().lengthOfLongestSubstring(s)

    print(res)
