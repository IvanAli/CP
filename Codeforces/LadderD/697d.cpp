#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[100005];
int size[100005];
int from[100005];
double ans[100005];

void calc(int u = 0) {
    size[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (size[v] == 0) calc(v);
        size[u] += size[v];
    }
}

int main() {
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &x);
        graph[x - 1].push_back(i + 1);
        from[i + 1] = x - 1;
    }
    calc();
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        ans[i] += ans[from[i]] + 1;
        long long sum = 0;
        int parent = from[i];
        sum += size[parent];
        sum -= size[i];
        sum -= 1;
        ans[i] += sum / 2.0;
    }
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%.1f", ans[i]);
    }
    printf("\n");
    return 0;
}
