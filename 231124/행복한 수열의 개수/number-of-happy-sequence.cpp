#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    int cnt = 0;
    int consecutiveCount = 1;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    if (m == 1) {
        cnt = 2 * n;
    } else {
        //행 순회
        for (vector<int> row: v) {
            for (int i = 0; i < n - 1; i++) {
                if (row[i] == row[i + 1]) {
                    consecutiveCount++;
                    if (consecutiveCount == m) {
                        cnt++;
                        break;
                    }
                }else{
                    consecutiveCount = 1;
                }
            }
            consecutiveCount = 1;
        }

        //열 순회
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (v[i][j] == v[i + 1][j]) {
                    consecutiveCount++;
                    if (consecutiveCount == m) {
                        cnt++;
                        break;
                    }
                }else{
                    consecutiveCount = 1;
                }
            }
            consecutiveCount = 1;
        }
    }

    cout << cnt << '\n';
}