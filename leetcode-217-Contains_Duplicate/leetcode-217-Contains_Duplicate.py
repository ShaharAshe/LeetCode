class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen: set[int] = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False


if __name__ == "__main__":
    nums: list[int] = [1,2,3,1]

    result = Solution().containsDuplicate(nums)
    print(result)
