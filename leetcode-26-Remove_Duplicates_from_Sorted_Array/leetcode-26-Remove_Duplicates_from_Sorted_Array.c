#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int num_of_dup = numsSize;

    for (int i = 0; i<num_of_dup; ++i){
        int dup = 0;
        for(int j = i+1; j<num_of_dup; ++j){
            if(nums[j] == nums[i] || dup){
                if(!dup){
                    dup = 1;
                }
                nums[j-1] = nums[j];
            }
        }
        if(dup){
            --i;
            --num_of_dup;
        }
    }
    return num_of_dup;
}

int main(){
    // [0,0,1,1,1,2,2,3,3,4]
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = 10;

    int uniqe_values = removeDuplicates(nums, numsSize);

    printf("%d\n",uniqe_values);

    return EXIT_SUCCESS;
}