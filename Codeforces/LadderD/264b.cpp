#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int dp[100005];
int d[100005];
vector<int> primes;
bitset<100005> bs;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void sieve(long long n) {
    bs.set();
    for (long long i = 2; i <= n; i++) {
        if (bs[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= n; j += i) bs[j] = 0;
        }
    }
}

vector<int> primefact(long long n) {
    int i = 0, prime = primes[i];
    vector<int> ret;
    while (prime * prime <= n) {
        while (n % prime == 0) {
            ret.push_back(prime);
            n /= prime;
        }
        prime = primes[++i];
    }
    if (n != 1) ret.push_back(n);
    return ret;
}

int main() {
    cin >> n;
    sieve(100000);
    for (int i = 0; i < n; i++) cin >> a[i], dp[a[i]] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> v = primefact(a[i]);
        for (int j = 0; j < v.size(); j++) dp[a[i]] = max(dp[a[i]], d[v[j]] + 1);
        for (int j = 0; j < v.size(); j++) d[v[j]] = dp[a[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[a[i]]);
    cout << ans << endl;
    return 0;
}
