class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        max_val:int = max(nums)
        min_val:int = min(nums)
        abs_min_val:int = abs(min_val)

        count_arr:list = [0]*((max_val+abs(min_val))+1)
        for x in nums:
            count_arr[x+abs_min_val]+=1
        e:int = 0
        for i in range(len(count_arr)):
            while count_arr[i] != 0:
                nums[e] = i-abs_min_val
                e+=1
                count_arr[i]-=1
        
        res:list = []
        for i in range(len(nums)):
            if (nums[i]+(max_val*2))<0 or (0<i and nums[i] == nums[i-1]):
                continue
            j:int = (i+1)
            k:int = (len(nums)-1)
            while j<k:
                if (nums[i]+nums[j]+nums[k])<0:
                    j+=1
                    while j<k and nums[j] == nums[j-1]:
                        j+=1
                elif 0<(nums[i]+nums[j]+nums[k]):
                    k-=1
                    while j<k and nums[k] == nums[k+1]:
                        k-=1
                else:
                    res.append([nums[i],nums[j],nums[k]])
                    j+=1
                    while j<k and nums[j] == nums[j-1]:
                        j+=1
                    k-=1
                    while j<k and nums[k] == nums[k+1]:
                        k-=1
        return res


if __name__ == "__main__":
    nums:list = [-1,0,1,2,-1,-4]
    res: str = Solution().threeSum(nums)

    print(res)
