#include <bits/stdc++.h>
#define pb push_back
#define INF 1e9
using namespace std;

string s1, s2, virus;
int f[105];
int memo[105][105][105];

void failure(string p) {
    for (int i = 2; i <= p.size(); i++) {
        int j = f[i - 1];
        while (true) {
            if (p[j] == p[i - 1]) {
                f[i] = j + 1;
                break;
            } else if (j == 0) break;
            j = f[j];
        }
    }
}

int solve(int i = 0, int j = 0, int k = 0) {
    if (k == virus.size()) return -INF;
    if (i == s1.size() || j == s2.size()) return 0;
    if (memo[i][j][k] != -1) return memo[i][j][k];
    int ret = 0;
    ret = max(ret, max(solve(i + 1, j, k), solve(i, j + 1, k)));
    if (s1[i] == s2[j]) {
        int kk = k;
        while (true) {
            if (s1[i] == virus[kk]) {
                ret = max(ret, 1 + solve(i + 1, j + 1, kk + 1));
                break;
            } else if (kk > 0) kk = f[kk];
            else {
                ret = max(ret, 1 + solve(i + 1, j + 1, 0));
                break;
            }
        }
    }
    return memo[i][j][k] = ret;
}



void print(int i = 0, int j = 0, int k = 0) {
    if (k == virus.size()) return;
    if (i == s1.size() || j == s2.size()) return;
    if (memo[i][j][k] == memo[i + 1][j][k]) print(i + 1, j, k);
    else if (memo[i][j][k] == memo[i][j + 1][k]) print(i, j + 1, k);
    else {
        f[0] = -1;
        int kk = k;
        while (kk >= 0 && s1[i] != virus[kk]) kk = f[kk];
        kk++;
        if (s1[i] == s2[j]) cout << s1[i];
        else return;
        print(i + 1, j + 1, kk);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s1 >> s2 >> virus;
    memset(memo, -1, sizeof memo);
    failure(virus);
    int ans = solve();
    if (ans) {
        print();
        cout << endl;
    } else cout << 0 << endl;
    return 0;
}
