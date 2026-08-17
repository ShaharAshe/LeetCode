class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_characters_counter: dict[str, int] = {}
        for c in t:
            if c not in t_characters_counter:
                t_characters_counter[c] = 0
            t_characters_counter[c] += 1
        
        min_window: str = ""
        min_len: float = float("inf")
        window_len: int = 0
        left: int = 0
        for right, value in enumerate(s):
            if value in t_characters_counter:
                t_characters_counter[value] -= 1
                if t_characters_counter[value] >= 0:
                    window_len += 1
            while left <= right and window_len == len(t):
                if min_len > right-left+1:
                    min_len = right-left+1
                    min_window = s[left:right+1:]
                if s[left] in t_characters_counter:
                    t_characters_counter[s[left]] += 1
                    if t_characters_counter[s[left]] > 0:
                        window_len -= 1
                left += 1
        return min_window


if __name__ == "__main__":
    s: str = "ADOBECODEBANC"
    t: str = "ABC"
    result = Solution().minWindow(s, t)
    print(result)
