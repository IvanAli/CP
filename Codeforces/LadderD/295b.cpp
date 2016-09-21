#include <bits/stdc++.h>
#define INF 1e11
using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;

int n;
long long graph[505][505];
long long ans[505];
int x[505];

void floyd() {
    vvi ret = vvi(n, vi(n, INF));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        ret[i][j] = graph[i][j];
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            ret[i][j] = min(ret[i][j], ret[i][x[k]] + ret[x[k]][j]);
        }
        for (int i = 0; i < k + 1; i++) for (int j = 0; j < k + 1; j++) ans[n - k - 1] += ret[x[i]][x[j]];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> graph[i][j];
    for (int i = 0; i < n; i++) cin >> x[i], x[i]--;
    reverse(x, x + n);
    floyd();
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
