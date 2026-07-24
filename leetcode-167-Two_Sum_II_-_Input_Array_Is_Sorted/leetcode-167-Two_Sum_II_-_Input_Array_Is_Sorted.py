class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        left: int = 0
        right: int = len(numbers) - 1
        while left < right:
            curr: int = numbers[left] + numbers[right]
            if curr == target:
                break
            elif curr < target:
                left += 1
            else:
                right -= 1
        return [left+1, right+1]


if __name__ == "__main__":
    numbers: list[int] = [2,7,11,15]
    target: int = 9
    result = Solution().twoSum(numbers, target)
    print(result)
