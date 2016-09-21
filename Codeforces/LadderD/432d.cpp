#include <bits/stdc++.h>
#define pb push_back
using namespace std;

string s;
int f[100005];
int b[100005];
vector<int> graph[100005];
int sz[100005];

void failure() {
    for (int j = 2; j <= s.size(); j++) {
        int i = f[j - 1];
        while (true) {
            if (s[i] == s[j - 1]) {
                f[j] = i + 1;
                break;
            } else if (i == 0) {
                break;
            }
            i = f[i];
        }
    }
}

void calc(int u = 0) {
    sz[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        calc(v);
        sz[u] += sz[v];
    }
}

int main() {
    cin >> s;
    failure();
    for (int i = 1; i <= s.size(); i++) {
        graph[f[i]].pb(i);
    }
    int x = f[s.size()];
    int ans = 1;
    b[s.size()] = 1;
    calc();
    while (x) {
        b[x] += sz[x];
        ans++;
        x = f[x];
    }
    cout << ans << endl;
    for (int i = 0; i <= s.size(); i++) if (b[i]) cout << i << " " << b[i] << endl;
    return 0;
}
