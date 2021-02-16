/*
 * @lc app=leetcode.cn id=12 lang=java
 *
 * [12] 整数转罗马数字
 */

// @lc code=start

//贪心算法，逐一配对
class Solution {
        private static int[] a = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; //数字表
        private static String[] str = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};//罗马符号表
    public String intToRoman(int num) {
        int nums = 12; //两表的标记
        int cnt = 0; //重复的数字
        String result  = "" ; //结果
        for(nums = 12;nums>=0;nums--){  //从大到小开始减少
            while(num - a[nums] >= 0){
                cnt++;                //计数加一
                num = num - a[nums]; //减去得出符号的数字
            }
            while(cnt>0)
            {
                result += str[nums]; //结果符号叠加
                cnt--;
            }
        }
        return result;
    }
    
}
// @lc code=end
// 3999/3999 cases passed (5 ms)
// Your runtime beats 92.13 % of java submissions
// Your memory usage beats 36.81 % of java submissions (38.3 MB)

