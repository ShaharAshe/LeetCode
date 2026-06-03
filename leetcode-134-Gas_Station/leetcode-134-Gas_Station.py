class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        min_i: int = 0
        sum_values: int = 0
        min_sum: int = 10000
        for i in range(len(gas)):
            sum_values += (gas[i]-cost[i])
            if sum_values < min_sum:
                min_sum = sum_values
                min_i = i
        return -1 if sum_values < 0 else (min_i+1)%len(gas)
    

if __name__ == "__main__":
    gas: list[int] = [1,2,3,4,5]
    cost: list[int] = [3,4,5,1,2]
    result = Solution().canCompleteCircuit(gas, cost)
    print(result)
