/**
字节跳动2019春招后端开发3月16日笔试题
第三题：
n个人参加比赛，结束后每个人一个分数。
领奖时所有人依次排成一圈，第一个和第n个相邻。
要求:
1.如果某个人的分数比旁边的人高，那么奖品数量也要比他多。
2.每个至少得一个奖品。
问最少应该准备多少个奖品?
求解思路：化环为直，动态调整循环次数
**/
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn=10000;
//struct node{   //node用来给每个节点排序，得到key的索引顺序
//	int key;
//	int value;
//	//int score;
//}nodes[maxn];
//
//bool cmp(node a, node b){
//	return a.value < b.value;
//}
//
//int main(){
//	int n;
//	cin >> n;
//	int*a = new int[n];//记录原始排序的每个人的得分数
//	int m;
//	for (int i = 0; i < n; i++){
//		cin >> m;
//		nodes[i].key = i;
//		nodes[i].value = m;
//		//nodes[i].score = 0;
//		a[i] = 0;
//	}
//
//	sort(nodes, nodes + n,cmp);
//
//	int sum = 0;
//	for (int i = 0; i < n; i++){
//		int p;
//		p = nodes[i].key;
//		if (p == 0){
//			a[p] = max(a[p + 1], a[p + n - 1]) + 1;// 错误写法 nodes[i].score = max(nodes[p -1].score, nodes[p -n + 1].score) + 1;
//			sum = sum + a[p];
//		}
//
//		if (p == n - 1){
//			a[p] = max(a[p - 1], a[p - n + 1]) + 1;
//			sum = sum + a[p];
//		}
//
//		else{
//			a[p] = max(a[p + 1], a[p - 1]) + 1;
//			sum = sum + a[p];
//		}
//	}
//	for (int i = 0; i < n; i++){
//		cout<<a[i] << ' ';
//	}
//	cout << endl;
//	cout << sum << endl;
//}