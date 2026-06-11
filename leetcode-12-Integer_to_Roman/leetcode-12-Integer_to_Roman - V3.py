class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbol_list: list[tuple[int, str]] = [
            (1000, "M"),
            (900, "CM"), (500, "D"), (400, "CD"), (100, "C"),
            (90, "XC"), (50, "L"), (40, "XL"), (10, "X"),
            (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
        ]
        result: str = ""
        for value, symbol in value_symbol_list:
            while num >= value:
                result += symbol
                num -= value
        return result


if __name__ == "__main__":
    num: int = 3749
    result = Solution().intToRoman(num)
    print(result)
