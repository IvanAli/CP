// 51

#include <cstdio>
#include <bitset>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

bitset<1000005> bs;
vector<ll> primes;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

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

bool isPrime(ll n) {
    return bs[n];
}

ll largest_prime_factor(ll n) {
    for(ll i = primes.size() - 1; i >= 0; i--) {
        if(n % primes[i] == 0) return primes[i];
    }
    return -1;
}

string int_to_str(ll n) {
    string str;
    while(n) {
        char ch = n % 10 + '0';
        str = ch + str;
        n /= 10;
    }
    return str;
}

int str_to_int(string str) {
    ll n = 0;
    int len = str.size();
    int exponent;
    int power = 1;
    for(int i = len - 1; i >= 0; i--) {
        exponent = len - 1 - i;
        int digit = str[i] - '0';
        n += digit * power;
        power *= 10;
    }
    return n;
}

string dec_to_binary(ll n) {
    string str;
    for(int i = 0; i < 7; i++) {
        if(n & (1 << i)) str = '1' + str;
        else str = '0' + str;
    }
    return str;
}

bool checkMask(ll n, ll mask) {
    string n_str = int_to_str(n);
    string mask_str = int_to_str(mask);

    int len_n = n_str.size();
    int len_mask = mask_str.size();


    if(len_n < len_mask) {
        for(int i = 0; i < len_mask - len_n; i++) {
            n_str = '0' + n_str;
        }
    }
    if(len_mask < len_n) {
        for(int i = 0; i < len_n - len_mask; i++) {
            mask_str = '0' + mask_str;
        }
    }

    int repeatedDigit = -1;
    for(int i = 0; i < len_n; i++) {
        if(mask_str[i] == '1') {
            if(repeatedDigit == -1) {
                if(n_str[i] == '0' && i == 0) return false;
                repeatedDigit = n_str[i] - '0';
            }
            else {
                if(n_str[i] - '0' != repeatedDigit) return false;
            }
        }
    }
    if(n == 11 && mask == 1000) {
        cout << "checkmask: " << mask_str << ", n: " << n_str << endl;
        cout << "lens: " << len_n << " " << len_mask << endl;
        cout << n_str << "... " << mask_str << endl;
    }
    return true;
}

int number_length(ll n) {
    int len = 0;
    while(n /= 10) len++;
    return len;
}

int get_digit(ll n, int index_last) {
    int digit;
    for(int i = 0; i <= index_last; i++) {
        digit = n % 10;
        n /= 10;
    }
    return digit;
}

int main() {
    sieve(1000000);
    int familyMembers = 0;
    vector<int> binaries;
    for(int i = 2; i < (1 << 6); i++) {
        binaries.push_back(str_to_int(dec_to_binary(i)));
    }
    for(ll i = 4; i < primes.size(); i++) {
        ll prime = primes[i];
        for(ll j = 0; j < binaries.size(); j++) {
            prime = primes[i];
            int prime_len = number_length(prime);
            ll binary = binaries[j];
            familyMembers = 1;
            if(checkMask(prime, binary)) {
                while(get_digit(prime, log10(binary) + 1) == get_digit(primes[i], log10(binary) + 1) && number_length(prime) == prime_len) {
                    prime += binary;
                    if(isPrime(prime)) {
                        printf("new prime: %lld\n", prime);
                        familyMembers++;
                        if(familyMembers == 8) {
                            if(number_length(prime) == prime_len) {
                                printf("%lld\n", primes[i]);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
