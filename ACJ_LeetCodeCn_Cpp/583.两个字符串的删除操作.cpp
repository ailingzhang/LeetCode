/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (41.25%)
 * Total Accepted:    913
 * Total Submissions: 2.2K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "sea", "eat"
 * 输出: 2
 * 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 * 
 * 
 * 说明:
 * 
 * 
 * 给定单词的长度不超过500。
 * 给定单词中的字符只含有小写字母。
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
    int minDistance(string word1, string word2) {

        // 动态规划初始化
        vector<vector<int> > dp(word1.size() + 1, vector<int>(word2.size() + 1, __INT_MAX__));

        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++)
        {
            dp[0][j] = j;
        }

        // 动态规划
        for(int i = 1; i <= word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
                }
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
            } 
        }

        return dp[word1.length()][word2.length()];
    }
};

// int main() {
//     cout << "hello" << endl;
//     Solution solution;
//     cout << solution.minDistance("sea", "eat") << endl;
//     cout << solution.minDistance("b", "") << endl;
//     cout << solution.minDistance("", "") << endl;
// }
