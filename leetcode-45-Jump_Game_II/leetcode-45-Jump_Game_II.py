class Solution:
    def jump(self, nums: list[int]) -> int:
        result: int = 0
        i: int = 0
        max_i: int = nums[i]
        while 1 < len(nums) and i < len(nums):
            max_len: int = 0
            result += 1
            while i < len(nums) and i <= max_i:
                max_len = max((i+nums[i]), max_len)
                i+=1
            max_i = max_len
        return result


if __name__ == "__main__":
    nums: list[int] = [2,3,1,1,4]
    result = Solution().jump(nums)
    print(result)
