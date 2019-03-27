/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.32%)
 * Total Accepted:    7K
 * Total Submissions: 12.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      if(root==NULL)  return res;
      treePath(root,res,to_string(root->val)) ;
      return res;
    }

    void treePath(TreeNode*root,vector<string>&str,string path){ //返回类型不同写成vector<string>，str加了引用
        if(root->left==NULL&&root->right==NULL){
            str.push_back(path);
            return;
        }
        if(root->left) treePath(root->left,str,path+"->"+to_string(root->left->val));
        if(root->right) treePath(root->right,str,path+"->"+to_string(root->right->val));
    }
};

