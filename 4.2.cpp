//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int main()
//{
//	int n, m;
//	string s;
//	for (; cin >> n >> m >> s;) {
//		int ans = 0;
//		for (char c = 'a'; c < 'c'; ++c) {//目标字母是a还是b
//			vector<int> dp(s.size() + 1, 0);//dp[][]表示i位及之前连续的最大字符串长度
//			for (int i = 1; i <= s.size(); ++i)
//				dp[i] = dp[i - 1] + (s[i - 1] == c);
//			int l = -1, r = s.size() - 1;
//			while (l < r) {
//				int mid = (l + r + 1) / 2;
//				bool f = false;
//				for (int i = 0; i + mid - 1 < s.size(); i++)
//				if (dp[i + mid] - dp[i] <= m) {
//					f = true;
//					break;
//				}
//				f ? l = mid : r = mid - 1;
//			}
//			ans = max(ans, r);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}