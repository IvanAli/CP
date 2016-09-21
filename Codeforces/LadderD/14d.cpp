#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

int n;
vector<int> graph[205];
int memo[205][205];
int memo2[205][205];

int get(int u, int from) {
    int ret = 0;
    if (memo2[u][from] != -1) return memo2[u][from];
    for (int i = 0; i < graph[u].size(); i++) {
        int to = graph[u][i];
        if (to == from) continue;
        ret = max(ret, get(to, u) + 1);
    }
    return memo2[u][from] = ret;
}

int solve(int u, int from) {
    int ret = 0;
    int d1 = 0, d2 = 0;
    if (memo[u][from] != -1) return memo[u][from];
    for (int i = 0; i < graph[u].size(); i++) {
        int to = graph[u][i];
        if (to == from) continue;
        int res = 1 + get(to, u);
        if (d1 < res) {
            d2 = d1;
            d1 = res;
        } else d2 = max(d2, res);
        ret = max(ret, solve(to, u));
    }
    ret = max(ret, d1 + d2);
    return memo[u][from] = ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    memset(memo, -1, sizeof memo);
    memset(memo2, -1, sizeof memo2);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int a = solve(i, graph[i][j]);
            int b = solve(graph[i][j], i);
            ans = max(ans, a * b);
        }
    }
    cout << ans << endl;
    return 0;
}
