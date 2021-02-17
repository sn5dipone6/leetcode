/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
//逐一取出字符，前后两者比较，若前者更大，就按一般输出，若后者更大，则说明是要减法，故乘上-1。
class Solution {
    private static int[] nums =      {1,5,10,50,100,500,1000};
    private static char[] romans = {'I','V','X','L','C','D','M'};//数字表，罗马字符表。
    public int romanToInt(String s) {
        char[] news = s.toCharArray();//字符串改为字符数组。
        char roman=' ',roman_after=' ';
        int i = 0,j = 0,result = 0,num = 0,num_after = 0;//初始化，after表示下一位。
        for(i = 0;i<=s.length()-1;i++){
            roman = news[i]; //取出一位
            if(i<s.length()-1){
            roman_after = news[i+1];}//取出下一位，添加了检测终点的条件。繁琐，可以更简化。
            for(j = 6;j >= 0;j--){ //将字符在罗马字符表中找到位置，并转化得到具体数字。
                {
                    if(romans[j] == roman)
                        num = nums[j];
                        if(i<s.length()-1){
                    if(romans[j] == roman_after)
                        num_after = nums[j];}
                }
            }
            if(i<s.length()-1){//前者比后者大，直接加，否则前一位要做减法。
            if(num>=num_after)
            {result+=num;}
            if(num<num_after)
            {result+= -1*num;}}
            else
            result+=num; //只剩最后一位了直接加上去。
        }
        return result;
    }
}
// @lc code=end
/*
3999/3999 cases passed (5 ms)
Your runtime beats 73.57 % of java submissions
Your memory usage beats 48.19 % of java submissions (38.7 MB)
*/
