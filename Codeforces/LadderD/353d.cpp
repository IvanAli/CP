#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int toki[1000005];
int wait[1000005];

int main() {
    cin >> s;
    n = s.size();
    int ans = 0;
    int pos = 0;
    bool beg = true;
    for (int i = 0; i < n; i++) {
        if (i) {
            wait[i] += wait[i - 1];
            if (s[i - 1] == 'M') wait[i] = max(0, wait[i] - 1);
            if (s[i - 1] == 'F') wait[i]++;
        }
        if (s[i] == 'F') {
            toki[i] = i - pos;
            pos++;
        }
        else if (s[i] == 'M') {
            if (beg) wait[i] = 0;
            beg = false;
        }
    }
    for (int i = 0; i < n; i++) if (toki[i]) ans = max(ans, toki[i] + wait[i]);
    cout << ans << endl;
    return 0;
}
