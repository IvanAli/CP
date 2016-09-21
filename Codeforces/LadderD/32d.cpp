#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, k;
char grid[305][305];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct star {
    int r, cr, cc;
    star() {}
    star(int r, int cr, int cc) : r(r), cr(cr), cc(cc) {}
    bool operator<(const star& s) const {
        if (r == s.r) {
            if (cr == s.cr) return cc > s.cc;
            return cr > s.cr;
        }
        return r > s.r;
    }
};

bool ok(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return false;
    if (grid[r][c] == '*') return true;
    return false;
}

bool allok(int r, int c, int rad) {
    if (!ok(r, c)) return false;
    for (int i = 0; i < 4; i++) {
        if (!ok(r + dr[i] * rad, c + dc[i] * rad)) return false;
    }
    return true;
}

vector<int> get(int r, int c) {
    vector<int> ret;
    int sz = min(r, n - r - 1);
    sz = min(sz, c);
    sz = min(sz, m - c - 1);
    for (int i = 1; i <= sz; i++) {
        if (allok(r, c, i)) ret.pb(i);
    }
    return ret;
}

int main() {
    cin >> n >> m >> k;
    priority_queue<star> pq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = s[j];
    }
    int rr, cc;
    int rad = 0;
    while (k) {
        rad++;
        if (rad > min(n / 2, m / 2)) return cout << -1 << endl, 0;
        for (int i = 0; k && i < n; i++) for (int j = 0; k && j < m; j++) {
            if (allok(i, j, rad)) k--, rr = i, cc = j;
        }
    }
    cout << rr + 1 << " " << cc + 1 << endl;
    for (int i = 0; i < 4; i++) cout << rr + 1 + dr[i] * rad << " " << cc + 1 + dc[i] * rad << endl;
    return 0;
}
