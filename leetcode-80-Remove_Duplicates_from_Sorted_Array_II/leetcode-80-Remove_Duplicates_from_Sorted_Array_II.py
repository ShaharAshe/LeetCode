class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        start_i: int = 0
        end_i: int = 0
        last_i: int = 0
        while end_i < len(nums):
            while end_i < len(nums) and nums[end_i] == nums[last_i]:
                end_i += 1
            if (start_i+1) < len(nums) and (start_i+1) < end_i:
                nums[last_i+1] = nums[last_i]
                last_i += 1
            if end_i < len(nums):
                last_i += 1
                nums[last_i], nums[end_i] = nums[end_i], nums[last_i]
                start_i = end_i
                end_i += 1
        return last_i+1


if __name__ == "__main__":
    # nums: list[int] = [1,1,1,2,2,3]
    # nums: list[int] = [0,0,1,1,1,1,2,3,3]
    nums: list[int] = [1,1,1,2,2,3]
    result = Solution().removeDuplicates(nums)
    print(result)
