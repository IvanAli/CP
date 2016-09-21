#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int n, m;
int a, b;
vector<int> graph[3005];
int in[3005];

long long bfs(int s) {
    queue<int> q;
    int dist[3005];
    int deg[3005];
    for (int i = 0; i < n; i++) dist[i] = deg[i] = 0;
    for (int i = 0; i < graph[s].size(); i++) {
        int u = graph[s][i];
        for (int j = 0; j < graph[u].size(); j++) {
            int v = graph[u][j];
            deg[v]++;
        }
    }
    long long ret = 0;
    deg[s] = 0;
    for (int i = 0; i < n; i++) ret += (deg[i] * (deg[i] - 1)) >> 1LL;
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bfs(i);
    }
    cout << ans << endl;
    return 0;
}
