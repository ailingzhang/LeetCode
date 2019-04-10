#include <vector>
#include <iostream>
using namespace std;







int maxSubmatrixSum(std::vector<std::vector<int>> matrix, int n, int m)
{
    int base_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            base_sum += matrix[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i + n - 1 < matrix.size(); i++) {
        if (i > 0) {
            for (int y = 0; y < m; y++) {
                base_sum += matrix[i + n - 1][y] - matrix[i - 1][y];
            }
        }
        int real_sum = base_sum;
        if (real_sum > result) {
            result = real_sum;
        }
        for (int j = 1; j + m - 1 < matrix[i].size(); j++) {
            for (int x = 0; x < n; x++) {
                real_sum += matrix[i + x][j + m - 1] - matrix[i + x][j - 1];
            }
            if (real_sum > result) {
                result = real_sum;
            }
        }
    }
    return result;
}

int main() {
    cout << "hello" << endl;
}

/* 纠错

3   int base_sum = 0;

10   for (int i = 0; i + n - 1 < matrix.size(); i++) {

13         base_sum += matrix[i + n - 1][y] - matrix[i - 1][y];

20     for (int j = 1; j + m - 1 < matrix[i].size(); j++) {

22         real_sum += matrix[i+x][j + m - 1] - matrix[i+x][j - 1];

*/