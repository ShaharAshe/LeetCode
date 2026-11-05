class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        nums_dict: dict = {}

        for n in range(len(nums)):
            nums_dict[nums[n]] = n
        
        for n in range(len(nums)):
            rest: int = (target-nums[n])
            if rest in nums_dict and n!=nums_dict[rest]:
                return [n,nums_dict[rest]]
        return []


if __name__ == "__main__":
    nums: list = [2,7,11,15]
    target: int = 9

    res: list = Solution().twoSum(nums, target)

    print(res)
