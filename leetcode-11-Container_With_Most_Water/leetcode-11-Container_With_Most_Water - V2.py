class Solution:
    def maxArea(self, height: list[int]) -> int:
        left: int = 0
        right: int = len(height) - 1
        most_water: int = 0
        while left < right:
            curr_water = right-left
            if height[left] < height[right]:
                curr_water *= height[left]
                left += 1
            else:
                curr_water *= height[right]
                right -= 1
            most_water = max(curr_water, most_water)
        return most_water


if __name__ == "__main__":
    heights: list[int] = [1,8,6,2,5,4,8,3,7]
    result = Solution().maxArea(heights)
    print(result)
