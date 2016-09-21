#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<ii> vii;

int n;
vii pts;
map<dd, int> hash;
dd midp;

dd midPoint(ii a, ii b) {
	return dd(double(a.x + b.x) / 2.0, double(a.y + b.y) / 2.0);
}

int main() {
	cin >> n;
	pts = vii(n);
	for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			midp = midPoint(pts[i], pts[j]);
			hash[midp]++;
		}
	}
	int ans = 0;
	int val;
	for (map<dd, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
		val = it->second;
		ans = ans + (val * (val - 1)) / 2;
	}
	cout << ans << endl;
	return 0;
}
