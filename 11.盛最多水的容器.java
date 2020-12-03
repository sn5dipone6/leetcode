/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
//Your runtime beats 67.75 % of java submissions
//Your memory usage beats 41.21 % of java

//从最两端开始往回缩减，高度较小的移动，直到重合。这题比较简单，不多注释。
class Solution {
    public int maxArea(int[] height) {
        int left,right;
        left = 0;
        right = height.length-1;
        int contian=right*Math.min(height[left],height[right]);
        while(left < right){
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
            right--;
            }
            contian = Math.max(contian,Math.min(height[left],height[right])*(right-left));
    }
    return contian;
}
}
// @lc code=end

