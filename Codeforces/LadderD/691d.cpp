#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[1000005];
int a, b;
int from[1000005];
vector<int> v[1000005];
int ans[1000005];

int find(int i) {
    return i == from[i] ? i : from[i] = find(from[i]);
}

void join(int i, int j) {
    int x = find(i);
    int y = find(j);
    from[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) from[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        join(a, b);
    }
    for (int i = 0; i < n; i++) {
        int id = find(i);
        v[id].push_back(p[i]);
    }
    for (int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
    for (int i = 0; i < n; i++) {
        int id = find(i);
        int back = v[id].back();
        v[id].pop_back();
        ans[i] = back;
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
