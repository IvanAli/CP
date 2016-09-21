#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int turn[100005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> stk;
    stk.push_back(0);
    turn[0] = -1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        while (stk.size() && a[stk.back()] < a[i]) {
            turn[i] = max(turn[i], turn[stk.back()] + 1);
            stk.pop_back();
        }
        if (!stk.size()) turn[i] = -1;
        stk.push_back(i);
        ans = max(ans, turn[i] + 1);
    }
    cout << ans << endl;
    return 0;
}
