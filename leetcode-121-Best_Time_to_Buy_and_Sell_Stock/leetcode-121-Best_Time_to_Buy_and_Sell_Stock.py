class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_val:int = prices[0]
        result:int = 0
        for price in prices:
            min_val = min(price, min_val)
            result = max((price-min_val), result)
        return result


if __name__ == "__main__":
    prices: list[int] = [7,1,5,3,6,4]
    result = Solution().maxProfit(prices)
    print(result)
