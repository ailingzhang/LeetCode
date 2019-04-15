//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//void getbc(int i, long long a, long long*b, long long*c, long long d1, long long d2){
//	//i判断是四种情况中的哪种
//	switch (i){
//	case 0:
//		*b = a - d1;
//		*c = a - d1 + d2;
//		break;
//	case 1:
//		*b = a - d1;
//		*c = a - d1 - d2;
//		break;
//	case 2:
//		*b = a + d1;
//		*c = a + d1 - d2;
//		break;
//	case 3:
//		*b = a + d1;
//		*c = a + d1 + d2;
//		break;
//	}
//}
//int main(){
//	int p;
//	cin >> p;
//	for(; p--;){//while造成循环错误？
//		long long n, k;
//		long long d1, d2;
//		bool flag = false;
//		//scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
//		cin >> n >> k >> d1 >> d2;
//		if (n % 3) {
//			cout << "no" << endl;
//			continue;
//		}
//		//x[i]为
//		long long x[4] = {
//			k + 2 * d1 - d2,
//			k + 2 * d1 + d2,
//			k - 2 * d1 - d2,
//			k - 2 * d1 + d2
//		};
//		//依次遍历每种可能的x的解
//		for (int i = 0; i < 4; i++){
//			int sum = 0;
//
//			for (long long t = x[i]; t;){
//				sum = sum + t % 10;
//				t = t / 10;
//			}
//			if (sum % 3 == 0 && x[i] / 3 >= 0 && x[i] / 3 <= k&& x[i] <= n){
//				long long a = x[i] / 3, b, c;
//				getbc(i, a, &b, &c, d1, d2);
//				if (0 <= b && b <= min(k, n / 3) && 0 <= c && c <= min(k, n / 3)) {
//					flag = true;
//					break;
//				}
//			}
//		}
//		cout << (flag ? "yes" : "no") << endl;
//	}
//	return 0;
//}
