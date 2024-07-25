#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int final_size = numsSize;
    for(int i = 0; i<final_size; ++i){
        if(nums[i] == val){
            for(int j = i+1; j<final_size; ++j)
            {
                nums[j-1] = nums[j];
            }
            --final_size;
            --i;
        }
    }
    return final_size;
}


int main() {
    // [0,1,2,2,3,0,4,2]
    int nums[] = {0,1,2,2,3,0,4,2},
        val = 2,
        final_size = removeElement(nums, 8, val);

    printf("%d\n", final_size);
    for(int i = 0; i<final_size; ++i){
        printf("%d ", nums[i]);
    }
    
    return EXIT_SUCCESS;
}