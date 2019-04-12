#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip> 
using namespace std;

/**
字节跳动2019春招后端开发3月16日笔试题
第四题:
有N根绳子，第i根长为Li，现需要m根等长绳子。
你可以对N根绳子进行任意剪裁(不能拼接)，计算出这m根绳子最长的长度是多少?
求解思路：二分法

注意绳长可以为浮点数
**/

//每段绳长length，最多可以被切成几段
int num(double*a,double length,int n){
	int k = 0;
	for (int i = 0; i < n; i++){
		k = k + a[i] / length;
	}
	return k;
}
int main(){
	int n;
	double maxn = 0;//记录最大绳长
	cin >> n;
	double*len = new double[n];
	for (int i = 0; i < n; i++){
		cin >> len[i];
		maxn = max(maxn, len[i]);
	}
	int m;
	cin >> m;

	//使用二分法求最大长度
	bool flag = false;
	double l = 0;
	double r = maxn;
	double mid;
	while ((r-l)>1e-4){
		mid = (l + r) / 2;
		if (num(len, mid, n) == m && (r - l)<=1e-4){//刚开始忘加限制(r - l)<=1e-4)
			flag = true;
			break;
		}
		if (num(len, mid, n) < m){
			r = mid;//刚开始写的r = mid-1;这是浮点型的二分法，不可
		}
		else {
			l = mid;
		}
	}
	if (flag == true) cout << setprecision(2)<<mid*m << endl;
	else cout << "l=" << mid << ' ' << "l*m=" << l*m << endl;
	// else cout << l*m << endl;

}