#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int ma[100005][20];
int lg[100005];

int mn(int l, int r) {
    int k = lg[r - l + 1];
    int x = ma[l][k], y = ma[r - (1 << k) + 1][k];
    return min(a[x], a[y]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) ma[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            int x = ma[i][j - 1], y = ma[i + (1 << (j - 1))][j - 1];
            if (a[x] < a[y]) ma[i][j] = x;
            else ma[i][j] = y;
        }
    }
    for (int i = 2; i < n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++) {
        int low = i, high = n - 1, mid;
        while (low < high) {
            mid = (low + high + 1) >> 1;
            if (mn(mid, n - 1) < a[i]) low = mid;
            else high = mid - 1;
        }
        cout << low - i - 1 << " ";
    }
    cout << endl;
    return 0;
}
