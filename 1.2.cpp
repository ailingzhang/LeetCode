#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX_N = 5e5 + 5;
int a[MAX_N];
int main() {
	long long ans, sum;
	int n, minnum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = 0;
	ans = 0;
	for (int j = 100; j >= 1; j--) {
		sum = 0, minnum = 101;
		for (int i = 0; i <= n; i++) {
			if (a[i] < j) {
				ans = max(ans, sum * minnum);
				minnum = 101, sum = 0;
			}
			else {
				sum += a[i];
				minnum = min(minnum, a[i]);
			}
			//printf("i = %d, j = %d, ans = %lld\n", i, j, ans);
		}

	}
	printf("%lld\n", ans);
	return 0;
}