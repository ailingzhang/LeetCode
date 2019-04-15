//#include<iostream>
//#include<algorithm>
//#include<map>
//#include<vector>
//using namespace std;
////n，q值太大，导致时间复杂度太大，不符合要求
//
//void match(int*a, int l, int r, int k){
//	int count = 0;
//	for (int j = l - 1; j <= r - 1; j++){
//		if (a[j] == k) count++;
//	}
//	cout << count << endl;
//}
//int main(){
//	int n;
//	cin >> n;
//	int *a = new int[n];
//	for (int i = 0; i < n; i++){
//		cin >> a[i];
//	}
//	int m;
//	cin >> m;
//	int l, r, k;
//	for (int i = 0; i < m; i++){
//		cin >> l >> r >> k;
//		match(a, l, r, k);
//	}
//	return 0;
//}