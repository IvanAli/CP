#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
int a[300005];
int M[300005][25];
int G[300005][25];
int lg[1000005];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int minquery(int l, int r) {
    // int k = lg[r - l + 1];
    int k = 0;
    while ((1 << k) <= r - l + 1) k++;
    k--;
    return min(M[l][k], M[r - (1 << k) + 1][k]);
}

int gcdquery(int l, int r) {
    // int k = lg[r - l + 1];
    int k = 0;
    while ((1 << k) <= r - l + 1) k++;
    k--;
    return gcd(G[l][k], G[r - (1 << k) + 1][k]);
}

bool ok(int sz) {
    for (int i = 0; i + sz < n; i++) {
        if (minquery(i, i + sz) == gcdquery(i, i + sz)) return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++) {
        M[i][0] = a[i];
        G[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            int x, y;
            x = M[i][j - 1], y = M[i + (1 << (j - 1))][j - 1];
            M[i][j] = min(x, y);
            x = G[i][j - 1], y = G[i + (1 << (j - 1))][j - 1];
            G[i][j] = gcd(x, y);
        }
    }
    int low = 0, high = n;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (ok(mid)) low = mid;
        else high = mid;
    }
    vector<int> ans;
    for (int i = 0; i + low < n; i++) {
        if (minquery(i, i + low) == gcdquery(i, i + low)) ans.pb(i);
    }
    cout << ans.size() << " " << low << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
    cout << endl;
    return 0;
}
