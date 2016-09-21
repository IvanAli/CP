#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int dist[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n + 1; i++) dist[i] = -1;
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }
        if (u + 1 < n && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }
        if (dist[a[u]] == -1) {
            dist[a[u]] = dist[u] + 1;
            q.push(a[u]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << dist[i];
    }
    cout << endl;
}
