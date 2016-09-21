#include <bits/stdc++.h>
#define pb push_back
#define eps 1e-8
#define y1 qjwdiowqjdioqjd
using namespace std;

int n;
int k, b;
set<long double> st;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> b;
        if (k == 0) continue;
        st.insert(1. * -b / k);
    }
    cout << st.size() << endl;
    return 0;
}
