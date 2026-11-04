class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_letters = {}
        for c in s:
            if c in s_letters:
                s_letters[c]+=1
            else:
                s_letters[c] = 1
        for c in t:
            if c in s_letters and 0<s_letters[c]:
                s_letters[c]-=1
            else:
                return False
        return True


if __name__ == "__main__":
    s: str = "anagram"
    t: str = "nagaram"

    res: bool = Solution().isAnagram(s, t)

    print(res)
