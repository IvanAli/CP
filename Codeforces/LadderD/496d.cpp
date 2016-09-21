#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n;
int a[100005];
int cnt1[100005], cnt2[100005];
vector<pair<int, int> > ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cnt1[i + 1] = cnt1[i];
        cnt2[i + 1] = cnt2[i];
        if (a[i] == 1) cnt1[i + 1]++;
        if (a[i] == 2) cnt2[i + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        int p, low, high, mid, last, w1, w2;
        p = 0;
        w1 = 0, w2 = 0;
        while (p < n) {
            low = p + 1, high = n + 1;
            while (low < high) {
                mid = (low + high) >> 1;
                if (cnt1[mid] - cnt1[p] >= i || cnt2[mid] - cnt2[p] >= i) high = mid;
                else low = mid + 1;
            }
            if (cnt1[low] - cnt1[p] == i) w1++, last = 1;
            else if (cnt2[low] - cnt2[p] == i) w2++, last = 2;
            p = low;
        }
        if (p == n) {
            if (w1 > w2 && last == 1) ans.pb(mp(w1, i));
            else if (w2 > w1 && last == 2) ans.pb(mp(w2, i));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
