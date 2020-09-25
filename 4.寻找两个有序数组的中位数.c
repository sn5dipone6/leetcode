/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
int midvalues, total, num1 = 0, num2 = 0, flag;
double first, second;//利用 first 和second 来记录。总数是奇数的话，两者取相等。偶数则取两位。
total = nums1Size + nums2Size;//计算总数。
midvalues = (total+1)/2;//计算最中间是第几个，或者两个时， 算出第一个。
while(midvalues)//当midvalues为0时，就得到了最靠近中间的数字。
{
    if(num1 == nums1Size)//有数据的是0 到 nums1Size-1 ，但是数量是nums1Size个。只有指针跳过去的数字才算被读取了。
    {
        num2++;
        flag = 2;//flag来记录上一次的取值是在哪个数组中的。
        midvalues--;//本来放在while语句末尾的，因为continue的存在，需要加上一句。
        continue;
    }
    if(num2 == nums2Size)//与上同理。
    {
        num1++;
        flag = 1;
        midvalues--;
        continue;
    }
    if(*(nums1 + num1) < *(nums2 + num2))//记录较小的数字，因为是有序数组，本身已经排序。
    {
        num1++;flag = 1;
    }
    else
    {
        num2++;flag = 2;
    }
midvalues--;
}
if(flag == 1)//通过flag来寻找最后一次记录的数据
first = *(nums1 + num1 -1);
if(flag == 2)
first = *(nums2 + num2 -1);
if(total %2 ==0)//总数是偶数
{
    if((num1 < nums1Size) && (num2 < nums2Size))//在两个数组尚有余量时，找到下一个最小的数。
    {
        second = *(nums1 + num1)<*(nums2 + num2)?*(nums1 + num1):*(nums2 + num2);
    }
    if(num1 == nums1Size)//若有数组到了尽头，则下一个数字只能从另一个数组中读取。
    second = *(nums2 + num2);
    if(num2 == nums2Size)
    second = *(nums1 + num1);
}
else second = first;//总数是奇数。两者取值相等。
return (first + second)/2;//中位数取first 和 second 的平均值。
}

// @lc code=end

