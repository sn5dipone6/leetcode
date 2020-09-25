/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

char *longestPalindrome(char *s)//用了马拉车算法
{
    int min(int a, int b)
{
    return a < b ? a : b;
}//the function is to chose the smaller one.
int i;//记录每个字符的位置。
    char t[10000];//存储处理后的字符串
    t[0] = '$';
    t[1] = '#';
    for (i = 2; s[i / 2 - 1] != '\0'; i++)
    {
        if (i % 2 == 0)
            t[i] = s[(i / 2) - 1];
        if (i % 2 == 1)
            t[i] = '#';
    }
    t[i] = '\0';//讲原来的字符串中间插入'#',开头加一个'$',末尾是'\0',是的字符串永远是奇数个，
                //就不需要分类讨论，奇偶个数下，回文字符串的区别。
    int id = 0, mx = 0, maxlength = 0, p[10000], head;
    //id为右端最远的回文字符串的中心
    //mx为id为中心的字符串的临界值+1，即在以id为中心的回文字符串以外。
    //maxlength记录最长半径。
    //p[]记录字符串每个位置的半径。
    //head记录最长半径的头，即最长回文子串的起始位置。
    for (i = 1; t[i] != '\0'; i++)//遍历字符串，顺便计算并得到最大半径。即只需遍历一遍即可找到答案。
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//马拉车的核心，使得每次判定半径不一定要从1开始。
        while (t[i - p[i]] == t[i + p[i]])
            ++p[i];//判断回文，则半径增加。
        if (mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }//更新临界值，便意味着边界发生变化，id与mx同步变化。
        if (maxlength < p[i])
        {
            maxlength = p[i];
            head = (i - maxlength) / 2;
        }
        //更新最大半径字符，更新起始位置。
    }
    char a[10000];//保存最长回文子串。
    int j;//遍历最长回文子串的循环变量。
    for (j = 0; j < maxlength - 1; j++)
    {
        *(a + j) = *(s + head + j);
        i++;
    }//讲最长子串，从s中复制到a中。
    a[maxlength-1] = '\0';//a在声明时，会随机给值，要在末尾加上结束符号。
    char *c = a;//指针传递。
    return c;//返回指针。不知道为什么返回数组首地址不可以。
}
// @lc code=end
