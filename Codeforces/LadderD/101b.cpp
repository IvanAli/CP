#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, m;
struct stop {
    int s, t;
    bool operator< (const stop& sto) const {
        return t < sto.t;
    }
} st[100005];
int dp[200005];
int sum[200005];
int cnt;
map<int, int> ma;

static int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
static int sub(int a, int b) { return a - b >= 0  ? a - b : a - b + mod ; }

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> st[i].s >> st[i].t;
    // ma[0] = ma[n] = 0;
    for (int i = 0; i < m; i++) ma[st[i].s] = ma[st[i].t] = 0;
    for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) it->second = cnt++;
    for (int i = 0; i < m; i++) st[i].s = ma[st[i].s], st[i].t = ma[st[i].t];
    if (!ma.count(0) || !ma.count(n)) {
        cout << 0 << endl;
        return 0;
    }
    sort(st, st + m);
    dp[0] = 1;
    for (int i = 0, j = 0; i < cnt; i++) {
        while (j < m && st[j].t == i) {
            // dp[i] = (dp[i] + ((sum[i] - sum[st[j].s] + mod) % mod)) % mod;
            dp[i] = add(dp[i], sub(sum[i], sum[st[j].s]));
            j++;
        }
        // sum[i + 1] = (sum[i] + dp[i]) % mod;
        sum[i + 1] = add(sum[i], dp[i]);
    }
    cout << dp[cnt - 1] << endl;
    return 0;
}
