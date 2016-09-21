#include <bits/stdc++.h>
using namespace std;

string s;
int f[1000005];
int b[1000005];

void failure(string s) {
    for (int i = 2; i <= s.size(); i++) {
        int j = f[i - 1];
        while (true) {
            if (s[j] == s[i - 1]) {
                f[i] = j + 1;
                break;
            }
            if (j == 0) break;
            j = f[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    failure(s);
    int ans = 0;
    int x = f[s.size()];
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < s.size(); j++) {
            if (f[j] == x) ans = max(ans, f[j]);
        }
        x = f[x];
    }
    if (ans) cout << s.substr(0, ans) << endl;
    else cout << "Just a legend" << endl;
    return 0;
}
