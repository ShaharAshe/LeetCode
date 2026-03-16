package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	numsMap := make(map[int][]int, len(nums))
	for i, v := range nums {
		numsMap[v] = append(numsMap[v], i)
	}
	for firstV, firstIndex := range numsMap {
		if secondV := target - firstV; secondV == firstV {
			if 1 == len(firstIndex) {
				continue
			}
			if lenSlice := len(firstIndex) - 1; firstIndex[0] < firstIndex[lenSlice] {
				return []int{firstIndex[0], firstIndex[lenSlice]}
			} else {
				return []int{firstIndex[lenSlice], firstIndex[0]}
			}
		} else if secondIndex, ok := numsMap[secondV]; ok {
			if firstIndex[0] < secondIndex[0] {
				return []int{firstIndex[0], secondIndex[0]}
			} else {
				return []int{secondIndex[0], firstIndex[0]}
			}
		}
	}
	return []int{}
}

func main() {
	nums := []int{3, 3}
	target := 6
	result := twoSum(nums, target)
	fmt.Println(result)
}
