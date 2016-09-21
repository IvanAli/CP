#include <bits/stdc++.h>
using namespace std;

int n, m;
int row[1005];
int col[1005];
string s;
bool grid[1005][1005];

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                row[i]++, col[j]++, cnt++;
                grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (row[i] + col[j] == cnt + grid[i][j]) {
            cout << "YES" << endl;
            cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
