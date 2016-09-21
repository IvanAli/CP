#include <bits/stdc++.h>
#define pb push_back
#define INF 1e9
using namespace std;

int n, m, d;
int p[100005];
vector<int> tree[100005];
int down[100005];
int up[100005];
int max1[100005];
int max2[100005];

void dfs1(int u = 0, int from = 0) {
    for (int i = 0; i < tree[u].size(); i++) {
        int to = tree[u][i];
        if (to == from) continue;
        dfs1(to, u);
        down[u] = max(down[u], down[to] + 1);
        if (max1[u] < down[to]) {
            max2[u] = max1[u];
            max1[u] = down[to];
        } else max2[u] = max(max2[u], down[to]);
    }
}

void dfs2(int u = 0, int from = 0) {
    if (u != from) {
        if (down[u] < max1[from]) up[u] = max(up[u], max1[from] + 2);
        else up[u] = max(up[u], max2[from] + 2);
        up[u] = max(up[u], up[from] + 1);
    }
    for (int i = 0; i < tree[u].size(); i++) {
        int to = tree[u][i];
        if (to == from) continue;
        dfs2(to, u);
    }
}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a - 1].pb(b - 1);
        tree[b - 1].pb(a - 1);
    }
    for (int i = 0; i < n; i++) up[i] = down[i] = max1[i] = max2[i] = -INF;
    for (int i = 0; i < m; i++) up[p[i]] = down[p[i]] = 0;
    dfs1();
    dfs2();
    int ans = 0;
    for (int i = 0; i < n; i++) if (down[i] <= d && up[i] <= d) ans++;
    cout << ans << endl;
}
