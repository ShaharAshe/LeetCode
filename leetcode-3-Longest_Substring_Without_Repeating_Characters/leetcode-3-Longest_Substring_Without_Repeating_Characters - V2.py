class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left: int = 0
        max_len: int = 0
        characters_window: set[str] = set()
        for right in range(len(s)):
            while s[right] in characters_window:
                characters_window.remove(s[left])
                left += 1
            characters_window.add(s[right])
            max_len = max(right-left+1, max_len)
        return max_len


if __name__ == "__main__":
    s:str = "abcabcbb"
    result = Solution().lengthOfLongestSubstring(s)
    print(result)
