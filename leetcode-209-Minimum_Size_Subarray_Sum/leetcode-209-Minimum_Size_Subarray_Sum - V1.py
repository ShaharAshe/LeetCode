class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        i:int = 0
        j:int = 0
        sum_val:int = 0
        min_len:int = -1

        while j<len(nums):
            sum_val+=nums[j]
            if target<=sum_val:
                while target<=(sum_val-nums[i]):
                    sum_val-=nums[i]
                    i+=1
                if min_len == -1:
                    min_len = ((j-i)+1)
                else:
                    min_len = min(min_len,((j-i)+1))
            j+=1
        
        return min_len if min_len!=-1 else 0


if __name__ == "__main__":
    target = 7
    nums = [2,3,1,2,4,3]
    res: str = Solution().minSubArrayLen(target, nums)

    print(res)
