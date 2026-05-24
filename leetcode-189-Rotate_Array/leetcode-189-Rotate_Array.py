class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last_i: int = 0
        i: int = k%len(nums)
        last_value: int = nums[0]
        count_cycle: int = 0
        while count_cycle < len(nums):
            while i != last_i:
                last_value, nums[i] = nums[i], last_value
                i = (i+k)%len(nums)
                count_cycle += 1
            else:
                nums[i] = last_value
                count_cycle += 1
                last_i = (last_i+1)%len(nums)
                i = (last_i+k)%len(nums)
                last_value = nums[last_i]


if __name__ == "__main__":
    nums: list[int] = [1,2,3,4,5,6,7]
    k: int = 3
    result = Solution().rotate(nums, k)
    print(nums)