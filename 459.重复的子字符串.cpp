/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (39.16%)
 * Total Accepted:    4.1K
 * Total Submissions: 10.5K
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
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
/*         if(n%2!=0) {       考虑奇数字符串abcabcabc也满足要求
            bool flag=true;
            for(int i=0;i<n-1;i++){
                if(s[i]!=s[i+1]) {
                    flag=false;
                    return false;
                }
            }
            if(flag) return true;
        } */
        if(n==0||n==1) return false;
        for(int i=n/2;i>0;i--){
                if(n%i==0){
                    bool flag=true;
                    for(int j=n/i;j>0;j--){
                        if(s.substr(0,i)!=s.substr(i*(j-1),i)){//s.substr(pos, n)  截取s中从pos开始（包括0）的n个字符的子串，并返回
                            flag=false;                        //java中s.substring(0, i)，从0到i-1位
                            break;
                        }
                    }
                    if(flag) return true;
                }
            }
        return false;
    }
};

