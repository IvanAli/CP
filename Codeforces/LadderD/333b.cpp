#include <bits/stdc++.h>
using namespace std;

int n, m;
bool row[1005], col[1005];

int solve() {
    int grid[1005][1005];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) grid[i][j] = 0;
    int ret = 0;
    for (int i = 0, j = 0; i < n && j < n; i++, j++) {
        while (row[i]) i++;
        if (i < n) {
            if (!grid[i][0] && !grid[0][i] && !grid[n - 1][n - i - 1]) {
                grid[i][0] = 1;
                ret++;
            } else if (!grid[i][n - 1] && !grid[n - 1][i] && !grid[0][n - i - 1]) {
                grid[i][n - 1] = 1;
                ret++;
            }
        }
        while (col[j]) j++;
        if (j < n) {
            if (!grid[0][j] && !grid[j][0] && !grid[n - j - 1][n - 1]) {
                grid[0][j] = 1;
                ret++;
            } else if (!grid[n - 1][j] && !grid[j][n - 1] && !grid[n - j - 1][0]) {
                grid[n - 1][j] = 1;
                ret++;
            }
        }
    }
    return ret;
}

int solve2() {
    int grid[1005][1005];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) grid[i][j] = 0;
    int ret = 0;
    for (int i = 0, j = 0; i < n && j < n; i++, j++) {
        while (col[j]) j++;
        if (j < n) {
            if (!grid[0][j] && !grid[j][0] && !grid[n - j - 1][n - 1]) {
                grid[0][j] = 1;
                ret++;
            } else if (!grid[n - 1][j] && !grid[j][n - 1] && !grid[n - j - 1][0]) {
                grid[n - 1][j] = 1;
                ret++;
            }
        }
        while (row[i]) i++;
        if (i < n) {
            if (!grid[i][0] && !grid[0][i] && !grid[n - 1][n - i - 1]) {
                grid[i][0] = 1;
                ret++;
            } else if (!grid[i][n - 1] && !grid[n - 1][i] && !grid[0][n - i - 1]) {
                grid[i][n - 1] = 1;
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        row[r] = true;
        col[c] = true;
    }
    row[0] = col[0] = row[n - 1] = col[n - 1] = true;
    int ans = max(solve(), solve2());
    cout << ans << endl;
    return 0;
}
