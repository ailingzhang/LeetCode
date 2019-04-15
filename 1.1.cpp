//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<algorithm>
//using namespace std;
///*
//头条测开1
//
//第一行输入点集的个数 N， 接下来 N 行，每行两个数字代表点的 X 轴和 Y 轴。
//对于 50%的数据,  1 <= N <= 10000;
//对于 100%的数据, 1 <= N <= 500000;
//
//输出“最大的” 点集合， 按照 X 轴从小到大的方式输出，每行两个数字分别代表点的 X 轴和 Y轴。
//
//运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
//(node[i].x < node[j].x) && (node[i].y < node[j].y)
//
//按照y值从大到小排序，然后扫描，保存当前最大的x，如果该点比x大，那么该点满足条件
//注意要使用scanf,printf,使用cin,cout会超时!
//*/
//struct Node{
//	long x;
//	long y;
//}node[500001],nodes[500000];
//
//bool cmp(Node a, Node b){
//	return a.y > b.y;
//}
//int main(){
//	int k;
//	cin >> k;
//	for (int i = 0; i < k; i++){
//		cin >> node[i].x;
//		cin >> node[i].y;
//	}
//	sort(node, node + k, cmp);
//	//int p=0;
//	//for (int i = 0; i < k; i++){
//	//	bool flag = true;
//	//	
//	//	for (int j = i+1; j < k; j++){
//	//		if ((node[i].y < node[j].y)){
//	//			flag = false;
//	//			break;
//	//		}
//	//	}
//	//	if (flag == true){
//	//		nodes[p].x = node[i].x;
//	//		nodes[p].y = node[i].y;
//	//		p++;
//	//	}
//	//		
//	//}
//
//	////cout << "p=" << p << endl;
//	//sort(nodes, nodes + p, cmp);
//
//	//for (int i = 0; i < p; i++){
//	//	cout << nodes[i].x << ' ' << nodes[i].y << endl;
//	//}
//
//	int maxx = -1;
//	for (int i = 0; i < k; i++){
//		if (node[i].x>maxx){
//			maxx = node[i].x;
//			cout << node[i].x << ' ' << node[i].y << endl;
//		}
//	}
//	return 0;
//}
//
