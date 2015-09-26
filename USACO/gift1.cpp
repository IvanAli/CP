/*
ID: ivanali1
LANG: C++
TASK: gift1
*/

#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int N, a, b;
    FILE* fin = fopen("gift1.in", "r");
    FILE* fout = fopen("gift1.out", "w+");
    vector<int> start;
    vector<int> money;
    map<string, int> m;
    vector<string> names;
    char str[15];
    char str2[15];
    fscanf(fin, "%d", &N);
    start.assign(N, -1);
    money.assign(N, 0);
    for(int i = 0; i < N; i++) {
        fscanf(fin, "%s", str);
        m[str] = i;
        names.push_back(str);
    }
    while((fscanf(fin, "%s", str) == 1)) {
        fscanf(fin, "%d %d", &a, &b);
        if(start[m[str]] == -1) {
            start[m[str]] = a;
        }
        money[m[str]] += a;
        for(int i = 0; i < b; i++) {
            fscanf(fin, "%s", str2);
            if(b) money[m[str2]] += a / b;
        }
        money[m[str]] -= a;
        if(b) money[m[str]] += (a % b);   
    }
    /*for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        printf("%s %d\n", (it->first).c_str(), money[m[it->first]] - start[m[it->first]]);
    }*/
    for(int i = 0; i < names.size(); i++) {
        fprintf(fout, "%s %d\n", names[i].c_str(), money[m[names[i]]] - start[m[names[i]]]);
    }
    return 0;
}
