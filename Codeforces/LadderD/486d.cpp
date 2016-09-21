#include <bits/stdc++.h>
#define INF 1e9
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;
int d, n;
int a[2005];
vector<int> graph[2005];
int visited[2005];
long long dp[2005];

void dfs(int u, int root) {
    visited[u] = 1;
    dp[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            if (a[root] <= a[v] && a[v] <= a[root] + d) {
                if (v < root && a[root] == a[v]) continue;
                dfs(v, root);
                dp[u] = (dp[u] * (dp[v] + 1LL)) % mod;
            }
        }
    }
}

int main() {
    cin >> d >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[j] = 0;
            dp[j] = 0;
        }
        dfs(i, i);
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
}
