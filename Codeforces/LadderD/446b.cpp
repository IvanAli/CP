#include <bits/stdc++.h>
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define INF 1e18
using namespace std;

int grid[1005][1005];
long long n, m, k, p;
long long x;
vector<int> row, col;

vector<long long> solve(vector<int> a, int x) {
    priority_queue<long long> pq;
    vector<long long> ret;
    for (int i = 0; i < a.size(); i++) pq.push(a[i]);
    ret.pb(0);
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        long long top = pq.top();
        pq.pop();
        sum += top;
        pq.push(top - p * x);
        ret.pb(sum);
    }
    return ret;
}

int main() {
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) sum += grid[i][j];
        row.pb(sum);
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += grid[j][i];
        col.pb(sum);
    }
    vector<long long> ansrow, anscol;
    ansrow = solve(row, m);
    anscol = solve(col, n);
    long long ans = -INF;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, ansrow[i] + anscol[k - i] - i * (k - i) * p);
    }
    cout << ans << endl;
    return 0;
}
