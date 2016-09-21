#include <bits/stdc++.h>
using namespace std;

int f[100005];
string s1, s2;

void failure(string p) {
    for (int i = 2; i <= p.size(); i++) {
        int j = f[i - 1];
        while (true) {
            if (p[j] == p[i - 1]) {
                f[i] = j + 1;
                break;
            }
            if (j == 0) break;
            j = f[j];
        }
    }
}

int cnt(string t, string p) {
    failure(p);
    int i = 0, j = 0;
    int ret = 0;
    while (true) {
        if (j == t.size()) break;
        if (p[i] == t[j]) {
            i++;
            j++;
            if (i == p.size()) {
                ret++;
                i = 0;
            }
        }
        else if (i > 0) i = f[i];
        else j++;
    }
    return ret;
}

int main() {
    cin >> s1 >> s2;
    string s;
    if (s1.size() < s2.size()) s = s1;
    else s = s2;
    int ans = 0;
    int sol;
    for (int i = 1; i <= s.size(); i++) {
        string ss = s.substr(0, i);
        if (s1.size() % ss.size() || s2.size() % ss.size()) continue;
        sol = cnt(s1, ss);
        if (sol * ss.size() != s1.size()) continue;
        sol = cnt(s2, ss);
        if (sol * ss.size() != s2.size()) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
