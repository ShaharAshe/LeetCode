class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left: int = 0
        max_len: int = 0
        characters_window: dict[str, int] = {}
        for right in range(len(s)):
            if s[right] in characters_window:
                left = max(characters_window[s[right]]+1, left)
            characters_window[s[right]] = right
            max_len = max(right-left+1, max_len)
        return max_len


if __name__ == "__main__":
    s:str = "abcabcbb"
    result = Solution().lengthOfLongestSubstring(s)
    print(result)
