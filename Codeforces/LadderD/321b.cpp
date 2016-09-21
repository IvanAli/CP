#include <bits/stdc++.h>
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
using namespace std;

int n, m;
vector<int> atk, def;
vector<int> a;
bool used[105];

int solve1() {
    int ret = 0;
    for (int i = 0; i < a.size() && i < atk.size(); i++) {
        int sol = 0;
        for (int j = 0; j <= i; j++) {
            if (a[i - j] >= atk[j]) sol += a[i - j] - atk[j];
        }
        ret = max(ret, sol);
    }
    return ret;
}

int solve2() {
    int ret = 0;
    multiset<int> st(a.begin(), a.end());
    for (int i = 0; i < def.size(); i++) {
        multiset<int>::iterator it = st.upper_bound(def[i]);
        if (it == st.end()) return 0;
        st.erase(it);
    }
    for (int i = 0; i < atk.size(); i++) {
        multiset<int>::iterator it = st.lower_bound(atk[i]);
        if (it == st.end()) return 0;
        ret += *it - atk[i];
        st.erase(it);
    }
    for (multiset<int>::iterator it = st.begin(); it != st.end(); it++) ret += *it;
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "ATK") atk.pb(x);
        else def.pb(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    int ans = solve1();
    ans = max(ans, solve2());
    cout << ans << endl;
    return 0;
}
