class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i_s: int = 0
        for i_t in range(len(t)):
            if i_s < len(s) and s[i_s] == t[i_t]:
                i_s += 1
        return i_s == len(s)


if __name__ == "__main__":
    s:str = "abc"
    t:str = "ahbgdc"

    result = Solution().isSubsequence(s, t)

    print(result)