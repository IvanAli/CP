#include <bits/stdc++.h>
#define pb push_back
#define INF 1e9
using namespace std;

int n;
int a[200005];
int from[200005];

int findSet(int x) {
    if (x == from[x]) return x;
    return from[x] = findSet(from[x]);
}

int merge(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    from[x] = y;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        from[i] = i;
    }
    int root = -1;
    for (int i = 0; i < n; i++) if (i == a[i]) {
        root = i;
        break;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (findSet(i) != findSet(a[i])) {
            merge(i, a[i]);
        } else {
            if (root == a[i]) continue;
            if (root != -1) a[i] = root;
            else root = a[i] = i;
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) cout << a[i] + 1 << " ";
    cout << endl;
    return 0;
}
