#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, m, p, b;
vi a;
vi tree;

void build(int x, int id = 1, int l = 0, int r = (1 << n)) {
    if (l + 1 == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(1 - x, id * 2, l, mid);
    build(1 - x, id * 2 + 1, mid, r);
    if (x) tree[id] = tree[id * 2] | tree[id * 2 + 1];
    else tree[id] = tree[id * 2] ^ tree[id * 2 + 1];
}

void update(int p, int x, int id = 1, int l = 0, int r = (1 << n)) {
    if (l + 1 == r) {
        tree[id] = a[p];
        return;
    }
    int mid = (l + r) / 2;
    if (p < mid) update(p, 1 - x, id * 2, l, mid);
    else update(p, 1 - x, id * 2 + 1, mid, r);
    if (x) tree[id] = tree[id * 2] | tree[id * 2 + 1];
    else tree[id] = tree[id * 2] ^ tree[id * 2 + 1];
}

int main() {
    int ans;
    cin >> n >> m;
    a = vi((1 << n));
    tree = vi(4 * (1 << n));
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    build(n % 2);
    for (int i = 0; i < m; i++) {
        cin >> p >> b;
        p--;
        a[p] = b;
        update(p, n % 2);
        cout << tree[1] << endl;
    }
    return 0;
}
