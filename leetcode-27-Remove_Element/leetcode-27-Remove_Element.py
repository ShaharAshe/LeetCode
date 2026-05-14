class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        i: int = 0
        i_right: int = len(nums)
        while i < i_right:
            if nums[i] == val:
                nums[i], nums[i_right - 1] = nums[i_right - 1], nums[i]
                i_right -= 1
            else:
                i += 1
        return i_right


if __name__ == "__main__":
    nums: list[int] = [0,1,2,2,3,0,4,2]
    val: int = 2
    result = Solution().removeElement(nums, val)
    print(result)
