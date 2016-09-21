#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int grid[1005][1005];
char dir[100005];
int dr[100005];
int dc[100005];
int len[100005];
string ans;
int row[1005][1005];
int col[1005][1005];

bool ok(int r, int c) {
    for (int i = 0; i < k; i++) {
        if (r + dr[i] <= 0 || r + dr[i] >= n - 1) return false;
        if (c + dc[i] <= 0 || c + dc[i] >= m - 1) return false;
        if (dr[i] < 0) {
            if (col[c][r] - col[c][r + dr[i] - 1] > 0) return false;
        } else {
            if (col[c][r + dr[i]] - col[c][r - 1] > 0) return false;
        }
        if (dc[i] < 0) {
            if (row[r][c] - row[r][c + dc[i] - 1] > 0) return false;
        } else {
            if (row[r][c + dc[i]] - row[r][c - 1] > 0) return false;
        }
        r += dr[i];
        c += dc[i];
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = s[j];
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        row[i][j] += j ? row[i][j - 1] : 0;
        if (grid[i][j] == '#') row[i][j]++;
    }
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        col[i][j] += j ? col[i][j - 1] : 0;
        if (grid[j][i] == '#') col[i][j]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> dir[i] >> len[i];
        if (dir[i] == 'N') dr[i] = -len[i];
        if (dir[i] == 'S') dr[i] = len[i];
        if (dir[i] == 'W') dc[i] = -len[i];
        if (dir[i] == 'E') dc[i] = len[i];
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
            if (ok(i, j)) ans += grid[i][j];
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size()) cout << ans << endl;
    else cout << "no solution" << endl;
}
