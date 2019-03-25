/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (59.47%)
 * Total Accepted:    11.6K
 * Total Submissions: 19.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<queue>
using namespace std;

// struct TreeNode {
//        int val;
//        TreeNode *left;
//        TreeNode *right;
//        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 
// };


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    
    vector<vector<int>> res;
    if(root==NULL) return res;

    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        vector<int> level;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode*now=q.front();
            q.pop();
            level.push_back(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);

        }
        res.insert(res.begin(),level);

    }
    return res;
    }
};

