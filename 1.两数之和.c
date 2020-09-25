/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i,j, *x;
for(i=0; i<numsSize - 1; i++) //没什么好说的  两次循环 检测和值是否相等
{
    for(j=i+1; j<numsSize; j++)
        if(nums[i] + nums[j] == target)
            {
                x = (int *)malloc(sizeof(int) * 2);
                x[0] = i;
                x[1] = j;
                *returnSize = 2;
                return x;
            }
}
return 0;
}


// @lc code=end

