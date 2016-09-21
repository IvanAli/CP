#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, x;
int c[105];
int v[105];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) v[i] = c[i] * (n - i);
    sort(v, v + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= v[i]) ans++, x-= v[i];
        else break;
    }
    cout << ans << endl;
    return 0;
}
