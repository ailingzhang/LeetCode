/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (56.36%)
 * Total Accepted:    3.7K
 * Total Submissions: 6.5K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;//return 0注意返回类型
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            if(q.back()) res.push_back(q.back()->val);
            //res.push_back(q.back()->val);
            //TreeNode*now=q.front();
            //q.pop();
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*now=q.front();
                q.pop();//循环弹出一层
                if(now->left) q.push(now->left);
                if(now->right) q.push(now->right);
            }
            
        }
        return res;
        
    }
};

