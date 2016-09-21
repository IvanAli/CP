#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, h;
int a[100005], p[100005], p2[100005];

bool cmp(const int i, const int j) {
    return a[i] < a[j];
}

int main() {
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> a[i], p[i] = i, p2[i] = i;
    int ans = INF;
    sort(p, p + n, cmp);
    ans = min(ans, a[p[n - 1]] + a[p[n - 2]] - a[p[1]] - a[p[0]]);
    a[p[0]] += h;
    sort(p2, p2 + n, cmp);
    int sol = a[p2[n - 1]] + a[p2[n - 2]] - a[p2[1]] - a[p2[0]];
    if (sol < ans) {
        ans = sol;
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            if (i == p[0]) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    } else {
        cout << ans << endl;
        for (int i = 0; i < n; i++) cout << 2 << " ";
        cout << endl;
    }
    return 0;
}
