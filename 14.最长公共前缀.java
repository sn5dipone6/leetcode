/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start
//这题简单，双指针检索，不过费时费力。
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String temp = "" ,commonprefix;
        if(strs.length == 0)
        commonprefix = "" ;
        else commonprefix = strs[0];
        int i,j;
        for(i = 0;i<=strs.length-1;i++){

            if(commonprefix.length()<=strs[i].length()){
            for(j = 0;j<=commonprefix.length()-1;j++){
                if(commonprefix.charAt(j) == strs[i].charAt(j))
                temp+=commonprefix.charAt(j);
                else
                break;
                }
            }
            else{
                for(j = 0;j<=strs[i].length()-1;j++){
                    if(commonprefix.charAt(j) == strs[i].charAt(j))
                    temp += strs[i].charAt(j);
                    else break;
                }
            }
            commonprefix = temp;
            temp = "";
        }
        return commonprefix;
    }
    
}
// @lc code=end
/*
123/123 cases passed (18 ms)
Your runtime beats 5.49 % of java submissions
Your memory usage beats 5.04 % of java submissions (39.3 MB)
*/

//分享一个很妙的方法
/*
public static String longestCommonPrefix(String[] strs) {
        int count = strs.length;
        String prefix = "";
        if(count != 0){
            prefix = strs[0];
        }
        for(int i=0; i<count; i++){
            //关键代码，不断的从后往前截取字符串，然后与之相比，直到startsWith()返回true
            while(!strs[i].startsWith(prefix)){
                prefix = prefix.substring(0, prefix.length()-1);
            }
        }
        return prefix;
    }
*/

//以第一个字符为公共前缀，通过startsWith方法来比较，然后依次从后往前截取，知道找到为止。

