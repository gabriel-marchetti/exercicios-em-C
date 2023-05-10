#include <stdio.h>
#include <stdlib.h>


int *twoSum(int* nums, int numSize, int target, int* returnSize)
{
    int *array = (int *)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numSize - 1; i++){
        for(int j = i + 1; j < numSize; j++){
            if( nums[i] + nums[j] == target ){
                array[0] = i; array[1] = j;
                *returnSize = 2;
                return(array);
            }
        }
    }
    *returnSize = 0;
    return(array);    
}


int main(void)
{
    int *nums, numsSize, target, *returnSize;
    
    FILE *file;
    file = fopen("exerc1.txt", "r");

    fscanf(file, "%d", &numsSize);
    nums = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        fscanf(file, "%d ", &nums[i]);
    }
    printf("target: ");
    scanf("%d", &target);
    for (int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    returnSize = twoSum(nums, numsSize, target, returnSize);

    printf("[%d, %d]\n", returnSize[0], returnSize[1]);
    free(returnSize);
    free(nums);
    return(0);
}