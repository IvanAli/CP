#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

int t, k, a, b;
ll dp[100005];
ll f[100005];

int main() {
    cin >> t >> k;
    dp[0] = 1L;
    f[0] = 1L;
    for (int i = 1; i <= 100000; i++) {
        if (i < k) dp[i] = 1L;
        else dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
        f[i] = (dp[i] + f[i - 1]) % MOD;
    }
    while (t--) {
        cin >> a >> b;
        cout << abs(f[b] - f[a - 1] + MOD) % MOD << endl;
    }
    return 0;
}
