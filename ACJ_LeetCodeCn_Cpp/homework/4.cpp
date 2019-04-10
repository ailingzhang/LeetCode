#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 初始化
    int n, x;
    long temp;
    vector<long> arr;

    // 输入
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    int min_value = arr[x - 1];
    int min_index = x - 1;
    int min_distance = 0;
    for (int i = 1; i < n; i++)
    {
        int index = x - i - 1;
        if (index < 0)
        {
            index += n;
        }
        if (arr[index] < min_value)
        {
            min_value = arr[index];
            min_index = index;
            min_distance = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int index = x - i - 1;
        if (index < 0)
        {
            index += n;
        }
        if (i < min_distance)
        {
            arr[index] -= min_value + 1;
        }
        else if (i > min_distance)
        {
            arr[index] -= min_value;
        }
        else
        {
            arr[index] = (long)n * min_value + min_distance;
        }
    }

    // 输出
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}