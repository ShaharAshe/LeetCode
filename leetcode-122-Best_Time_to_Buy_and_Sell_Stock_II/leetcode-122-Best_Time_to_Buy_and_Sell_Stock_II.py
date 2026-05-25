class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_val: int = prices[0]
        max_val:int = prices[0]
        result: int = 0
        for price in prices:
            if price < max_val:
                result += (max_val-min_val)
                min_val = price
                max_val = price
            else:
                max_val = price
        return result + (max_val-min_val)


if __name__ == "__main__":
    prices: list[int] = [7,1,5,3,6,4]
    result = Solution().maxProfit(prices)
    print(result)
