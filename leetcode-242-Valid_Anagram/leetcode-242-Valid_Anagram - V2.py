class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        chars: dict[str, int] = {}
        for c in s:
            if c not in chars:
                chars[c] = 0
            chars[c] += 1
        for c in t:
            if c not in chars:
                return False
            chars[c] -= 1
            if chars[c] < 0:
                return False
        return True


if __name__ == "__main__":
    s: str = "anagram"
    t: str = "nagaram"

    res: bool = Solution().isAnagram(s, t)

    print(res)
