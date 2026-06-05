class Solution:
    def trap(self, height: list[int]) -> int:
        i_left: int = 0
        i_right: int = len(height)-1
        max_left: int = height[i_left]
        max_right: int = height[i_right]
        result: int = 0
        while i_left < i_right:
            if height[i_left] < height[i_right]:
                i_left += 1
                max_left = max(max_left, height[i_left])
                result += max(min(max_left, max_right)-height[i_left], 0)
            else:
                i_right -= 1
                max_right = max(max_right, height[i_right])
                result += max(min(max_left, max_right)-height[i_right], 0)
        return result


if __name__ == "__main__":
    # height: list[int] = [0,1,0,2,1,0,1,3,2,1,2,1]
    height: list[int] = [4,2,0,3,2,5]
    result = Solution().trap(height)
    print(result)
