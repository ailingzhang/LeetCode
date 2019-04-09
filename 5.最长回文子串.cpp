/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (24.82%)
 * Total Accepted:    49K
 * Total Submissions: 197.5K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string ss;
        int n=s.size();
        if(n==0||n==1) return s;
        //if(n==2) return s[]
        vector<vector<int>> dp(n, vector<int>(n, 0));//记住这种初始化方法
        //int dp[1000][1000];
        //memset(dp,0,sizeof(dp));
        //int dp[n][n]={0};
/*         if(n==2&&s[0]!=s[1]) {
            ss=s[0];
            return ss;
        } */
        int left=0;  //int right,left=0;一起赋值不行？？？；样例ac，abcda非回文串的过不了
        int right=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=1;
                    left=i;
                    right=i+1;
                }
            }
        }

        for(int l=3;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1; //l表示回文串的长度，j为末端点
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    left=i;
                    right=j;
                }
            }
        }
/*         if(left==right){
            ss=s[0];
            return ss;
        } */
        ss=s.substr(left,right-left+1);//ss初始化长度默认为零，直接赋值，不能下标访问，会越界
        return ss;
    }
};

