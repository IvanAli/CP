#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int q;
int m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> m;
        int ans = upper_bound(a, a + n, m) - a;
        int add = 0;
        if (ans) if (m >= a[ans - 1]) add++;
        cout << max(0, ans + add - 1) << endl;
    }
    return 0;
}
