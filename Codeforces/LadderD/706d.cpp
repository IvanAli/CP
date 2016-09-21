#include <bits/stdc++.h>
using namespace std;

int q, x;
int tree[200005 * 40][2];
int sz;
int cnt[200005 * 40];

void add(int x) {
    int id = 1;
    cnt[id]++;
    for (int i = 30; i >= 0; i--) {
        bool z = ((x >> i) & 1);
        if (!tree[id][z]) tree[id][z] = ++sz;
        id = tree[id][z];
        cnt[id]++;
    }
}

void remove(int x) {
    int id = 1;
    cnt[id]--;
    for (int i = 30; i >= 0; i--) {
        bool z = ((x >> i) & 1);
        if (!tree[id][z]) tree[id][z] = ++sz;
        id = tree[id][z];
        cnt[id]--;
    }
}

int search(int x) {
    int id = 1;
    int ret = 0;
    for (int i = 30; i >= 0; i--) {
        bool z = ((x >> i) & 1);
        if (cnt[tree[id][!z]]) id = tree[id][!z], ret |= (1 << i);
        else id = tree[id][z];
    }
    return ret;
}


int main() {
    cin >> q;
    sz = 1;
    add(0);
    for (int i = 0; i < q; i++) {
        char ch;
        cin >> ch >> x;
        if (ch == '+') {
            add(x);
        } else if (ch == '-') {
            remove(x);
        } else if (ch == '?') {
            int ans = search(x);
            cout << ans << endl;
        }
    }
    return 0;
}
