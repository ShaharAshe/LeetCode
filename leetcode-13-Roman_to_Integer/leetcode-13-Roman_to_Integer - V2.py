class Solution:
    def romanToInt(self, s: str) -> int:
        roman_integer_map: dict[str, int] = {
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000,
        }

        result: int = roman_integer_map[s[len(s)-1]]
        for i in range(len(s)-2, -1, -1):
            if roman_integer_map[s[i]] < roman_integer_map[s[i+1]]:
                result -= roman_integer_map[s[i]]
            else:
                result += roman_integer_map[s[i]]
        return result


if __name__ == "__main__":
    s: str = "III"
    result = Solution().romanToInt(s)
    print(result)
