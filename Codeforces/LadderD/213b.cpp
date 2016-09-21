#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n;
int a[10];
long long c[105][105];
long long dp[105][10];

int main() {
    cin >> n;
    for (int i = 0; i < 10; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) c[i][i] = 1;
    for (int i = 0; i <= n; i++) c[i][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    for (int i = 0; i <= n; i++) dp[i][9] = (i >= a[9]);
    for (int i = 0; i <= n; i++) {
        for (int j = 8; j > 0; j--) {
            for (int k = a[j]; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i - k][j + 1] * c[i][k]) % mod;
            }
        }
        for (int k = a[0]; k <= i; k++) dp[i][0] = (dp[i][0] + dp[i - k][1] * c[i - 1][k]) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + dp[i][0]) % mod;
    cout << ans << endl;
}
