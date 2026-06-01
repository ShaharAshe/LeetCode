class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        result: list[int] = [1] * len(nums)
        last_val_start: int = 1
        last_val_end: int = 1
        for i_start, i_end in zip(range(len(nums)), range((len(nums)-1), -1, -1)):
            result[i_start] *= last_val_start
            result[i_end] *= last_val_end
            last_val_start *= nums[i_start]
            last_val_end *= nums[i_end]
        return result


if __name__ == "__main__":
    nums: list[int] = [1,2,3,4]
    result = Solution().productExceptSelf(nums)
    print(result)
