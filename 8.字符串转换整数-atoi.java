/*
 * @lc app=leetcode.cn id=8 lang=java
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution{
public int myAtoi(String str) {
    str = str.trim();//移除字符串两侧的空白字符或其他预定义字符
    if (str.isEmpty())//判断字符是否为null,空。
        return 0;
    int sign = 1; int i = 0;//sign记录正负号，i数组下标。
    //处理正负号
    if (str.charAt(0) == '-' || str.charAt(0) == '+'){
        sign = (str.charAt(0) == '-')? -1 : 1;
        //
        if (str.length() < 2 || !Character.isDigit(str.charAt(1))) {//字符串只有一个字符，且第一个不是数字
            return 0;
        }
        i++;
    }
    int n = 0;//记录最终答案
    while (i < str.length()) {
    	if (Character.isDigit(str.charAt(i))) {
            int d = str.charAt(i) - '0';//巧妙化字符为数字
            if (n > (Integer.MAX_VALUE - d) / 10) { //判断是否越界
                n = (sign == -1)? Integer.MIN_VALUE : Integer.MAX_VALUE;
                return n;
            }
            n = n*10 + d;
    	} else {
            break;
        }
        i++;
    }
    return sign * n;
}
}
// @lc code=end
