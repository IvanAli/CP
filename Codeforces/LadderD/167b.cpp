#include <bits/stdc++.h>
using namespace std;

int n, l, k;
int p[205];
int a[205];
double memo[205][410][205];

double solve(int i = 0, int w = k, int v = 0) {
    double ret;
    w = min(w, 205);
    if (i == n) {
        if (v < l) return 0;
        return (w < 0 ? 0 : 1);
    }
    if (memo[i][w + 205][v] > -0.5) return memo[i][w + 205][v];
    ret = p[i] * solve(i + 1, w + a[i], v + 1) + (100 - p[i]) * solve(i + 1, w, v);
    ret *= 0.01;
    return memo[i][w + 205][v] = ret;
}

int main() {
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(memo, -1, sizeof memo);
    double ans = solve();
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
