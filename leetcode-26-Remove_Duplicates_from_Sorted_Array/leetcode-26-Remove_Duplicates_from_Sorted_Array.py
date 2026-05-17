class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        last_i: int = 0
        i: int = 0
        while i < len(nums):
            while i < len(nums) and nums[last_i] == nums[i]:
                i += 1
            if i < len(nums):
                last_i += 1
                nums[last_i], nums[i] = nums[i], nums[last_i]
                i += 1
        return last_i+1


if __name__ == "__main__":
    nums: list[int] = [1,1,2]
    result = Solution().removeDuplicates(nums)
    print(result)
