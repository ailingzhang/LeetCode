#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
    long maxScore(vector<int>& init_status){
        if (init_status.size()!=24) {
            return -1;
        }
        long ans = LONG_MIN;
        dfs(0, init_status, ans);
        return ans;
    }
private:

    void dfs(int dep, vector<int>& now_status, long& ans)
    {
        ans = std::max(ans, getSum(now_status));
        if (dep == 5)
        {
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            flip(now_status, i);
            dfs(dep + 1, now_status, ans);
            flip(now_status, i);
            flip(now_status, i);
            dfs(dep + 1, now_status, ans);
            flip(now_status, i);
        }
    }

    void flip(vector<int> &a, int index)
    {
        vector<int> b(a);
        for (int i = 0; i < a.size(); i++)
            b[i] = a[mp[index][i]];
        a = b;
    }

    long getSum(vector<int> &arr)
    {
        long ret = 0;
        for (int i = 0; i < 6; i++)
        {
            long s = 1;
            for (int j = 0; j < 4; j++) {
                s *= arr[face[i][j]];
            }
            ret += s;
        }
        return ret;
    }

private:
    const int face[6][4] = {
        {0, 1, 2, 3},
        {4, 5, 10, 11},
        {6, 7, 12, 13},
        {8, 9, 14, 15},
        {16, 17, 18, 19},
        {20, 21, 22, 23}};

    const int mp[6][24] = {
        // 原始
        //  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23},
        // 下层右旋
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 21, 20, 10, 11, 12, 13, 18, 16, 19, 17, 15, 14, 22, 23},
        // 上层右旋
        {1, 3, 0, 2, 23, 22, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 9, 8},
        // 右层后旋
        {0, 21, 2, 23, 4, 5, 6, 1, 9, 15, 10, 11, 12, 3, 8, 14, 16, 7, 18, 13, 20, 17, 22, 19},
        // 左层后旋
        {20, 1, 22, 3, 10, 4, 0, 7, 8, 9, 11, 5, 2, 13, 14, 15, 6, 17, 12, 19, 16, 21, 18, 23},
        // 前层右旋
        {0, 1, 11, 5, 4, 16, 12, 6, 2, 9, 10, 17, 13, 7, 3, 15, 14, 8, 18, 19, 20, 21, 22, 23},
        // 后层右旋
        {10, 4, 2, 3, 18, 5, 6, 7, 8, 0, 19, 11, 12, 13, 14, 1, 16, 17, 15, 9, 21, 23, 20, 22}};
};

int main() {
    vector<int> input_vector;
    int temp;
    for (int i = 0; i < 24; i++)
    {
        cin >> temp;
        input_vector.push_back(temp);
    }

    Solution solution;
    cout << solution.maxScore(input_vector) << endl;
}