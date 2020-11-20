/*
 * @lc app=leetcode.cn id=10 lang=java
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
//用了最典型的动态规划算法，网上很多讲解，就标注一些注意点。
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length()+1][p.length()+1];//java初始化布尔值为false.申请的数组比两个字符串长度都大1
        if (s == null || p == null)
            return false;
        dp[0][0] = true;//表示s前0个字符与p前0个字符匹配，也就是说还没开始比较。
        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) == '*' && dp[0][i - 1]) {
                dp[0][i + 1] = true;
            }
        }
        //
        for (int i = 0; i < s.length(); i++)
            for (int j = 0; j < p.length(); j++) {
                if (p.charAt(j) == '.' || p.charAt(j) == s.charAt(i))
                    dp[i + 1][j + 1] = dp[i][j];
                if (p.charAt(j) == '*') {
                    if (p.charAt(j - 1) != s.charAt(i) && p.charAt(j - 1) != '.') {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    } else {
                        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                    }//状态转移方程分类有很多种，此处将一样的结果合并了。
                }
            }
        return dp[s.length()][p.length()];
    }
}


// @lc code=end

