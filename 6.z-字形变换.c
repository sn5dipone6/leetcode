/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
//本人采用找规律的方法。
char *convert(char *s, int numRows)
{
int length = strlen(s);//获得字符串长度，避免检索数组越界
    int circle = 2 * numRows - 2;//循环周期
    char t[10000];//存放变换后数组
    int i, row, j = 0;//i存储周期数，row存储行数，j存储存放时的顺序。 遍历一次，同时获取答案。
    if(circle<=0)
        return s;//说明数组太短，直接输出即可。
    for (row = 0; row < numRows; row++)//因为最后时逐行读取，故行遍历优先。
    {
        for (i = 0;; i++)//不知道周期总数，不需要中止条件，在下面判断，不超出数组长度即可。
        {
            if (row == 0 || row == numRows - 1)//只有第一行和最后一行，在每个周期内读取一次。
            {
                if ((i * circle + row < length))//越界就跳出，否则读取。
                    t[j++] = *(s + i * circle + row);
                else
                    break;
            }
            else//每个周期内读取两次，即是中间的行数。
            {
                if ((i * circle + row < length))//读取的第一次。
                    t[j++] = *(s + i * circle + row  );
                else
                    break;
                if ((2 * (i*circle+numRows-1) - (i * circle + row) < length))//读取的第二次。
                    t[j++] = *(s + 2 * (i*circle+numRows-1) - (i * circle + row));
                else
                    break;
            }//每个读取部分的代码其实都很相似，感觉还可以更简洁。暂时不做优化。如果有人看到，可以一起思考一下哦。
        }
    }
    t[j] = '\0';//末尾加上结束符
    char *a = t;
    return a;;
}

// @lc code=end
