#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[1005][1005];
int dp1[1005][1005];
int dp2[1005][1005];
int dp3[1005][1005];
int dp4[1005][1005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp1[i][j] = grid[i][j] + max(i ? dp1[i - 1][j] : 0, j ? dp1[i][j - 1] : 0);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp2[i][j] = grid[i][j] + max(i < n - 1 ? dp2[i + 1][j] : 0, j < m - 1 ? dp2[i][j + 1] : 0);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            dp3[i][j] = grid[i][j] + max(i < n - 1 ? dp3[i + 1][j] : 0, j ? dp3[i][j - 1] : 0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            dp4[i][j] = grid[i][j] + max(i ? dp4[i - 1][j] : 0, j < m - 1 ? dp4[i][j + 1] : 0);
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++) {
        ans = max(ans, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
        ans = max(ans, dp1[i][j - 1] + dp2[i][j + 1] + dp4[i - 1][j] + dp3[i + 1][j]);
    }
    cout << ans << endl;
    return 0;
}
