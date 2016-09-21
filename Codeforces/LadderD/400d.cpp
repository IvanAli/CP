#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
using namespace std;

typedef pair<int, int> ii;
int n, m, k;
int c[505];
int cc[505];
int type[100005];
vector<ii> graph[100005];
vector<int> graph2[100005];
int mat[505][505];
int visited[100005];
map<int, int> hash;

void dfs(int u) {
    visited[u] = true;
    hash[type[u]]++;
    for (int i = 0; i < graph2[u].size(); i++) {
        int v = graph2[u][i];
        if (!visited[v]) dfs(v);
    }
}

bool ok() {
    for (map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
        if (it->second != c[it->first]) return false;
    }
    return true;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) mat[i][j] = INF;
    for (int i = 0; i < k; i++) cin >> c[i];
    for (int i = 0; i < k; i++) cc[i] = c[i] + (i ? cc[i - 1] : 0);
    for (int i = 0, j = 0; i < n; i++) {
        while (cc[j] <= i) j++;
        type[i] = j;
    }
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        int tu = type[u], tv = type[v];
        if (tu != tv) {
            mat[tu][tv] = min(mat[tu][tv], x);
            mat[tv][tu] = min(mat[tv][tu], x);
        }
        graph[u].pb(ii(v, x));
        graph[v].pb(ii(u, x));
        if (x == 0) {
            graph2[u].pb(v);
            graph2[v].pb(u);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            if (!ok()) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < k; i++) mat[i][i] = 0;
    for (int p = 0; p < k; p++) for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) {
        mat[i][j] = min(mat[i][j], mat[i][p] + mat[p][j]);
    }
    cout << "Yes" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) cout << (mat[i][j] >= INF ? -1 : mat[i][j]) << " ";
        cout << endl;
    }
    return 0;
}
