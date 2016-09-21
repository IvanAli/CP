#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m;
int s[5005];
double x[5005];
int dp[5005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i] >> x[i], s[i]--;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (s[j] <= s[i]) mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << n - ans << endl;
}
