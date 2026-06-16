class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        result: str = ""
        min_len: int = len(min(strs, key=len))
        for i in range(min_len):
            temp_char: str = ""
            for s in strs:
                if temp_char == "":
                    temp_char = s[i]
                elif temp_char != s[i]:
                    return result
            result += temp_char
        return result


if __name__ == "__main__":
    strs: list[str] = ["flower","flow","flight"]
    result = Solution().longestCommonPrefix(strs)
    print(result)
