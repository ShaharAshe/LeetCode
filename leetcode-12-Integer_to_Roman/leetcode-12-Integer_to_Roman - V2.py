class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbol_map: dict[int, str] = {
            1:"I",
            5:"V",
            10:"X",
            50:"L",
            100:"C",
            500:"D",
            1000:"M"
        }
        result: str = ""
        exponent: int = 0
        while num != 0:
            num_remain_start: int = (num % 10)
            num_remain: int = num_remain_start * (10 ** exponent)
            num //= 10
            coefficient_1: int = 1*(10**exponent)
            coefficient_5: int = 5*(10**exponent)
            if num_remain_start == 4:
                result = value_symbol_map[coefficient_1] + value_symbol_map[coefficient_5] + result
            elif num_remain_start == 9:
                result = value_symbol_map[coefficient_1] + value_symbol_map[1*(10**(exponent+1))] + result
            else:
                temp_result: str = ""
                while num_remain != 0:
                    if num_remain >= coefficient_5:
                        temp_result += value_symbol_map[coefficient_5]
                        num_remain -= coefficient_5
                    else:
                        temp_result += value_symbol_map[coefficient_1]
                        num_remain -= coefficient_1
                result = temp_result + result
            exponent += 1
        return result


if __name__ == "__main__":
    num: int = 3749
    result = Solution().intToRoman(num)
    print(result)
