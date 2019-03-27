/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.44%)
 * Total Accepted:    7K
 * Total Submissions: 12.3K
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

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
  public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;

        if (root == nullptr)
        {
            return ans;
        }

        vector<int> my_stack;
        DFS(root, my_stack, ans);

        return ans;
    }

  private:
    void DFS(TreeNode *root, vector<int> &my_stack, vector<string> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        my_stack.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            string this_ans = std::to_string(my_stack.front());
            for (int i = 1; i < my_stack.size(); i++)
            {
                this_ans += "->" + std::to_string(my_stack[i]);
            }
            ans.push_back(this_ans);
        }
        else
        {
            DFS(root->left, my_stack, ans);
            DFS(root->right, my_stack, ans);
        }
        my_stack.pop_back();
        return;
    }
};

// int main()
// {
//     Solution solution;
//     cout << "hello!" << endl;
//     return 0;
// }
