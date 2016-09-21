#include <bits/stdc++.h>
using namespace std;

int n, h;
long long dp[40][40];

int main() {
    cin >> n >> h;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                for (int l = 0; l < j; l++) dp[i][j] += dp[k - 1][j - 1] * dp[i - k][l];
                for (int l = 0; l < j - 1; l++) dp[i][j] += dp[k - 1][l] * dp[i - k][j - 1];
            }
        }
    }
    long long ans = 0;
    for (int i = h; i <= n; i++) ans += dp[n][i];
    cout << ans << endl;
    return 0;
}
