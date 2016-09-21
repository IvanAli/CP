#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int n, k;
int dp[2005][2005];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 2; j <= k; j++) {
            for (int x = i; x <= n; x += i) {
                if (x % i == 0)
                    dp[i][j] = (dp[i][j] + dp[x][j - 1]) % mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[i][k]) % mod;
    cout << ans << endl;
    return 0;
}
