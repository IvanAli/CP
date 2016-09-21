#include <bits/stdc++.h>
using namespace std;

string s;
int n;
long long ansodd = 0, anseven = 0;
int oddcnt[2];
int evencnt[2];

int main() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        ansodd++;
        int let = s[i] - 'a';
        if (i % 2) {
            ansodd += oddcnt[let];
            anseven += evencnt[let];
            oddcnt[let]++;
        } else {
            ansodd += evencnt[let];
            anseven += oddcnt[let];
            evencnt[let]++;
        }
    }
    cout << anseven << " " << ansodd << endl;
}
