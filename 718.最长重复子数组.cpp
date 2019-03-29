/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (42.54%)
 * Total Accepted:    2.1K
 * Total Submissions: 4.9K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出: 3
 * 解释: 
 * 长度最长的公共子数组是 [3, 2, 1]。
 * 
 * 
 * 说明:
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //int dp[1000][1000];//直接二维数组装不下
/*         vector<vector<int>> dp;
        for(int i=0;i<A.size()+1;i++){
            for(int j=0;j<B.size()+1;j++){
                dp[i][j]=0;
            }
        } */ //只是赋值，并没有设置vector的行列数，用下面的方法。
        vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1, 0));
/*         for(int i=0;i<A.size();i++){
            dp[i][0]=0;
        }
        for(int j=0;j<B.size();j++){
            dp[0][j]=0;
        } */
        int *sa=new int[A.size()+1];
        int *sb=new int[B.size()+1];
        for(int i=1;i<A.size()+1;i++){
            sa[i]=A[i-1];
        }
        for(int i=1;i<B.size()+1;i++){
            sb[i]=B[i-1];
        }
        //记录连续的重复子数组，连续！
        int res=0;
        for(int i=1;i<A.size()+1;i++){
            for(int j=1;j<B.size()+1;j++){
                if(sa[i]==sb[j]) dp[i][j]=dp[i-1][j-1]+1;
                //else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                res=max(dp[i][j],res);
            }
        }
        return res;  

    }
};

