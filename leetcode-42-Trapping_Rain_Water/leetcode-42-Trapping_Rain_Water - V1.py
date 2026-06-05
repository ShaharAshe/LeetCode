class Solution:
    def trap(self, height: list[int]) -> int:
        left_i, right_i = 0, (len(height)-1)
        max_left :int = height[left_i]
        max_right :int = height[right_i]
        result :int = 0
        while left_i < right_i:
            if height[left_i] < height[right_i]:
                result += max(min(max_left, max_right)-height[left_i], 0)
                left_i += 1
                max_left = max(height[left_i], max_left)
            else:
                result += max(min(max_left, max_right)-height[right_i], 0)
                right_i -= 1
                max_right = max(height[right_i], max_right)
        return result


if __name__ == '__main__':
    height: list[int] = [0,1,0,2,1,0,1,3,2,1,2,1]
    result = Solution().trap(height)
    print(result)
