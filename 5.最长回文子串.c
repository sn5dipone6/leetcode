/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

char *longestPalindrome(char *s)
{
    int min(int a, int b)
{
    return a < b ? a : b;
}//the function is to chose the smaller one.
int i;
    char t[10000];
    t[0] = '$';
    t[1] = '#';
    for (i = 2; s[i / 2 - 1] != '\0'; i++)
    {
        if (i % 2 == 0)
            t[i] = s[(i / 2) - 1];
        if (i % 2 == 1)
            t[i] = '#';
    }
    t[i] = '\0';
    int id = 0, mx = 0, maxlength = 0, p[10000], head;
    for (i = 1; t[i] != '\0'; i++)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i - p[i]] == t[i + p[i]])
            ++p[i];
        if (mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }
        if (maxlength < p[i])
        {
            maxlength = p[i];
            head = (i - maxlength) / 2;
        }
    }
    char a[10000];
    int j;
    for (j = 0; j < maxlength - 1; j++)
    {
        *(a + j) = *(s + head + j);
        i++;
    }
    a[maxlength-1] = '\0';
    char *c = a;
    return c;;
}
// @lc code=end
