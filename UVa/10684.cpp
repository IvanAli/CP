// too lazy to open eclipse, so let's use sublime

// 10684 - The jackpot

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define NINF -1e9

typedef vector<int> vi;

int main() {
	int N, d;
	int ans;
	vi bets;
	while(scanf("%d", &N) && N) {
		bets.resize(N + 1);
		ans = -1;
		bets[0] = NINF;
		for(int i = 1; i < N + 1; i++) {
			scanf("%d", &d);
			bets[i] = d;
		}
		// algorithm
		for(int i = 1; i < N + 1; i++) {
			bets[i] = max(bets[i], bets[i] + bets[i - 1]);
			ans = max(ans, bets[i]);
		}
		if(ans) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}