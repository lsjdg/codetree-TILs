#include <iostream>

using namespace std;

int grid[200][200];
int n, m;

int lBlockOne(int x, int y) {
    if (x == n - 1 || y == 0) {
        return 0;
    } else {
        return grid[x][y] + grid[x + 1][y] + grid[x][y - 1];
    }
}

int lBlockTwo(int x, int y) {
    if (x == n - 1 || y == m - 1) {
        return 0;
    } else {
        return grid[x][y] + grid[x + 1][y] + grid[x][y + 1];
    }
}

int lBlockThree(int x, int y) {
    if (x == 0 || y == m - 1) {
        return 0;
    } else {
        return grid[x][y] + grid[x - 1][y] + grid[x][y + 1];
    }
}

int lBlockFour(int x, int y) {
    if (x == 0 || y == 0) {
        return 0;
    } else {
        return grid[x][y] + grid[x - 1][y] + grid[x][y - 1];
    }
}

int iBlockOne(int x, int y) {
    if (x == 0 || x == n - 1) {
        return 0;
    } else {
        return grid[x][y] + grid[x - 1][y] + grid[x + 1][y];
    }
}

int iBlockTwo(int x, int y) {
    if (y == 0 || y == m - 1) {
        return 0;
    } else {
        return grid[x][y] + grid[x][y - 1] + grid[x][y + 1];
    }
}

int main() {
    int max = 0;
    int lOne, lTwo, lThree, lFour, iOne, iTwo;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            lOne = lBlockOne(i, j);
            if (lOne > max) {
                max = lOne;
            }
            lTwo = lBlockTwo(i, j);
            if (lTwo > max) {
                max = lTwo;
            }
            lThree = lBlockThree(i, j);
            if (lThree > max) {
                max = lThree;
            }
            lFour = lBlockFour(i, j);
            if (lFour > max) {
                max = lFour;
            }
            iOne = iBlockOne(i, j);
            if (iOne > max) {
                max = iOne;
            }
            iTwo = iBlockTwo(i, j);
            if (iTwo > max) {
                max = iTwo;
            }
        }
    }
    cout << max;
}