#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];
int n;

bool ok() {
    for (int i = 0; i < 26; i++) if (cnt[i] > 1) return false;
    return true;
}

void stuff() {
    for (int i = 0; i < n; i++) if (s[i] == '?') s[i] = 'A';
}

int main() {
    cin >> s;
    n = s.size();
    if (n < 26) return cout << -1 << endl, 0;
    for (int i = 0; i + 26 <= n; i++) {
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < 26; j++) if (s[i + j] != '?') cnt[s[i + j] - 'A']++;
        if (ok()) {
            for (int a = 0, b = 0; a < 26; a++) {
                if (s[a + i] == '?') {
                    while (b < n && cnt[b]) b++;
                    if (b == n) break;
                    s[a + i] = b + 'A';
                    b++;
                }
            }
            stuff();
            cout << s << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
