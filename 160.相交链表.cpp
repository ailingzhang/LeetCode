/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 *
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (38.62%)
 * Total Accepted:    19.3K
 * Total Submissions: 50K
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
 *
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 
 * 如下面的两个链表：
 * 
 * 
 * 
 * 在节点 c1 开始相交。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2,
 * skipB = 3
 * 输出：Reference of the node with value = 8
 * 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为
 * [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
 * = 1
 * 输出：Reference of the node with value = 2
 * 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为
 * [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：null
 * 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为
 * 0，而 skipA 和 skipB 可以是任意值。
 * 解释：这两个链表不相交，因此返回 null。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* //首先遍历两个链表记录下它们的长度LenA和LenB，两者长度差为x。若存在交点， 则从最后一个结点
//到交点的位置两个链表的结点数一定是相同的，所以使较长的链表先向后移动x个位置（使长链表后面
//的长度与短链表相同），再开始对两个链表同时进行遍历，直到遍历到第一个相同结点时即为交点。

    //求出链表长度
    int getListLength(ListNode *head)
    {
        int len = 0;
        ListNode *tmp = head;
        while(tmp) tmp = tmp->next,len++;

        return len;
    }
    //判断交叉节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;

        int ab  = getListLength(a)-getListLength(b);

        if(ab > 0)
        {
            while(ab) a = a->next, ab--;
        }
        else if(ab < 0)
        {
            while(ab) b = b->next, ab++;
        }

        while(a && b)
        {
            if(a->val == b->val) return a;

            a = a->next;
            b = b->next;
        }

        return NULL;
    }
}; */

//[4,1,8,4,5] [5,0,1,8,4,5] 注释掉的代码返回1，为什么不对呢
class Solution {
public:
    ListNode*getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        ListNode* a = headA, *b = headB;
        while(a!=NULL){
            lena++;
            a = a->next;
        }
        while(b!=NULL){
            lenb++;
            b = b->next;
        }
        
        int c = lena>lenb ? lena-lenb : lenb-lena;
        
        if(lena>lenb){
            for(int i=0; i<c; i++){
                headA = headA->next;
            }
        }else{
            for(int i=0; i<c; i++){
                headB = headB->next;
            }
        }
        
        while(headB!=headA){
            headB = headB->next;
            headA = headA->next;
        }
        
        return headA;
    }
};


