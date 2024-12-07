class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        if len(nums) == 1:
            return nums[0]
        i_range: int = 0
        i_start: int = 0
        i_pivot: int = len(nums)-1
        i_place: int = len(nums)-k
        p = nums[i_pivot]
        
        while i_range < i_pivot:
            if nums[i_pivot] != p or (i_start == 0 and i_pivot == len(nums)-1):
                for i in range(i_start, i_pivot):
                    if nums[i]<=nums[i_pivot]:
                        nums[i_range], nums[i] = nums[i], nums[i_range]
                        i_range+=1

                p = nums[i_pivot]
                nums[i_range], nums[i_pivot] = nums[i_pivot], nums[i_range]
            else:
                i_range = i_pivot
        
            if i_place<i_range:
                i_pivot = (i_range-1)
                i_range = i_start
            elif i_range == i_place:
                return nums[i_place]
            else:
                i_range += 1
                i_start = i_range

        return nums[i_place]


if __name__ == "__main__":
    nums: list = [3,2,1,5,6,4]
    k: int = 2
    
    res: int = Solution().findKthLargest(nums, k)

    print(res)
