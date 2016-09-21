#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
    cin >> n >> m;
    if (n == 1) cout << m << endl;
    else if (m == 1) cout << n << endl;
    else if (n == 2) {
        long long ans = (4 * (m / 4));
        if (m % 4) ans += 2;
        if (m % 4 > 1) ans += 2;
        cout << ans << endl;
    }
    else if (m == 2) {
        long long ans = (4 * (n / 4));
        if (n % 4) ans += 2;
        if (n % 4 > 1) ans += 2;
        cout << ans << endl;
    }
    else cout << (n * m + 1) / 2 << endl;
    return 0;
}
