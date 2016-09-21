#include <bits/stdc++.h>
using namespace std;

int n, k;
int q[105];
int s[105];
int inv[105];

bool ok(vector<int>& a) {
    for (int i = 0; i < n; i++) if (a[i] != s[i]) return false;
    return true;
}

bool identity(vector<int>& a) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[q[i] - 1] = a[i];
    for (int i = 0; i < n; i++) if (q[i] != b[i]) return false;
    return true;
}

int solve(vector<int> a, int k, bool x, int t = 0) {
    if (t == k) {
        if (!ok(a)) return true;
        return false;
    } else {
        if (!ok(a)) return false;
    }
    vector<int> b = vector<int>(n);
    if (x) {
        for (int i = 0; i < n; i++) b[i] = a[q[i] - 1];
    } else {
        for (int i = 0; i < n; i++) b[q[i] - 1] = a[i];
    }
    return solve(b, k, x, t + 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> a = vector<int>(n);
    vector<int> b, c;
    c = vector<int>(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    if (ok(a)) {
        cout << "NO" << endl;
        return 0;
    }
    if (identity(a)) {
        if (k == 1) {
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    b = a;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) c[j] = b[q[j] - 1];
        b = c;
        if (ok(b)) {
            if ((k - i) % 2) {
                cout << "YES" << endl;
                return 0;
            }
            break;
        }
    }
    b = a;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) c[q[j] - 1] = b[j];
        b = c;
        if (ok(b)) {
            if ((k - i) % 2) {
                cout << "YES" << endl;
                return 0;
            }
            break;
        }
    }
    cout << "NO" << endl;
    return 0;
}
