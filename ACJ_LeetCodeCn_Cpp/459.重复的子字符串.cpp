/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (39.20%)
 * Total Accepted:    4.5K
 * Total Submissions: 11.3K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abab"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 
 * 输出: False
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcabcabcabc"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
 * 
 * 
 */
#include <iostream>
using namespace std;

class Solution {
    public:
        bool repeatedSubstringPattern(string s)
        {
            if (s.empty())
            {
                return 0;
            }
            for (int i = 1; i <= s.length() / 2; i++)
            {
                if (repeatedSubstringCanBe(s.substr(0, i), s)) {
                    return true;
                }
            }
            
            return false;
        }
    private:
        bool repeatedSubstringCanBe(string s1, string s2)
        {
            if (s2.size() % s1.size() != 0)
            {
                return false;
            }
            for (int i = 0; i < s2.size() / s1.size(); i++)
            {
                string temp = s2.substr(i * s1.size(), s1.size());
                if (temp != s1)
                {
                    return false;
                }
            }
            return true;
        }
};

// int main() { 
//     cout << "hello world!" << endl;
//     Solution solution;
//     cout << solution.repeatedSubstringPattern("abab") << endl;
//     cout << solution.repeatedSubstringPattern("aba") << endl;
//     cout << solution.repeatedSubstringPattern("abcabcabcabc") << endl;

//     return 0;
// }
