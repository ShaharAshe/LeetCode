class Solution:
    def minSteps(self, n: int) -> int:
        if(n == 1):
            return 0
        
        temp_n = n
        total_res = 0
        while(temp_n != 1):
            for x in range(2, (temp_n+1)):
                if(temp_n%x == 0):
                    while(temp_n%x == 0):
                        total_res += x
                        temp_n //= x
                    break
        return total_res


if __name__ == "__main__":
    sol = Solution()
    # res = sol.minSteps(3)
    # res = sol.minSteps(1)
    # res = sol.minSteps(6)
    res = sol.minSteps(16)


    print(res)
