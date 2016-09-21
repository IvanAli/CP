#include <bits/stdc++.h>
using namespace std;

long long l, r;
string s1, s2;
long long memo[65][2][2][2][2];

string tobin(long long n) {
    string ret = "";
    for (long long i = 1; i <= n; i *= 2) {
        if (n & i) ret = "1" + ret;
        else ret = "0" + ret;
    }
    return ret;
}

int todigit(char c) {
    return c - '0';
}

long long solve(int i = 0, bool al = 0, bool ar = 0, bool bl = 0, bool br = 0) {
    if (i == s2.size()) return 0;
    if (memo[i][al][ar][bl][br] != -1) return memo[i][al][ar][bl][br];
    long long ret = 0;
    int a = 0, b = 0, aa = 1, bb = 1;
    if (todigit(s1[i]) == 1 && al == 0) a = 1;
    if (todigit(s2[i]) == 0 && ar == 0) aa = 0;
    if (todigit(s1[i]) == 1 && bl == 0) b = 1;
    if (todigit(s2[i]) == 0 && br == 0) bb = 0;
    for (int ii = a; ii <= aa; ii++) {
        for (int jj = b; jj <= bb; jj++) {
            int x = (ii ^ jj);
            long long add = 0;
            if (x) add = 1LL << (s2.size() - i - 1);
            ret = max(ret, add + solve(i + 1, al || ii > todigit(s1[i]), ar || ii < todigit(s2[i]), bl || jj > todigit(s1[i]), br || jj < todigit(s2[i])));
        }
    }
    return memo[i][al][ar][bl][br] = ret;
}

int main() {
    cin >> l >> r;
    s1 = tobin(l);
    s2 = tobin(r);
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < s2.size() - s1.size(); i++) s1 = "0" + s1;
    long long ans = solve();
    cout << ans << endl;
    return 0;
}
