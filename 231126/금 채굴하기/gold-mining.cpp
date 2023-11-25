#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

//k 크기의 마름모 영역 내 타일 갯수
int tileCost(int k) {
    return k * k + (k + 1) * (k + 1);
}

//마름모 영역 내 금 갯수
int goldInArea(int centerRow, int centerCol, int k) {
    int cnt = 0;
    for (int row = centerRow - k; row <= centerRow + k; row++) {
        for (int col = centerCol - k; col <= centerCol + k; col++){
            if (row < 0 || row >= n || col < 0 || col >= n) {
                continue;
            }
            if (abs(row - centerRow) + abs(col - centerCol) <= k){
                cnt += grid[row][col];
            }
        }
    }
    return cnt;
}

int main() {
    //입력 받고 금 갯수 관리
    cin >> n >> m;
    int goldCount = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) { goldCount++; }
        }
    }
    //금 없으면 최솟값 0, 있으면 1
    int maxGold = (goldCount == 0 ? 0 : 1);
    //손해 안 보는 최대 크기 마름모까지 순회
    while (tileCost(k) <= goldCount * m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxGold = max(maxGold, goldInArea(i, j, k));
            }
        }
        k++;
    }

    cout << maxGold;
}