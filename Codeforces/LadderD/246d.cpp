#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> graph[100005];
int c[100005];
int a, b;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        if (c[a] == c[b]) continue;
        graph[c[a]].insert(c[b]);
        graph[c[b]].insert(c[a]);
    }
    int ans = 100005;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (graph[c[i]].size() >= mx) {
            if (graph[c[i]].size() > mx) ans = c[i];
            else ans = min(ans, c[i]);
            mx = graph[c[i]].size();
        }
    }
    cout << ans << endl;
}
