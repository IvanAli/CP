#include <bits/stdc++.h>
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
using namespace std;

string s;
long long k;
long long n;
long long cnt[26];
vector<int> vt[26];

int main() {
    cin >> s >> k;
    n = s.size();
    if (n * n + n < 2LL * k) return cout << "No such line." << endl, 0;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'] += n - i;
        vt[s[i] - 'a'].pb(i);
    }
    while (k > 0) {
        int i;
        for (i = 0; i < 26 && cnt[i] < k; i++) k -= cnt[i];
        putchar('a' + i);
        k -= vt[i].size();
        vector<int> vvt = vt[i];
        for (int j = 0; j < 26; j++) cnt[j] = 0, vt[j].clear();
        for (int j = 0; j < vvt.size(); j++) {
            if (vvt[j] + 1 < n) {
                cnt[s[vvt[j] + 1] - 'a'] += n - vvt[j] - 1;
                vt[s[vvt[j] + 1] - 'a'].pb(vvt[j] + 1);
            }
        }
    }
    cout << endl;
    return 0;
}
