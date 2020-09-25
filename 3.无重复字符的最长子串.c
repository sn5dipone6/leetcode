/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
int max = 0, begin = 0, p = 0, i, flag;//指针p在原始字符串上逐个扫描 begin表示所需字符串的开始 max表示长度 
flag = *(s + p);               //flag用于记录是否遍历完原始字符串
while (flag != 0)
{
    for(i = begin;i<p;i++)//i是在所求字符串中逐个检查的指针
    {
        if((i != p)&&(*(s + i)==*(s + p)))//通过(i！=p)来排除只有一个字符串或者没有的情况
            {
                max = max > (p - begin) ? max : (p - begin);//取最大长度
                begin = i + 1;//begin只能逐个后移 不能直接跳跃到检查出的重复字段  如"dvdf"
            }
    }
    i = begin;//重置begin 记录新的目标字符串
    p++;
    flag = *(s + p);//重置flag
}
max = max > (p - begin) ? max : (p - begin);
/*
当初这一步死了很久
倘若没有这一句，只有进入if语句后，才会计算max
但if的条件是检测到字符串会重复
所以如果字符串不重复的话 就不会更新计算max 如 "asdfghjkl" ,就会导致max一直为0。
*/
return max;
}


// @lc code=end

