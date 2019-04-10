/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (33.61%)
 * Total Accepted:    4.2K
 * Total Submissions: 12.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */
#include <iostream>
#include <map>
using namespace std;

class Solution
{
  public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()){
            return "";
        }
        int left_point = 0;
        int right_point = -1;
        map<char, int> target_map;
        map<char, int> now_map;

        for (char c:t) {
            target_map[c]++;
        }

        string ans = "";
        while (right_point < 0 || right_point < s.size())
        {
            right_point++;
            now_map[s[right_point]]++;

            bool flag_status_ok = true;
            for (auto it : target_map)
            {
                if (now_map[it.first] < target_map[it.first])
                {
                    flag_status_ok = false;
                    break;
                }
            }
            while (flag_status_ok)
            {
                string temp = s.substr(left_point, right_point - left_point + 1);
                if (ans == "" || temp.length() < ans.length()) {
                    ans = temp;
                }
                now_map[s[left_point]]--;
                if (t.find_first_of(s[left_point]) != string::npos && now_map[s[left_point]] < target_map[s[left_point]])
                {
                    flag_status_ok = false;
                }
                left_point++;
            }
        }
        return ans;
    }
};

// int main() {
//     cout << "hello world" << endl;
//     Solution solution;

//     cout << solution.minWindow("ADOBECODEBANC", "ABC") << endl;
// }
