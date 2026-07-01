class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        pattern_lst: list[int] = [0] * len(needle)
        i_begin: int = 0
        for i in range(1, len(needle)):
            while needle[i_begin] != needle[i] and i_begin != 0:
                i_begin = pattern_lst[i_begin-1]
            else:
                if needle[i_begin] != needle[i]:
                    continue
            i_begin += 1
            pattern_lst[i] = i_begin
        
        i_haystack: int = 0
        i_needle: int = 0
        while i_needle < len(needle) and i_haystack < len(haystack):
            if needle[i_needle] == haystack[i_haystack]:
                i_haystack += 1
                i_needle += 1
            else:
                while needle[i_needle] != haystack[i_haystack] and i_needle != 0:
                    i_needle = pattern_lst[i_needle - 1]
                else:
                    if needle[i_needle] != haystack[i_haystack]:
                        i_haystack += 1
        if i_needle == len(needle):
            return i_haystack - len(needle)
        else:
            return -1


if __name__ == "__main__":
    haystack: str = "sadbutsad"
    needle: str = "sad"
    result = Solution().strStr(haystack, needle)
    print(result)
