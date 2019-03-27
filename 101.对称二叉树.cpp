/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.62%)
 * Total Accepted:    25.6K
 * Total Submissions: 56K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()&&!q2.empty()){
            TreeNode*now1=q1.front();
            TreeNode*now2=q2.front();
            //now1=q1.front();
            //now2=q2.front();
            q1.pop();
            q2.pop();//及时弹出now1，now2
            if((!now1&&now2)||(now1&&!now2)) return false;//
            if(now1){
                //q1.pop();
                //q2.pop();//及时弹出now1，now2
                if(now1->val!=now2->val) return false;
                //if(now1->left->val!=now2->right->val||now2->left->val!=now1->right->val) return false;

                q1.push(now1->left);
                q1.push(now1->right);
                q2.push(now2->right);
                q2.push(now2->left);
            }

        }
        return true;
    }
};

