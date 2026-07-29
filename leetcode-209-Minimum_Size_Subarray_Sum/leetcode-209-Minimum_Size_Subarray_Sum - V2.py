class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        min_len: int = len(nums)+1
        curr_sum: int = 0
        left: int = 0
        for right in range(len(nums)):
            curr_sum += nums[right]
            while curr_sum >= target:
                min_len = min(right-left+1, min_len)
                curr_sum -= nums[left]
                left += 1
        return 0 if min_len == (len(nums)+1) else min_len


if __name__ == "__main__":
    target: int = 7
    nums: list[int] = [2,3,1,2,4,3]
    result = Solution().minSubArrayLen(target, nums)
    print(result)
