class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i_s: int = 0
        i_t: int = 0
        while i_s < len(s):
            while i_t < len(t):
                if t[i_t] != s[i_s]:
                    i_t += 1
                else:
                    break
            else:
                return False
            i_t += 1
            i_s += 1
        return True


if __name__ == "__main__":
    s:str = "abc"
    t:str = "ahbgdc"

    result = Solution().isSubsequence(s, t)

    print(result)