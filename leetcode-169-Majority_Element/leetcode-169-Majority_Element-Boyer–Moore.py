class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        curr: int = nums[0]
        count: int = 0
        for num in nums:
            if num == curr:
                count += 1
            else:
                count -= 1
                if count == 0:
                    curr = num
                    count += 1
        return curr


if __name__ == "__main__":
    nums: list[int] = [3,2,3]
    result = Solution().majorityElement(nums)
    print(result)
