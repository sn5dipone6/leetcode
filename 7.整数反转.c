/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start

int reverse(int x)
{
    int flag = 1, num[15], number, low = -pow(2, 31), high = pow(2, 31) - 1;
    /*flag 记录正负数。 
     num用于存储分离出的每一位数字，其实11位就够了。边界就11位。
     number存储转化后的数字。负数化正，正数不变。
     low、high 上下界
    */
    double result = 0; //result 存储转化后结果，int类型会越界导致数据错误，暂时没想到有效方法。
    if (x > low && x < high && x != 0)//初始判断数据是否越界。
    {
        if (x < 0)
        {
            flag = -1;
        }                  //正负转化，记录。结果转化回去。
        int i, m;          //循坏变量，j用于分离时，m用于反向合成时。
        number = x * flag; //正负转化不用判断。
        for (i = 0; number > 0; i++)
        {
            num[i] = number % 10;
            number /= 10;
        } //各位数字 分离。
        for (m = 0; m < i; m++)
        {
            result = result * 10 + num[m];
        }//数据组成。
        result *= flag;//结尾正负转化回去。
        if (result < low || result > high)
            return 0; //越界 返回0;
    }
    else
        return 0;
    return result;
}
// @lc code=end

//Your runtime beats 100% of c submissions.
// Your memory usage beats 49.85% of c submissions.
