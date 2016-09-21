#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
int a[100005];

bool ok(int aa, int bb) {
    if ((aa + bb) % 2) {
        for (int i = 0; i < n; i++) if (a[i] != aa && a[i] != bb) return false;
    } else {
        int cc = (aa + bb) >> 1;
        for (int i = 0; i < n; i++) if (a[i] != aa && a[i] != bb && a[i] != cc) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int mmin = INF;
    int mmax = 0;
    for (int i = 0; i < n; i++) {
        mmin = min(mmin, a[i]);
        mmax = max(mmax, a[i]);
    }
    if (ok(mmin, mmax)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
