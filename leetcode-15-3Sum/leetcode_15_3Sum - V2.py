class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        result: list[list[int]] = []
        nums.sort()
        for i, value in enumerate(nums):
            if value > 0:
                break
            if i > 0 and nums[i-1] == nums[i]:
                continue
            left: int = i+1
            right: int = len(nums)-1
            while left < right:
                curr_sum: int = value + nums[left] + nums[right]
                if curr_sum == 0:
                    result.append([value, nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
                elif curr_sum < 0:
                    left += 1
                else:
                    right -= 1
        return result


if __name__ == "__main__":
    nums: list[int] = [-1,0,1,2,-1,-4]
    result = Solution().threeSum(nums)
    print(result)
