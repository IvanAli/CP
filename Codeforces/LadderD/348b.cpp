#include <bits/stdc++.h>
#define INF 1e18
#define pb push_back
using namespace std;

int n;
long long a[100005];
vector<int> tree[100005];
long long d[100005];
long long all;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void dfs(int u = 0, int from = 0) {
    long long mn = INF;
    int sz = 0;
    d[u] = 1;
    long long mult = 1;
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (from != v) {
            dfs(v, u);
            mn = min(mn, a[v]);
            mult = lcm(mult, d[v]);
            if (mult > mn) {
                cout << all << endl;
                exit(0);
            }
            sz++;
        }
    }
    if (sz) d[u] = mult * sz;
    else d[u] = 1;
    if (sz) a[u] = (mn / mult) * mult * sz;
    if (a[u] == 0) {
        cout << all << endl;
        exit(0);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all += a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs();
    cout << all - a[0] << endl;
    return 0;
}
