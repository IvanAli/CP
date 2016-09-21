#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> mp;

int main() {
    cin >> s;
    int ans = 0;
    if (s.size() % 2) return cout << -1 << endl, 0;
    for (int i = 0; i < s.size(); i++) mp[s[i]]++;
    ans += abs(mp['L'] - mp['R']);
    ans += abs(mp['U'] - mp['D']);
    cout << (ans >> 1) << endl;
    return 0;
}
