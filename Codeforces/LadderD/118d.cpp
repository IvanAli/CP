#include <bits/stdc++.h>
using namespace std;

const int mod = 100000000;

int n1, n2, k1, k2;
int memo[105][105][15][15];

int solve(int n1, int n2, int kk1, int kk2) {
    if (kk1 < 0) return 0;
    if (kk2 < 0) return 0;
    if (n1 + n2 == 0) return 1;
    int ret = 0;
    if (memo[n1][n2][kk1][kk2] != -1) return memo[n1][n2][kk1][kk2];
    if (n1) ret = (ret + solve(n1 - 1, n2, kk1 - 1, k2)) % mod;
    if (n2) ret = (ret + solve(n1, n2 - 1, k1, kk2 - 1)) % mod;
    return memo[n1][n2][kk1][kk2] = ret;
}

int main() {
    cin >> n1 >> n2 >> k1 >> k2;
    memset(memo, -1, sizeof memo);
    int ans = solve(n1, n2, k1, k2);
    cout << ans << endl;
    return 0;
}
