/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (56.45%)
 * Total Accepted:    3.7K
 * Total Submissions: 6.6K
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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
  public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root== nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){

            int most_right_val = 0;
            int level_node_cnt = q.size();
            for(int i = 0; i < level_node_cnt; i++)
            {
                TreeNode *temp_node = q.front();
                q.pop();
                most_right_val = temp_node->val;
                if (temp_node->left != nullptr){
                    q.push(temp_node->left);
                }
                if (temp_node->right != nullptr){
                    q.push(temp_node->right);
                }
            }
            ans.push_back(most_right_val);
        }
        return ans;
    }
};

