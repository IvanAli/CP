#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
string s, t;
int f[100005];
int g[100005];
int a[100005];
int q1[100005], q2[100005];

void failure() {
    for (int i = 2; i <= t.size(); i++) {
        int j = f[i - 1];
        while (true) {
            if (t[j] == t[i - 1]) {
                f[i] = j + 1;
                break;
            }
            else if (j == 0) break;
            j = f[j];
        }
    }
}

void match() {
    int i = 0, j = 0;
    while (true) {
        if (i == s.size()) break;
        if (s[i] == t[j]) {
            i++, j++;
            g[i - 1] = j;
        } else if (j > 0) j = f[j];
        else i++;
    }
}

int main() {
    cin >> s >> t;
    memset(q1, -1, sizeof q1);
    memset(q2, -1, sizeof q2);
    failure();
    match();
    int sum = 0, last = 0;
    int sumx = 0, sumy = 0;
    for (int i = 0; i < s.size(); i++) {
        a[i] = i ? a[i - 1] : 0;
        if (g[i] == t.size()) {
            int j = i - g[i];
            a[i] = (i - g[i] + 2 + q2[j]) % mod;
        }
        q1[i] = i ? (q1[i - 1] + a[i]) % mod : a[i];
        q2[i] = i ? (q2[i - 1] + q1[i]) % mod : q1[i];
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++) ans = (ans + a[i]) % mod;
    cout << ans << endl;
    return 0;
}
