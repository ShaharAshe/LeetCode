class Solution:
    def maxArea(self, heights: list[int]) -> int:
        left_i, right_i = 0, len(heights)-1
        max_area: int = 0
        while left_i < right_i:
            temp_area = right_i-left_i
            if heights[left_i] < heights[right_i]:
                temp_area *= heights[left_i]
                left_i += 1
            else:
                temp_area *= heights[right_i]
                right_i -= 1
            
            if max_area < temp_area:
                max_area = temp_area
        return max_area


if __name__ == "__main__":
    heights: list[int] = [1,8,6,2,5,4,8,3,7]

    result = Solution().maxArea(heights)
    print(result)
