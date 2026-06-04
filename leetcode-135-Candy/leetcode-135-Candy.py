class Solution:
    def candy(self, ratings: list[int]) -> int:
        count_candy: list[int] = [1]*len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i-1] < ratings[i]:
                count_candy[i] = count_candy[i-1] + 1
        for i in range(len(ratings)-2, -1, -1):
            if ratings[i+1] < ratings[i]:
                count_candy[i] = max(count_candy[i], count_candy[i+1] + 1)
        return sum(count_candy)


if __name__ == "__main__":
    ratings: list[int] = [1,0,2]
    result = Solution().candy(ratings)
    print(result)
