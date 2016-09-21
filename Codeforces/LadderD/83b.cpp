#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[100005];

int main() {
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    if (sum < k) {
        cout << -1 << endl;
        return 0;
    }
    long long low = 0, high = (int)1e9, mid, x;
    while (low < high) {
        sum = 0;
        mid = (low + high + 1) >> 1;
        for (int i = 0; i < n; i++) sum += min(a[i], mid);
        if (sum <= k) low = mid;
        else high = mid - 1;
    }
    for (int i = 0; i < n; i++) k -= min(a[i], low);
    for (int i = 0; i < n; i++) {
        if (k == 0) {
            for (int j = 0; j < n; j++) cerr << a[j] << " ";
            cerr << endl;
            for (int j = 0; j < n; j++) {
                if (a[(i + j) % n] > low) cout << (i + j) % n + 1 << " ";
            }
            cout << endl;
            return 0;
        }
        if (a[i] > low) {
            a[i]--;
            k--;
        }
    }
    return 0;
}
