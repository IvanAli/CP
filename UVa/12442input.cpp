#include <cstdio>

int main() {
	printf("1\n50000\n");
	for(int i = 0; i < 50000; i++) {
		printf("%d %d\n", i + 1, (i + 2) % 50000);
	}
	return 0;
}
