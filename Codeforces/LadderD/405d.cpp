#include <bits/stdc++.h>
#define INF 1e9
#define pb push_back
using namespace std;

int n;
int x[500005];
const int s = 1000000;
bool used[s + 5];
long long sumx, sumy;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        used[x[i]] = 1;
        sumx += x[i] - 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!used[s - x[i] + 1]) {
            used[s - x[i] + 1] = 1;
            ans.pb(s - x[i] + 1);
            sumy += x[i] - 1;
        }
    }
    for (int i = 1; sumx != sumy && i <= s; i++) {
        if (!used[i] && !used[s - i + 1]) {
            used[i] = used[s - i + 1] = 1;
            ans.pb(i);
            ans.pb(s - i + 1);
            sumy += s - 1;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
