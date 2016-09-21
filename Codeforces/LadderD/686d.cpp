#include <bits/stdc++.h>
using namespace std;

int n, q, v;
int p[300005];
int size[300005];
int big[300005];
int centroid[300005];
vector<int> graph[300005];

void calc(int u = 1) {
    int ans = 0;
    size[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        calc(v);
        size[u] += size[v];
        big[u] = max(big[u], size[v]);
    }
}

bool ok(int u, int v) {
    return ((size[u] - size[v]) * 2 <= size[u]) && (big[v] * 2 <= size[u]);
}

void cent(int u = 1) {
    if (size[u] == 1) {
        centroid[u] = u;
        return;
    }
    int good = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        cent(v);
        if (size[v] > size[good]) good = v;
    }
    int c = centroid[good];
    while (!ok(u, c)) c = p[c];
    centroid[u] = c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    int x;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        p[i + 2] = x;
        graph[x].push_back(i + 2);
    }
    calc();
    cent();
    for (int i = 0; i < q; i++) {
        cin >> v;
        cout << centroid[v] << endl;
    }
}
