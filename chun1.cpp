/**
字节跳动2019春招后端开发3月16日笔试题

第一题：
某国货币系统包含面值1元，4元，16元，64元共计4种硬币，以及面值1024元的纸币。
现在某人使用1024元的纸币购买了一件价格为N(0≤N≤1024)的商品。
请问最少他会收到多少枚硬币?
求解思路：贪心算法
**/
//#include<iostream>
//
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	int m = 1024 - n;
//	int count = 0;
//	count = count + m / 64;
//	m = m % 64;
//	count = count + m / 16;
//	m = m % 16;
//	count = count + m / 4;
//	m = m % 4;
//	count = count + m;
//	cout << count << endl;
//
//}