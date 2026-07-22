class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j:int = -1
        for i in range(len(s)):
            for j in range(j+1, len(t)):
                if t[j] == s[i]:
                    break
            else:
                return False
        return True


if __name__ == "__main__":
    s:str = "abc"
    t:str = "ahbgdc"

    res:bool = Solution().isSubsequence(s, t)

    print(res)