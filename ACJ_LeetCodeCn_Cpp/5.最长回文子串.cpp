/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (24.82%)
 * Total Accepted:    49.6K
 * Total Submissions: 199.7K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string longestPalindrome(string s) {
        if (s.empty()){
            return "";
        }
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), 0));

        for(int i = 0; i < s.size(); i++)
        {
            dp[i][0] = true;
            dp[i][1] = true;
        }
        string ans = s.substr(0,1);

        for (int j = 2; j <= s.size(); j++)
        {
            for(int i = 0; i < s.size(); i++)
            {
                if (i+j-1 < s.size() && s[i] == s[i+j-1] && dp[i+1][j-2]) {
                    dp[i][j] = true;
                    if (j> ans.length()){
                        ans = s.substr(i,j);
                    }
                }
            }
        }
        return ans;
    }
};

// int main() {
//     Solution solution;
//     cout << solution.longestPalindrome("babad") << endl;
//     cout << solution.longestPalindrome("abcba") << endl;
// }
