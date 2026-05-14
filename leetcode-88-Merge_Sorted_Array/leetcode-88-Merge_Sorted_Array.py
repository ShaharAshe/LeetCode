class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i_num1: int = 0
        i_num2: int = 0
        while i_num1 < m and i_num2 < n:
            if nums2[i_num2] < nums1[i_num1]:
                nums1.insert(i_num1, nums2[i_num2])
                nums1.pop()
                i_num2 += 1
                i_num1 += 1
                m += 1
            else:
                i_num1 += 1
        while i_num2 < n:
            nums1.insert(i_num1, nums2[i_num2])
            nums1.pop()
            i_num1 += 1
            i_num2 += 1
            m += 1

        
if __name__ == "__main__":
    nums1: list[int] = [1,2,3,0,0,0]
    m: int = 3
    nums2: list[int] = [2,5,6]
    n: int = 3
    result = Solution().merge(nums1, m, nums2, n)