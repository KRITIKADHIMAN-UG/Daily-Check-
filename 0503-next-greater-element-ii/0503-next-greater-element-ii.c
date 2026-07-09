/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int *result = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for(int i =0;i<numsSize;i++)result[i] = -1;
    
    int*stack = malloc(sizeof(int)*(2*numsSize));
    int top = -1;

    for(int i = 0;i<2*numsSize; i++){
        int num = nums[i%numsSize];
        while(top >= 0 && nums[stack[top]] < num){
            result[stack[top]] = num;
            top--;
        }
        if(i<numsSize){
            stack[++top] = i;
        }
    }
    free(stack);
    return result;
    }