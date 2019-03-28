/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.66%)
 * Total Accepted:    25.8K
 * Total Submissions: 56.5K
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

#include<iostream>
#include<queue>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode *> left_queue;
        queue<TreeNode *> right_queue;

        left_queue.push(root->left);
        right_queue.push(root->right);

        while (!left_queue.empty()){
            TreeNode *node1 = left_queue.front();
            TreeNode *node2 = right_queue.front();

            left_queue.pop();
            right_queue.pop();

            if (node1 == nullptr && node2 == nullptr){
                continue;
            }
            if (node1 == nullptr || node2 == nullptr){
                return false;
            }else{
                if (node1->val != node2->val) {
                    return false;
                }
                left_queue.push(node1->left);
                right_queue.push(node2->right);
                left_queue.push(node1->right);
                right_queue.push(node2->left);      
            }
        }
        return true;
    }
};

// int main() {
//     Solution solution;
//     cout << "hello" << endl;
// }
