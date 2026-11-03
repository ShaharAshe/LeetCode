class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        seen: set[int] = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False


if __name__ == "__main__":
    nums: list[int] = [1, 2, 3, 3]

    result = Solution().hasDuplicate(nums)
    print(result)
