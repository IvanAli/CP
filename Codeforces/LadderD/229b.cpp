#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e18
using namespace std;

typedef pair<long long, int> ii;

int n, m;
vector<ii> graph[100005];
vector<long long> vt[100005];
long long dist[100005];

void dijkstra() {
    for (int i = 0; i < n; i++) dist[i] = INF;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist[0] = 0;
    pq.push(mp(0, 0));
    while (!pq.empty()) {
        ii top = pq.top();
        pq.pop();
        int u = top.snd;
        long long d = top.fst;
        if (d > dist[u]) continue;
        if (u == n - 1) break;
        if (dist[u] == INF) break;
        int add = 0;
        for (int j = 0; j < vt[u].size(); j++) {
            if (vt[u][j] == dist[u] + add) add++;
        }
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].fst, d = graph[u][i].snd;
            if (dist[u] + d + add < dist[v]) {
                dist[v] = dist[u] + d + add;
                pq.push(mp(dist[v], v));
            }
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(0);
    scanf("%d %d", &n, &m);
    // cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        // cin >> a >> b >> c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }
    for (int i = 0; i < n; i++) {
        int k;
        // cin >> k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            vt[i].pb(x);
        }
    }
    dijkstra();
    if (dist[n - 1] >= INF) cout << -1 << endl;
    else cout << dist[n - 1] << endl;
    return 0;
}
