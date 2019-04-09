/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.38%)
 * Total Accepted:    61.4K
 * Total Submissions: 189.5K
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
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string aa;
        int min=__INT_MAX__;
        bool flag=true;
        if(strs.size()==0) return "";//需要判断，进入循环的条件
        else{
            for(int i=0;i<strs.size();i++){
            if (strs[i].length()<min) min=strs[i].length();
        }
        for(int i=0;i<min;i++){
            int j;
            //flag=true;
            for(j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){//刚开始写成了strs[i][j]!=strs[i][j+1]注意
                    flag=false;
                    break;//大姐，你怎么老是把break写在前面，害我检查好久
                }
            }
            if(flag==true){
                aa=aa+strs[j][i];
            }
            else return aa;//不用break，直接return
        }
        return aa;
        }

    }
};

