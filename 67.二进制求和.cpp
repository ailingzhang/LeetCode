/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (47.08%)
 * Total Accepted:    19.1K
 * Total Submissions: 40.6K
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
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

/* int num(int x,int p){
    int y=0,product=1;
    while(x!=0){
        y=y+(x%10)*product;
        x=x/10;
        product=product*p;
    }
    return y;

}

string num_p(long long y){
    //long long z=0;
    //long long p=1;
    int num=0;
    string z;
    do{
        char c=y%2+'0';
        z=c+z;
        y=y/2;
        //p=p*10;
    }while(y!=0);
    //reverse(z.begin(),z.end());
    return z;
} */
/* class Solution {
public:
    string addBinary(string a, string b) {
        //string c;
        long long aa=atoi(a.c_str());
        long long bb=atoi(b.c_str());
        long long cc=num(aa,2)+num(bb,2);
        return num_p(cc);
        }
    }; */
class Solution {
public:
    string addBinary(string a, string b) {
        //string c;
        int count=0;//
        int arr=0;
        int i=0;
        string s;
        while(i<a.size()||i<b.size()||arr!=0){
            int aa,bb;
            if(i<a.size()){
                aa=a[a.size()-i-1]-'0';
            }
            else aa=0;
            if(i<b.size()){
                bb=b[b.size()-i-1]-'0';
            }
            else bb=0; 
            count=aa+bb+arr;
            char c=count%2+'0';
            arr=count/2;
            s=c+s;
            i++;
        }

        return s;
        }
    };

