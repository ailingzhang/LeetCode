/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (46.65%)
 * Total Accepted:    12.8K
 * Total Submissions: 27.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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
#include <algorithm>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int left_hight = treeHeight(root->left);
        int right_hight = treeHeight(root->right);
        if (std::abs(left_hight-right_hight) <= 1) {
            return (isBalanced(root->left) && isBalanced(root->right));
        }
        else {
            return false;
        }
    }

    int treeHeight(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left_hight = treeHeight(root->left);
        int right_hight = treeHeight(root->right);
        return std::max(left_hight, right_hight) + 1;
    }

};

