/*
ID: ivanali1
LANG: C++
TASK: dualpal
*/

#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

char digit_to_char(int digit) {
    if(digit >= 0 && digit <= 9) return digit + '0';
    else return digit - 10 + 'A';
}

int char_to_digit(char ch) {
    if(ch >= '0' && ch <= '9') return ch - '0';
    else return ch - 'A' + 10;
}

string number_to_representation(int n, int base) {
    string out;
    while(n) {
        int digit = n % base;
        char ch = digit_to_char(digit);
        out = ch + out;
        n /= base;
    }
    return out;
}

int representation_to_number(string in, int base) {
    int total = 0;
    int exponent;
    for(int i = in.size() - 1; i >= 0; i--) {
        exponent = in.size() - i - 1;
        total += (in[i] * pow(base, exponent));
    }
    return total;
}

bool isPalindrome(string s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    FILE* fin = fopen("dualpal.in", "r");
    FILE* fout = fopen("dualpal.out", "w+");
    int N, S;
    fscanf(fin, "%d %d", &N, &S);
    int two;
    while(N) {
        two = 0;
        S++;
        for(int base = 2; base <= 10; base++) {
            if(isPalindrome(number_to_representation(S, base))) two++;
            if(two == 2) {
                N--;
                fprintf(fout, "%d\n", S);
                break;
            }
        }
    }

    return 0;
}
