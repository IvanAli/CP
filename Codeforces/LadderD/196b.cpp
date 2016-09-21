#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[3005][3005];
int visited[3005][3005];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

bool dfs(int r, int c, int fr, int fc) {
    if (visited[r][c]) return false;
    if (grid[r][c] == '#') return false;
    if (r != fr || c != fc) if (grid[r][c] == 'S') return true;
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0) rr += 2 * n;
        if (cc < 0) cc += 2 * m;
        if (rr >= 2 * n) rr -= 2 * n;
        if (cc >= 2 * m) cc -= 2 * m;
        if (rr == fr && cc == fc) continue;
        if (dfs(rr, cc, r, c)) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
            grid[i + n][j] = s[j];
            grid[i][j + m] = s[j];
            grid[i + n][j + m] = s[j];
        }
    }
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m * 2; j++) {
            if (grid[i][j] == 'S') {
                if (dfs(i, j, i, j)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
