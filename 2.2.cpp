////#include<iostream>
////using namespace std;
////
////int main(){
////	int n, m, c;
////	long long a[50][10000] = { 0 };
////	//cout << "ok1" << endl;
////	cin >> n >> m >> c;
////	//for (int i = 0; i < c; i++){
////	//	for (int j = 0; j < n; j++){
////	//		a[i][j] = { 0 };
////	//	}
////	//}
////	int k, p;
////	for (int i = 0; i < n; i++){
////		cin >> k;
////		if (k != 0){
////			for (int j = 0; j < k; j++){
////				cin >> p;
////				a[p - 1][i] = 1;
////			}
////		}
////	}
////	cout << "ok" << endl;
////	for (int i = 0; i < c; i++){
////		for (int j = 0; j < n; j++){
////			cout << a[i][j] << " ";
////		}
////		cout << endl;
////	}
////}
//
//#include <iostream>
//using namespace std;
//
//int main(){
//	int n, m, c;
//	int *col, *first;
//	cin >> n >> m >> c;
//	col = new int[c];
//	first = new int[c];
//	int *mul = new int[c];
//	for (int m = 0; m < c; m++)
//	{
//		col[m] = 0;
//		first[m] = 0;
//		mul[m] = 0;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		int colnum;
//		cin >> num;
//		if (num > c) return 0;
//		for (int j = 0; j < num; j++)
//		{
//			cin >> colnum;
//			if (first[colnum - 1] == 0) first[colnum - 1] = i + 1;
//			else if (i - col[colnum - 1] + 2 <= m || first[colnum - 1] + n - i <= m) mul[colnum - 1] = 1;
//			col[colnum - 1] = i + 1;
//		}
//	}
//	int count = 0;
//	for (int k = 0; k < c; k++){
//		if (mul[k] == 1) count++;
//	}
//	cout << count << endl;
//	return 0;
//}