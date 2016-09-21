#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
int b[200005];
int MA[200005][20];
int MB[200005][20];
int lg[200005];

int mx(int l, int r) {
    int k = lg[r - l + 1];
    return max(a[MA[l][k]], a[MA[r - (1 << k) + 1][k]]);
}

int mn(int l, int r) {
    int k = lg[r - l + 1];
    return min(b[MB[l][k]], b[MB[r - (1 << k) + 1][k]]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) MA[i][0] = i, MB[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            int ii = MA[i][j - 1], jj = MA[i + (1 << (j - 1))][j - 1];
            if (a[ii] > a[jj]) MA[i][j] = ii;
            else MA[i][j] = jj;
            ii = MB[i][j - 1], jj = MB[i + (1 << (j - 1))][j - 1];
            if (b[ii] < b[jj]) MB[i][j] = ii;
            else MB[i][j] = jj;
        }
    }
    for (int i = 2; i < n; i++) lg[i] = lg[i / 2] + 1;
    long long ans = 0;
    int low, high, mid;
    for (int i = 0; i < n; i++) {
        int x, y;
        low = i, high = n;
        while (low < high) {
            mid = (low + high) / 2;
            if (mx(i, mid) >= mn(i, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        x = low;
        low = x, high = n;
        while (low < high) {
            mid = (low + high) / 2;
            if (mx(i, mid) > mn(i, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        y = low;
        ans += y - x;
    }
    cout << ans << endl;
    return 0;
}
