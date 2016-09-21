#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<int> graph[100005];
long long v[100005];
int visited[100005];
long long a[100005];
long long b[100005];

void dfs(int u = 0) {
    visited[u] = true;
    long long inc = 0, dec = 0;
    if (v[u] < 0) inc = -v[u];
    else dec = v[u];
    for (int i = 0; i < graph[u].size(); i++) {
        if (!visited[graph[u][i]]) {
            dfs(graph[u][i]);
            inc = max(inc, a[graph[u][i]]);
            dec = max(dec, b[graph[u][i]]);
        }
    }
    v[u] += inc - dec;
    if (v[u] < 0) inc += -v[u];
    else dec += v[u];
    a[u] = inc;
    b[u] = dec;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }
    for (int i = 0; i < n; i++) cin >> v[i];
    dfs();
    long long ans = a[0] + b[0];
    cout << ans << endl;
    return 0;
}
