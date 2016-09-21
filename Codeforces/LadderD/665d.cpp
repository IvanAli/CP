#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int n;
vi a;
bitset<2000005> bs;

void sieve(ll n) {
    bs.set();
    for (ll i = 2; i <= n; i++) {
        if (bs[i]) {
            for (ll j = i * i; j <= n; j += i) bs[j] = 0;
        }
    }
}

bool isPrime(int k) {
    return bs[k];
}

void solve() {
    int ans1 = count(a.begin(), a.end(), 1);
    int prime = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1 && isPrime(a[i] + 1)) {
            prime = a[i];
            ans1++;
            break;
        }
    }
    if (ans1 >= 2) {
        cout << ans1 << endl;
        if (prime) {
            cout << prime << " ";
            for (int i = 0; i < ans1 - 1; i++) {
                if (i) cout << " ";
                cout << 1;
            }
        }
        else {
            for (int i = 0; i < ans1; i++) {
                if (i) cout << " ";
                cout << 1;
            }
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrime(a[i] + a[j])) {
                    cout << 2 << endl;
                    cout << a[i] << " " << a[j] << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
        cout << a[0] << endl;
    }
}

int main() {
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sieve(2000000);
    int ans = 0;
    solve();
    return 0;
}
