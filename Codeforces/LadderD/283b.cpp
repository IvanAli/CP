#include <bits/stdc++.h>
#define INF 1e12
using namespace std;

int n;
long long a[200005];
int visited[200005][2];
long long memo[200005][2];

long long solve(int i, int j) {
    if (i < 0 || i >= n) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    if (visited[i][j] == 0) visited[i][j] = 1;
    else if (visited[i][j] == 1) return memo[i][j] = INF;
    long long ret = a[i] + solve(j ? i + a[i] : i - a[i], 1 - j);
    return memo[i][j] = ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> a[i + 1];
    memset(memo, -1, sizeof memo);
    long long ans;
    for (int i = 0; i < n - 1; i++) {
        // for (int j = 0; j < n; j++) visited[j] = 0;
        visited[0][1] = true;
        ans = solve(i + 1, 0);
        if (ans >= INF) cout << -1 << endl;
        else cout << ans + i + 1 << endl;
    }
    return 0;
}
