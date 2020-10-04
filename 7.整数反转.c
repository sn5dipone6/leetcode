/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start

int reverse(int x)
{
    int flag = 1, num[15], number,low =-pow(2,31),high = pow(2,31) -1 ;
    double result = 0;
    if (x > low && x < high && x != 0)
    {
        if (x < 0)
        {
            flag = -1;
        }
        int i, m;
        number = x * flag;
        for (i = 0; number > 0; i++)
        {
            num[i] = number % 10;
            number /= 10;
        }
        for (m = 0; m < i; m++)
        {
            result = result * 10 + num[m];
        }
        result *= flag;
        if (result < low|| result > high)
                return 0;
    }
    else
        return 0;
    return result;
}
// @lc code=end

//Your runtime beats 100% of c submissions.
// Your memory usage beats 49.85% of c submissions.
