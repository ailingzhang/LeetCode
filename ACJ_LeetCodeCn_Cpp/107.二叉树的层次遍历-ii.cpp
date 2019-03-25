/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (59.46%)
 * Total Accepted:    11.8K
 * Total Submissions: 19.8K
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() != 0) {
            vector<int> this_level_ans;

            int this_level_node_cnt = q.size();
            for (int i = 0; i < this_level_node_cnt; i++)
            {
                TreeNode *pTemp = q.front();
                this_level_ans.push_back(pTemp->val);
                if (pTemp->left != nullptr)
                {
                    q.push(pTemp->left);
                }
                if (pTemp->right != nullptr)
                {
                    q.push(pTemp->right);
                }
                q.pop();
            }
            ans.insert(ans.begin(), this_level_ans);
        }

        return ans;
    }
};

// int main() {
//     Solution solution;

//     TreeNode* pn_3 = new TreeNode(3);
//     TreeNode* pn_9 = new TreeNode(9);
//     TreeNode* pn_20 = new TreeNode(20);
//     TreeNode* pn_15 = new TreeNode(15);
//     TreeNode* pn_7 = new TreeNode(7);
//     pn_3->left = pn_9;
//     pn_3->right = pn_20;
//     pn_20->left = pn_15;
//     pn_20->right = pn_7;

//     vector<vector<int> > ans = solution.levelOrderBottom(pn_3);

//     for (vector<vector<int> >::iterator it_i = ans.begin(); it_i != ans.end(); it_i++)
//     {
//         for (vector<int>::iterator it_j = (*it_i).begin(); it_j !=(*it_i).end();it_j++)
//         {
//             cout << *it_j << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }
