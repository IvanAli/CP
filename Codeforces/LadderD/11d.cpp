#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m;
vector<int> graph[20];
long long dp[1 << 19][19];
int lg[1000005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
    for (int i = 2; i < 1000000; i++) lg[i] = lg[i >> 1] + 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) > 1) {
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) && i != lg[mask & (-mask)]) {
                    for (int j = 0; j < graph[i].size(); j++) {
                        if ((mask >> graph[i][j]) & 1) dp[mask][i] += dp[mask ^ (1 << i)][graph[i][j]];
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) >= 3) {
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    for (int j = 0; j < graph[i].size(); j++) {
                        if (graph[i][j] == lg[mask & (-mask)]) {
                            ans += dp[mask][i];
                            break;
                        }
                    }
                }
            }
        }
    }
    ans >>= 1;
    cout << ans << endl;
    return 0;
}
