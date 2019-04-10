
/**
 * 别人的答案
 * [https://blog.csdn.net/flushhip/article/details/78267949#comments]
 * **/

#include <bits/stdc++.h>

using namespace std;

const int dirx[] = {-1, 0, 1, 0};
const int diry[] = {0, 1, 0, -1};

int n, m;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator == (const Point &other) const {
        return x == other.x && y == other.y;
    }
};

struct Node {
    Point peo, box;
    int step;
    Node() {}
    Node(Point peo, Point box, int step = 0) :
        peo(peo), box(box), step(step) {}
    bool operator < (const Node &other) const {
        return step > other.step;
    }
};

struct Peo {
    Point point;
    int step;
    Peo() {}
    Peo(Point point, int step = 0) :
        point(point), step(step) {}
};

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(Point src, Point des, Point box, vector<string> &mp)
{
    queue<Peo> que;
    vector<vector<bool> > used(n, vector<bool>(m, false));
    que.push(src);
    used[src.x][src.y] = true;
    int ret = -1;
    while (!que.empty()) {
        auto now = que.front();
        que.pop();
        if (now.point == des) {
            ret = now.step;
            break;
        }
        for (int k = 0; k < 4; k++) {
            int tx = now.point.x + dirx[k];
            int ty = now.point.y + diry[k];
            if (check(tx, ty) && mp[tx][ty] == '.' && !(Point(tx, ty) == box) && !used[tx][ty])
                que.emplace(Point(tx, ty), now.step + 1), used[tx][ty] = true;
        }
    }
    return ret;
}

int main()
{
    // freopen("in", "r", stdin);
    while (cin >> n >> m) {
        string str;
        vector<string> mp;
        Point initS, initE, initZ;
        for (int i = 0; i < n; i++) {
            cin >> str;
            mp.push_back(str);
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == 'S') {
                    initS = Point(i, j);
                    mp[i][j] = '.';
                    break;
                }
            }
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == 'E') {
                    initE = Point(i, j);
                    mp[i][j] = '.';
                    break;
                }
            }
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == '0') {
                    initZ = Point(i, j);
                    mp[i][j] = '.';
                    break;
                }
            }
        }

        vector<vector<bool> > used(n * m + 1000, vector<bool>(n * m + 1000, false));
        priority_queue<Node> que;
        que.emplace(initS, initZ);
        used[initS.x * n + initS.y][initZ.x * n + initZ.y] = true;

        int ans = 0x3f3f3f3f;
        int cnt = 0;
        for (int k = 0; k < 4; k++)
            if (check(initE.x + dirx[k], initE.y + diry[k]) && mp[initE.x + dirx[k]][initE.y + diry[k]] == '.')
                ++cnt;
        while (!que.empty()) {
            auto now = que.top();
            que.pop();
            if (now.box == initE) {
                cnt--;
                ans = min(now.step, ans);
                if (cnt == 0)
                    break;
                else
                    continue;
            }

            for (int k = 0; k < 4; k++) {
                int tmpSx = now.box.x + dirx[k];
                int tmpSy = now.box.y + diry[k];
                int tmpZx = now.box.x + dirx[(k + 2) % 4];
                int tmpZy = now.box.y + diry[(k + 2) % 4];

                if (!check(tmpSx, tmpSy) || !check(tmpZx, tmpZy))
                    continue;
                if (mp[tmpSx][tmpSy] != '.')
                    continue;
                if (mp[tmpZx][tmpZy] != '.')
                    continue;
                if (used[now.box.x * m + now.box.y][tmpZx * m + tmpZy])
                    continue;
                int step = bfs(now.peo, Point(tmpSx, tmpSy), now.box, mp);
                if (step == -1)
                    continue;
                que.emplace(now.box, Point(tmpZx, tmpZy), step + now.step + 1);
                used[now.box.x * m + now.box.y][tmpZx * m + tmpZy] = true;
            }
        }

        cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
    }
    return 0;
}
