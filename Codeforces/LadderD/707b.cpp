#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define fst first
#define snd second
using namespace std;

typedef pair<long long, long long> ii;

int n, m, k;
vector<pair<long long, long long> > graph[100005];
int a[100005];
long long dist[100005];
set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;
        graph[u].pb(mp(v, l));
        graph[v].pb(mp(u, l));
    }
    if (k) for (int i = 0; i < k; i++) cin >> a[i], a[i]--, s.insert(a[i]);
    else {
        cout << -1 << endl;
        return 0;
    }
    long long ans = INF;
    for (int t = 0; t < k; t++) {
        int u = a[t];
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].fst;
            long long d = graph[u][i].snd;
            if (s.count(v)) continue;
            ans = min(ans, d);
        }
    }
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
