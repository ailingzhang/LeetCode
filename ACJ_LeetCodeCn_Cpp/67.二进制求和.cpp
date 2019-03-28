/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (47.18%)
 * Total Accepted:    19.3K
 * Total Submissions: 40.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

/************
 * 方案一： 按个位到高位，按位加，控制进位
 * 
 * 时间复杂度：O(n+m), 设数字a为n位数，数字b为m位数
 * *********/

#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string addBinary(string a, string b) {
        string s;

        const int N = 2; // N进制
        int i = 0;
        int carry = 0; // 进位
        while (i < a.size() || i < b.size() || carry != 0)
        {
            int temp = 0;
            temp += carry;            
            if (a.size() >= i + 1) {
                temp += a[a.size() - 1 - i] - '0';
            }
            if (b.size() >= i+1) {
                temp += b[b.size() - 1 - i] - '0';
            }

            char c = (temp % N) + '0';
            s = c + s;
            carry = temp / N;

            i++;
        }
        return s;
    }
};

/***********
 * 测试：main函数
 * **********/

// int main() {
//     cout << "hello" << endl;
//     Solution solution;

//     cout << solution.addBinary("11","1") << endl;

// }

