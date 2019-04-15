#include<iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    // 用文件输入代替 stdin， 方便 debug
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        map<string, int> my_map;
        long ans = 0;
        for (int j = 0; j < m; j++)
        {
            int T;
            cin >> T;
            set<string> my_set;
            for (int t = 0; t < T; t++)
            {
                int tempX, tempY;
                string tempKey;
                cin >> tempX >> tempY;
                tempKey = "" + std::to_string(tempX) + "," + std::to_string(tempY);
                my_set.insert(tempKey);
                my_map[tempKey]++;
                ans = std::max(ans, (long)my_map[tempKey]);
            }
            for (map<string, int>::iterator it = my_map.begin(); it != my_map.end(); it++)
            {
                if (my_set.find(it->first) == my_set.end())
                {
                    it->second = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
