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
		secondV := target - firstV
		if secondV == firstV {
			if len(firstIndex) == 1 {
				continue
			} else {
				lenSlice := len(firstIndex) - 1
				if firstIndex[0] < firstIndex[lenSlice] {
					return []int{firstIndex[0], firstIndex[lenSlice]}
				} else {
					return []int{firstIndex[lenSlice], firstIndex[0]}
				}
			}
		}
		secondIndex, ok := numsMap[secondV]
		if ok {
			valFirst := firstIndex[0]
			valSecond := secondIndex[0]
			if valFirst < valSecond {
				return []int{valFirst, valSecond}
			} else {
				return []int{valSecond, valFirst}
			}
		}
	}
	return []int{}
}

func main() {
	nums := []int{5, 75, 25}
	target := 100
	result := twoSum(nums, target)
	fmt.Println(result)
}
