/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (36.90%)
 * Total Accepted:    24.9K
 * Total Submissions: 67.5K
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
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        int a[26]={0};//int a[26];不行，必须赋初值
        for(int i=0;i<n;i++){
            a[s[i]-'a']=a[s[i]-'a']+1;//int m[256] = {0};m[s[i]];ASCII表共能表示256个字符
        }
        for(int i=0;i<n;i++){
            if(a[s[i]-'a']==1){
                return i;
            }

        }
        return -1;
    }
};

