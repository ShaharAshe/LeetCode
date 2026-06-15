class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        i: int = len(s) - 1
        while i >= 0 and s[i] != ' ': i -= 1

        return (len(s)-1) - i


if __name__ == "__main__":
    s: str = "Hello World"
    result = Solution().lengthOfLastWord(s)
    print(result)
