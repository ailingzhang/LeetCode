//#include<iostream>
//using namespace std;
//
//int main(){
//	int n, index;
//	//int *a = new int [];
//	//int *b = new int[];
//	//int sum = 0;
//	cin >> n >> index;
//	int *a = new int[n];
//	for (int i = 0; i < n; i++){
//		cin >> a[i];
//	}
//	int ii=0;
//	int count = 0;
//	bool flag = false;
//	for (int i = index-1; ; i=(i+n-1)%n){
//		a[i] = a[i] - 1;
//		count++;
//		if (a[i] == 0&&flag==false) {
//			ii = i;
//			flag = true;
//		}
//
//		if (flag==true&&i==(ii+1)%n) {
//			a[ii] = count;
//			break;
//		}
//
//	}
//	for (int i = 0; i < n; i++){
//		if (i != n - 1) cout << a[i] << " ";
//		else cout << a[i];
//	}
//	cout << endl;
//	return 0;
//
//}