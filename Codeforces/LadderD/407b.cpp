#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];
const int mod = 1000000007;
unsigned long long dp[2005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    dp[1] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        if (i % 2 == 0) dp[i] = (dp[i - 1] + 1) % mod;
        else dp[i] = ((dp[i - 1] + dp[i - 2]) - dp[p[i / 2] * 2] + 2 + mod) % mod;
    }
    int ans = dp[2 * n];
    cout << ans << endl;
}
