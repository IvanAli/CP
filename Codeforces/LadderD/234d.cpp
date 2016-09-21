#include <bits/stdc++.h>
using namespace std;

int m, k, n;
int a[105];
set<int> S;
vector<int> v[105];
int c1[105], c2[105];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    cin >> m >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) S.insert(a[i]);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int d;
        cin >> s;
        cin >> d;
        v[i] = vector<int>(d);
        for (int j = 0; j < d; j++) cin >> v[i][j];
    }
    int ans1 = 0, ans2 = 0;
    int anss1 = 0, anss2 = 0;
    int max1, max2;
    for (int i = 0; i < n; i++) {
        int good = 0;
        int z = 0;
        int bad = 0;
        int rest;
        for (int j = 0; j < v[i].size(); j++) {
            if (S.count(v[i][j])) good++;
            else if (v[i][j] == 0) z++;
            else bad++;
        }
        rest = m - k - bad;
        c1[i] = good + max(0, z - rest);
        c2[i] = min(z, k - good) + good;
        if (ans1 < c1[i]) {
            ans1 = c1[i];
            max1 = i;
        }
        if (ans2 < c2[i]) {
            ans2 = c2[i];
            max2 = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (anss1 < c1[i] && i != max1) anss1 = c1[i];
        if (anss2 < c2[i] && i != max2) anss2 = c2[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == max1 && i == max2) {
            if (c1[i] >= anss2) cout << 0;
            else if (c2[i] >= anss1) cout << 2;
            else cout << 1;
        } else if (i == max1 && i != max2) {
            if (c1[i] >= ans2) cout << 0;
            else if (c2[i] >= anss1) cout << 2;
            else cout << 1;
        } else if (i != max1 && i == max2) {
            if (c1[i] >= anss2) cout << 0;
            else if (c2[i] >= ans1) cout << 2;
            else cout << 1;
        } else {
            if (c1[i] >= ans2) cout << 0;
            else if (c2[i] >= ans1) cout << 2;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}
