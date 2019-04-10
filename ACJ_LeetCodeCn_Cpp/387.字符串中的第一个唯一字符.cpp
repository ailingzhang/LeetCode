/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (36.73%)
 * Total Accepted:    25.1K
 * Total Submissions: 67.8K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
#include <map>
#include <string>
using namespace std;
/**
 * 时间复杂度O(N)
 * **/
class Solution
{
  public:
    int firstUniqChar(string s) {
        if (s.empty()){
            return -1;
        }
        map<char,int> my_map;

        for (char c : s)
        {
            my_map[c] += 1;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if (my_map[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};

