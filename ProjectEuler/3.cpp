// 3


/*sieve*/
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;

bitset<1000005> bs;
vector<ll> primes;

void sieve(ll n) {
    ll sieve_size = n;
    bs.set();
    for(ll i = 2; i <= sieve_size; i++) {
        if(bs[i]) {
            primes.push_back(i);
            for(ll j = i * i; j <= sieve_size; j += i) {
                bs[j] = 0;
            }
        }
    }
}

ll largest_prime_factor(ll n) {
    for(ll i = primes.size() - 1; i >= 0; i--) {
        if(n % primes[i] == 0) return primes[i];
    }
    return -1;
}

int main() {
    sieve(1000000);
    printf("%lld\n", largest_prime_factor(600851475143));
    return 0;
}
