#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

long long cnt(long long x) {
    long long ret = 0;
    for (long long i = 0; i < n; i++) ret += min(((x - 1) / (i + 1)), m);
    return ret;
}

int main() {
    cin >> n >> m >> k;
    long long low = 1, high = n * m + 1LL, mid;
    long long ans = 0;
    while (low < high) {
        mid = (low + high) / 2;
        long long res = cnt(mid);
        if (res < k) low = mid + 1;
        else high = mid;
    }
    if (ans == 0) ans = low - 1;
    cout << ans << endl;
}
