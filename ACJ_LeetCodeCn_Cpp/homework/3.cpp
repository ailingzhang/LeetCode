#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

class Point
{
public:
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

class Node
{
public:
    Point man, box;
    int step;

    Node(Point man, Point box,int step = 0) : man(man), box(box),step(step) {}
    bool operator<(const Node &other) const
    {
        return step > other.step;
    }
};

class Solution{
public:
    long pushBox(vector<vector<char> > &the_map) {
        Point initS, initE, initZ;
        for (int i = 0; i < the_map.size(); i++)
        {
            for (int j = 0; j < the_map[i].size(); j++)
            {
                if (the_map[i][j] == 'S')
                {
                    initS = Point(i, j);
                }
                if (the_map[i][j] == 'E')
                {
                    initE = Point(i, j);
                }
                if (the_map[i][j] == '0')
                {
                    initZ = Point(i, j);
                }
            }
        }
        vector< vector< vector< vector<int> > > > used(the_map.size(), 
            vector<vector<vector<int> > >(the_map[0].size(), 
            vector<vector<int> >(the_map.size(), 
            vector<int>(the_map[0].size(), INT_MAX))));

        priority_queue<Node> search_queue;
        search_queue.emplace(initS, initZ, 0);
        used[initS.x][initS.y][initZ.x][initZ.y] = 0;

        int ans = INT_MAX;

        while (!search_queue.empty())
        {
            auto now = search_queue.top();
            search_queue.pop();
            if (now.box == initE)
            {
                ans = std::min(now.step, ans);
                continue;
                
            }
            if (used[now.man.x][now.man.y][now.box.x][now.box.y] < now.step) {
                continue;
            }

            for (int k = 0; k < 4; k++)
            {
                int targetManX = now.box.x + dirx[k];
                int targetManY = now.box.y + diry[k];
                int targetBoxX = now.box.x + dirx[(k + 2) % 4];
                int targetBoxY = now.box.y + diry[(k + 2) % 4];

                if (!check(targetManX, targetManY, the_map) || !check(targetBoxX, targetBoxY, the_map))
                {
                    continue;
                }
                if (the_map[targetManX][targetManY] == '#' || the_map[targetBoxX][targetBoxY] == '#')
                {
                    continue;
                }

                int step = manMove(now.man, Point(targetManX, targetManY), now.box, the_map);
                if (step == -1)
                {
                    continue;
                }
                if (used[now.box.x][now.box.y][targetBoxX][targetBoxY] > step + now.step + 1)
                {
                    if (used[now.box.x][now.box.y][targetBoxX][targetBoxY]!= INT_MAX){
                        // 证明有反例
                        // cout << "有反例:"<< endl;
                        // cout << now.box.x << " " << now.box.y << " " << targetBoxX << " " << targetBoxY << endl;
                        // cout << used[now.box.x][now.box.y][targetBoxX][targetBoxY] << " " << step + now.step + 1 << endl;

                        if (Point(targetBoxX, targetBoxY) == initE) {
                            // 如果这个反例没出现，只能说明那个作者走运了
                            cout << "如果这个反例没出现了，只能说明那个作者走运了:" << endl;
                            cout << now.box.x << " " << now.box.y << " " << targetBoxX << " " << targetBoxY << endl;
                            cout << used[now.box.x][now.box.y][targetBoxX][targetBoxY] << " " << step + now.step + 1 << endl;
                        }
                    }
                    search_queue.emplace(now.box, Point(targetBoxX, targetBoxY), step + now.step + 1);
                    used[now.box.x][now.box.y][targetBoxX][targetBoxY] = step + now.step + 1;
                }
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }

private:
    int manMove(Point src, Point des, Point box, vector<vector<char>> &the_map)
    {
        queue<Point> man_move_queue;
        vector<vector<int>> used(the_map.size(), vector<int>(the_map[0].size(), INT_MAX));
        man_move_queue.push(src);
        used[src.x][src.y] = 0;
        int ret = -1;
        while (!man_move_queue.empty())
        {
            auto now = man_move_queue.front();
            man_move_queue.pop();
            if (now == des)
            {
                ret = used[now.x][now.y];
                break;
            }
            for (int k = 0; k < 4; k++)
            {
                int tx = now.x + dirx[k];
                int ty = now.y + diry[k];
                if (check(tx, ty, the_map) && the_map[tx][ty] != '#' && !(Point(tx, ty) == box))
                {
                    if (used[tx][ty] > used[now.x][now.y]+1) {
                        man_move_queue.emplace(Point(tx, ty));
                        used[tx][ty] = used[now.x][now.y] + 1;
                    }
                }
            }
        }
        return ret;
    }

    bool check(int x, int y, vector<vector<char>> &the_map)
    {
        return (x >= 0 && x < the_map.size() && y >= 0 && y < the_map[0].size());
    }

private:
    const int dirx[4] = {-1, 0, 1, 0};
    const int diry[4] = {0, 1, 0, -1};
};

int main()
{
    // 用文件输入代替 stdin， 方便 debug
    // freopen("stdin2.txt", "r", stdin);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char> > the_map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
       for(int j = 0; j < m; j++)
       {
            cin >> the_map[i][j];
       }
    }

    // 打印出 the_map
    // cout << endl<< endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << the_map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    Solution solution;
    cout << solution.pushBox(the_map) << endl;

    return 0;
}
