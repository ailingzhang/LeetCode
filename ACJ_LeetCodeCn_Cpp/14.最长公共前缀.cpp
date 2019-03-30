/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.46%)
 * Total Accepted:    64.5K
 * Total Submissions: 198.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";

        if (strs.empty()){
            return ans;
        }


        for (int i = 0; i < strs[0].length(); i++)
        {
            char c = strs[0][i];
            bool stop = false;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j].size() <= i || c != strs[j][i])
                {
                    stop = true;
                }
            }
            if (stop) {
                break;
            }
            ans += c;
        }

        return ans;
    }
};

// int main() {
//     cout << "hello" << endl;
//     Solution solution;
//     vector<string> a;
//     a.push_back("");
//     cout << solution.longestCommonPrefix(a) << endl;
// }
