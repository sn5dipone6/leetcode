/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//就是链表逐个求和相加 向前进位  本例将所得结果都放入链表l1中，所以可能要对l1进行增长。比重新建立一个l3链表节约内存。
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode *node1, *node2, *tail;
node1 = l1;
node2 = l2; 
int s1,s2;//分别取出两个链表结点的值，在链表空了后 方便赋予0值
int from_low = 0;//低位向高位的进位值
while((node1 != NULL) || (node2 != NULL) || (from_low == 1))//至少一个不为空很好理解 ， 都空了之后若有进位值产生 要进行l1的增长操作
{
    if(node1 == NULL)
    {
        node1 = (struct ListNode*)malloc(sizeof(struct ListNode));//如上所述，对l1进行必要的增长，前提是低位有进位值
        s1 = 0;
        tail->next = node1;
        node1->next = NULL;
    }
    else
    {
        s1 = node1->val;//若将l1结点的值给s1，下面s2同理
    }
    if(node2 == NULL)
    {
        node2 = (struct ListNode*)malloc(sizeof(struct ListNode));//最后的结果都在l1上，所以l2没必要增长。
        s2 = 0;
        node2->next = NULL;
    }
    else
    {
        s2 = node2->val;
    }
    node1->val = s1 + s2 + from_low;
    from_low = node1->val / 10;//如此计算进位值 必用if else 的两次组合省力。
    node1->val %= 10;
    tail = node1;//尾指针持续向后移动，方便在需要增长时，可以直接操作
    node1 = node1->next;
    node2 = node2->next;
}
return l1;
}


// @lc code=end

