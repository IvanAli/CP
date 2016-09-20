#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, k;
int grid[105][105];
int dp[105][105][11];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) grid[i][j] = s[j] - '0';
	}
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < m; i++) dp[0][i][grid[0][i] % (k + 1)] = grid[0][i];
	for (int i = 1; i < n; i++) for (int j = 0; j < m; j++) for (int a = 0; a < k + 1; a++) {
		int kk = (dp[i - 1][j - 1][a] + grid[i][j]) % (k + 1);
		if (j && dp[i - 1][j - 1][a] != -1) dp[i][j][kk] = max(dp[i][j][kk], dp[i - 1][j - 1][a] + grid[i][j]);
		kk = (dp[i - 1][j + 1][a] + grid[i][j]) % (k + 1);
		if (j < m - 1 && dp[i - 1][j + 1][a] != -1) dp[i][j][kk] = max(dp[i][j][kk], dp[i - 1][j + 1][a] + grid[i][j]);
	}
	int ans = -1;
	int c = 0;
	for (int i = 0; i < m; i++) {
		if (dp[n - 1][i][0] > ans) {
			ans = dp[n - 1][i][0];
			c = i;
		}
	}
	cout << ans << endl;
	if (ans == -1) return 0;
	cout << c + 1 << endl;
	int r = n - 1;
	int curr = 0;
	while (r) {
		int kk = (dp[r][c][curr] + (k + 1) - grid[r][c]) % (k + 1);
		if (c && dp[r][c][curr] == dp[r - 1][c - 1][kk] + grid[r][c]) {
			cout << "L";
			r--;
			c--;
			curr = kk;
		} else if (c < m - 1) {
			cout << "R";
			r--;
			c++;
			curr = kk;
		}
	}
	cout << endl;
	return 0;
}
