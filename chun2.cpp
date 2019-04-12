/**
字节跳动2019春招后端开发3月16日笔试题
第二题:
规则：
1.三个同样的字母连在一起，一定是拼写错误，去掉一个就好了。比如:helllo --> hello
2.两对一样的字母(AABB型)连在一起，一定是拼写错误，去掉第二对的第一个字母。比如:helloo --> hello
3.上面的规则优先从左到右匹配，即如果是AABBCC型，应优先考虑修复AABB为AABCC。
输入：
一串字符串
输出：
修正后的字符串
求解思路：遍历一次字符串即可
**/
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main(){
//	string s;
//	cin >> s;
//	int n1 = 0;
//	int n2 = 1;
//	int n3 = 2;
//	int n4 = 3;
//	int len = s.length();
//	if (len <= 2){
//		cout << s << endl;
//		return 0;
//	}
//	for (; n3 < len;){
//		if (s[n1] == s[n2] && s[n1] == s[n3]){
//			s.erase(s.begin()+n3); //erase的使用！
//		}
//		else{
//			n1++;
//			n2++;
//			n3++;
//		}
//	}
//	n1 = 0;
//	n2 = 1;
//	n3 = 2;
//	n4 = 3;
//	int len2 = s.length();
//	if (len2 <= 3){
//		cout << s << endl;
//		return 0;
//	}
//	for (; n4 < len;){
//		if (s[n1] == s[n2] && s[n3] == s[n4]){
//			s.erase(s.begin() + n4);
//		}
//		else{
//			n1++;
//			n2++;
//			n3++;
//			n4++;
//		}
//	}
//	cout << s << endl;
//	return 0;
//
//}