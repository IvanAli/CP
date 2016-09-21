#include <bits/stdc++.h>
using namespace std;

bool isZort(vector<int>& a) {
    bool gt = true;
    for (int i = 1; i < a.size(); i++) {
        if (gt) {
            if (a[i] < a[i - 1]) return false;
        }
        else {
            if (a[i] > a[i - 1]) return false;
        }
        gt = !gt;
    }
    return true;
}

void print(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int> > pqg;
    priority_queue<int> pql;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        pqg.push(a[i]);
        pql.push(a[i]);
    }
    bool gt = true;
    vector<int> zsorted;
    for (int i = 0; i < n; i++) {
        if (gt) {
            zsorted.push_back(pqg.top());
            pqg.pop();
        }
        else {
            zsorted.push_back(pql.top());
            pql.pop();
        }
        gt = !gt;
    }
    if (isZort(zsorted)) print(zsorted);
    else cout << "Impossible" << endl;
    return 0;
}
