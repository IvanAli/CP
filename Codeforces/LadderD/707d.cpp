#include <bits/stdc++.h>
using namespace std;

int last[100005][1005];
bool lines[100005][1005];
int sum[100005];
int n, m, q;
int cnt;

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++) {
        sum[i] = sum[i - 1];
        for (int j = 0; j < n; j++) last[i][j] = last[i - 1][j];
        int c, x, y;
        cin >> c;
        if (c == 1) {
            cin >> x >> y;
            x--, y--;
            if (lines[last[i][x]][y] == 0) {
                cnt++;
                for (int j = 0; j < m; j++) lines[cnt][j] = lines[last[i][x]][j];
                lines[cnt][y] = 1;
                last[i][x] = cnt;
                sum[i]++;
            }
        } else if (c == 2) {
            cin >> x >> y;
            x--, y--;
            if (lines[last[i][x]][y] == 1) {
                cnt++;
                for (int j = 0; j < m; j++) lines[cnt][j] = lines[last[i][x]][j];
                lines[cnt][y] = 0;
                last[i][x] = cnt;
                sum[i]--;
            }
        } else if (c == 3) {
            cin >> x;
            x--;
            int s = 0;
            cnt++;
            for (int j = 0; j < m; j++) s += lines[last[i][x]][j], lines[cnt][j] = !lines[last[i][x]][j];
            last[i][x] = cnt;
            sum[i] = sum[i] - s + m - s;
        } else if (c == 4) {
            cin >> x;
            for (int j = 0; j < n; j++) last[i][j] = last[x][j];
            sum[i] = sum[x];
        }
        cout << sum[i] << endl;
    }
    return 0;
}
