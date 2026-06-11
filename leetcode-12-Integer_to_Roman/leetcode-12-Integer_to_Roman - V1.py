class Solution:
    def intToRoman(self, num: int) -> str:
        roman_vals = {
            1:'I',
            5:'V',
            4:'IV',
            9:'IX',
            10:'X',
            40:'XL',
            50:'L',
            90:'XC',
            100:'C',
            400:'CD',
            500:'D',
            900:'CM',
            1000:'M'
        }
        num_lst: list = [int(c) for c in str(num)]
        res: str = ''
        
        for i in range(len(num_lst)):
            power_val = ((10**(len(num_lst)-(i+1))))
            cur_val = num_lst[i]*power_val
            
            if cur_val in roman_vals.keys():
                res += roman_vals[cur_val]
                num_lst[i] -= 0
            else:
                while num_lst[i] != 0:
                    if 5*power_val<cur_val:
                        num_lst[i] -= 5
                        res += roman_vals[5*power_val]
                    else:
                        num_lst[i] -= 1
                        res += roman_vals[power_val]
                    cur_val = num_lst[i]*power_val
        return res


if __name__ == "__main__":
    num: int = 3749
    # num: int = 1111
    res: str = Solution().intToRoman(num)

    print(res)
