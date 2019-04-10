/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (59.74%)
 * Total Accepted:    47.7K
 * Total Submissions: 79.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */
#include<iostream>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

/**
 * 方法一：递归
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * **/
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }
//         ListNode *new_head = nullptr;

//         if (head->next != nullptr)
//         {
//             new_head = reverseList(head->next);
//             head->next->next = head;
//             head->next = nullptr;
//             return new_head;
//         }else{
//             return head;
//         }
//     }
// };

/**
 * 方法二：迭代
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 * **/
class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
    
        ListNode * p1 = head;
        ListNode * p2 = p1->next;
        ListNode * p3 = p2->next;
        head->next = nullptr;

        while (p3 != nullptr){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};

// int main() {
//     auto p1 = new ListNode(1);
//     auto p2 = new ListNode(2);
//     auto p3 = new ListNode(3);
//     auto p4 = new ListNode(4);
//     auto p5 = new ListNode(5);
//     p1->next = p2;
//     p2->next = p3;
//     p3->next = p4;
//     p4->next = p5;
//     p5->next = nullptr;
//     Solution solution;
//     cout << "hello" << endl;
//     auto new_head = solution.reverseList(p1);
//     cout << new_head->val << endl;
//     cout << new_head->next->val << endl;
//     cout << new_head->next->next->val << endl;
// }
