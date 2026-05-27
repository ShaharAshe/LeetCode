class Solution:
    def canJump(self, nums: list[int]) -> bool:
        i: int = 0
        max_i: int = nums[i]
        while i < len(nums):
            while i < len(nums) and i <= max_i:
                max_i = max(max_i, (i+nums[i]))
                if len(nums)-1 <= max_i: return True
                i += 1
            i += 1
        return False


if __name__ == "__main__":
    nums: list[int] = [2,3,1,1,4]
    result = Solution().canJump(nums)
    print(result)
