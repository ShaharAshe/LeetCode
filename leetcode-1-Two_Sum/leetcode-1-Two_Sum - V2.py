class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen: dict[int, int] = {}
        for i, val in enumerate(nums):
            complement: int = target - val
            if complement in seen:
                return [seen[complement], i]
            seen[val] = i
        return []


if __name__ == "__main__":
    nums: list = [2,7,11,15]
    target: int = 9

    result = Solution().twoSum(nums, target)
    print(result)
