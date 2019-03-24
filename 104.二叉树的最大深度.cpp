/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (67.79%)
 * Total Accepted:    35.7K
 * Total Submissions: 52.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
    int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    queue<TreeNode*>q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        count++;
        vector<int> level;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode*now=q.front();
            q.pop();
            level.push_back(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);

        }

    }
    return count;  
    }
};

