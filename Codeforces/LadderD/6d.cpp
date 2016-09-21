#include <bits/stdc++.h>
#define INF 300
using namespace std;

int n, a, b;
int h[15];
int memo[15][20][20];
int path[15][20][20];

int solve(int p = 1, int prevhp = h[0], int currhp = h[1]) {
    if (p == n - 1) {
        return prevhp + currhp == 0 ? 0 : INF;
    }
    int ret = INF;
    if (memo[p][prevhp][currhp] != -1) return memo[p][prevhp][currhp];
    for (int i = 0; i <= 16; i++) {
        if (prevhp - b * i <= 0) {
            int sol = i + solve(p + 1, max(0, currhp - i * a), max(0, h[p + 1] - i * b));
            if (sol < ret) {
                ret = sol;
                path[p][prevhp][currhp] = i;
            }
        }
    }
    return memo[p][prevhp][currhp] = ret;
}

void build(int p = 1, int prevhp = h[0], int currhp = h[1]) {
    while (p < n) {
        int t = path[p][prevhp][currhp];
        for (int i = 0; i < t; i++) {
            cout << p + 1 << " ";
        }
        p++;
        prevhp = max(0, currhp - t * a);
        currhp = max(0, h[p] - t * b);
    }
    cout << endl;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> h[i], h[i]++;
    memset(memo, -1, sizeof memo);
    int ans = solve();
    cout << ans << endl;
    build();
    return 0;
}
