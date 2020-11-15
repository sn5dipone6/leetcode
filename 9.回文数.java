/*
 * @lc app=leetcode.cn id=9 lang=java
 *
 * [9] 回文数
 */

// @lc code=start
//一般做法是，求出反向的数字，再比较
//这里，只反向了一半，比较前一半是否和后一半相同即可。
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0||(x != 0 && x%10 == 0)){
            return false;
        }
        int res = 0;
        while(res < x) {
            res = res * 10 + x % 10;
            x/=10;
        }
        if(res ==x || res/10 ==x)
        {
            return true;
        }
        return false;
    }
}
// @lc code=end

