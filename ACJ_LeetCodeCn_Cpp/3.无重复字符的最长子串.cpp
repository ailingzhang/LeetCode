/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.74%)
 * Total Accepted:    100K
 * Total Submissions: 346.2K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


/**
 * 方法一：遍历开始位置i，结束位置j
 * 时间复杂度 O(n^2)
 **/
// class Solution
// {
//   public:
//     int lengthOfLongestSubstring(string s) {
//         if (s.empty()) {
//             return 0;
//         }
//         int ans = 0;
//         for(int i = 0; i < s.length(); i++)
//         {
//             set<char> my_set;
//             int temp_length = 0;
//             for (int j = i; j < s.length(); j++)
//             {
//                 if (my_set.find(s[j]) == my_set.end()){
//                     temp_length++;
//                     my_set.insert(s[j]);
//                     ans = std::max(ans, temp_length);
//                 }else {
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：结束位置j向右移动，遇到重复时开始位置i向右跳动
 * 时间复杂度 O(n)
 **/

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int ans = 0;
        int i = 0;
        int j = 0;
        map<char,int> my_map;

        while(j<s.length()){
            if (my_map.find(s[j]) == my_map.end() || my_map[s[j]]<i)
            {
                my_map[s[j]] = j;
                ans = std::max(ans, j - i + 1);
            }
            else
            {
                i = my_map[s[j]] + 1;
                my_map[s[j]] = j;
            }
            j++;
        }


        return ans;
    }
};

// int main(){
//     cout << "hello" << endl;
//     Solution solution;
//     cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
//     cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
//     cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
//     cout << solution.lengthOfLongestSubstring(" ") << endl;
//     cout << solution.lengthOfLongestSubstring("aabaab!bb") << endl;
//     cout << solution.lengthOfLongestSubstring("dvdf") << endl;
// }
