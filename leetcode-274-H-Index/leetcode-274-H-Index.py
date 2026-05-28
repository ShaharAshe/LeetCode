class Solution:
    def hIndex(self, citations: list[int]) -> int:
        counters: list[int] = [0] * (max(citations, default=0)+1)
        for c in citations:
            counters[c] += 1
        result: int = 0
        last_val: int = 0
        for i in range((len(counters)-1), -1, -1):
            counters[i] += last_val
            last_val = counters[i]
            if i <= last_val:
                return i
        return result


if __name__ == "__main__":
    citations: list[int] = [3,0,6,1,5]
    result = Solution().hIndex(citations)
    print(result)
