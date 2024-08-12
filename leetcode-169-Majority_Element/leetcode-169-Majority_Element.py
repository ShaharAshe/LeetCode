def majorityElement(nums: list[int]) -> int:
        coount_apearance = {}
        n_2 = len(nums)//2
        for x in nums:
            if coount_apearance.get(x) == None:
                coount_apearance[x] = 0
            coount_apearance[x] += 1
            if coount_apearance[x] > n_2:
                return x
        return -1


if __name__ == "__main__":
    vec = [2,2,1,1,1,2,2]
    res = majorityElement(vec)
    print(res)
