/*
ID: ivanali1
LANG: C++
TASK: namenum
*/
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

char name[13];
FILE* dictfile;
FILE* fin;
FILE* fout;
set<string> dict;

map<long long, set<char> > m;
long long N;
char number[13];

set<string> valid;

void backtrack(long long c) {
    if(number[c] == '\0') {
        if(dict.find(name) != dict.end()) {
            // fprintf(fout, "%s\n", name);
            valid.insert(name);
        }
        return;
    }
    for(set<char>::iterator it = m[number[c] - '0'].begin(); it != m[number[c] - '0'].end(); it++) {
        name[c] = *it;
        backtrack(c + 1);
    }
}

void insertion() {
    m[2].insert('A');
    m[2].insert('B');
    m[2].insert('C');
    m[3].insert('D');
    m[3].insert('E');
    m[3].insert('F');
    m[4].insert('G');
    m[4].insert('H');
    m[4].insert('I');
    m[5].insert('J');
    m[5].insert('K');
    m[5].insert('L');
    m[6].insert('M');
    m[6].insert('N');
    m[6].insert('O');
    m[7].insert('P');
    m[7].insert('R');
    m[7].insert('S');
    m[8].insert('T');
    m[8].insert('U');
    m[8].insert('V');
    m[9].insert('W');
    m[9].insert('X');
    m[9].insert('Y');
}

int main() {
    dictfile = fopen("dict.txt", "r");
    fin = fopen("namenum.in", "r");
    fout = fopen("namenum.out", "w+");
    char str[13];
    while(fscanf(dictfile, "%s", str) != EOF) {
        dict.insert(str);
    }
    /*for(int i = 0; i <= 7; i++) {
        for(int j = 0; j < 3; j++) {
            m[i + 2].insert('A' + j + i * 3);
        }
    }*/

    insertion();
    fscanf(fin, "%lld", &N);
    sprintf(number, "%lld", N);
    backtrack(0);

    if(valid.size()) {
        for(set<string>::iterator it = valid.begin(); it != valid.end(); it++) {
            fprintf(fout, "%s\n", (*it).c_str());
        }
    }
    else fprintf(fout, "NONE\n");


    return 0;
}
