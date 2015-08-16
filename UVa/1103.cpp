/*
 * 1103.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: Ivan
 */

// 1103 - Ancient Messages

#include <cstdio>
#include <queue>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

priority_queue<char, vector<char>, greater<char> > pq;
char image[15000][15000];
char id[58];
int ws[58];
int maxrow, maxcol;

int dr8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

queue<ii> q;

const char* hexToBin(char c) {
	switch(toupper(c)) {
	 	case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': return "1010";
		case 'B': return "1011";
		case 'C': return "1100";
		case 'D': return "1101";
		case 'E': return "1110";
		case 'F': return "1111";
	}
}

void floodfill(int r, int c, char c1, char c2) {
	if(r < 0 || r >= maxrow) return;
	if(c < 0 || c >= maxcol) return;
	if(image[r][c] != c1) return;
	image[r][c] = c2;
	for(int j = 0; j < 4; j++) {
		floodfill(r + dr[j], c + dc[j], c1, c2);
	}
}

void floodfill8(int r, int c, char c1, char c2) {
	if(r < 0 || r >= maxrow) return;
	if(c < 0 || c >= maxcol) return;
	if(image[r][c] != c1) return;
	image[r][c] = c2;
	for(int d = 0; d < 8; d++) {
		floodfill8(r + dr8[d], c + dc8[d], c1, c2);
	}
}

void floodfill8BFS(char c1, char c2) {
	while(!q.empty()) {
		ii u = q.front(); q.pop();
		if(u.first < 0 || u.first >= maxrow) continue;
		if(u.second < 0 || u.second >= maxcol) continue;
		if(image[u.first][u.second] != c1) continue;
		image[u.first][u.second] = c2;
		for(int d = 0; d < 8; d++) {
			q.push(ii(u.first + dr8[d], u.second + dc8[d]));
		}
	}
}

void floodfillBFS(char c1, char c2) {
	while(!q.empty()) {
		ii u = q.front(); q.pop();
		if(u.first < 0 || u.first >= maxrow) continue;
		if(u.second < 0 || u.second >= maxcol) continue;
		if(image[u.first][u.second] != c1) continue;
		image[u.first][u.second] = c2;
		for(int d = 0; d < 4; d++) {
			q.push(ii(u.first + dr[d], u.second + dc[d]));
		}
	}
}

int main() {
	int tc = 0;
	int H, W;
	int ccw, ccb, p;
	for(char i = 'A'; i <= 'z'; i++) {
		id[i - 'A'] = i;
	}
	while(scanf("%d %d", &H, &W) && (H | W)) {
		maxrow = H;
		maxcol = W * 4;
		ccw = 0; ccb = 0; p = 0;
		memset(ws, -1, 58);
		for(int i = 0; i < 58; i++) ws[i] = -1;

		char s[W];
		const char *bin;
		for(int i = 0; i < H; i++) {
			scanf("%s", &s);
			for(int j = 0; j < W; j++) {
				bin = hexToBin(s[j]);
				for(int k = 0; k < 4; k++) {
					image[i][j * 4 + k] = bin[k];
				}
			}
		}

		// algorithm
		bool found = false;
		for(int j = 0; j < maxcol; j++) {
			if(image[0][j] == '0') {
				q.push(ii(0, j));
				floodfill8BFS('0', '.');
			}
			if(image[maxrow - 1][j] == '0') {
				q.push(ii(maxrow - 1, j));
				floodfill8BFS('0', '.');
			}
		}
		for(int i = 0; i < maxrow; i++) {
			if(image[i][0] == '0') {
				q.push(ii(i, 0));
				floodfill8BFS('0', '.');
			}
			if(image[i][maxcol - 1] == '0') {
				q.push(ii(i, maxcol - 1));
				floodfill8BFS('0', '.');
			}
		}
		// floodfill8(0, 0, '0', '.');
		/*for(int i = 0; i < maxrow; i++) {
			for(int j = 0; j < maxcol; j++) {
				printf("%c", image[i][j]);
			}
			printf("\n");
		}*/
		for(int i = 0; i < maxrow; i++) {
			for(int j = 0; j < maxcol; j++) {
				/*if(image[i][j] == '0') {
					floodfill(i, j, '0', '.');
					ccw++;
				}*/
				if(image[i][j] == '1') {
					floodfill(i, j, '1', id[p]);
					ws[p] = 0;
					ccb++;p++;
				}
			}
		}
		char currch;
		for(int i = 0; i < maxrow; i++) {
			for(int j = 0; j < maxcol; j++) {
				// printf("%c", image[i][j]);
				if(!isdigit(image[i][j])) {
					currch = image[i][j];
				}
				if(image[i][j] == '0') {
					// printf("blank at curr char: %c\n", currch);
					q.push(ii(i, j));
					floodfillBFS('0', '.');
					ws[currch - 'A']++;
				}
			}
			// printf("\n");
		}
		for(int i = 0; i < 56; i++) {
			if(ws[i] == 1) pq.push('A');
			if(ws[i] == 3) pq.push('J');
			if(ws[i] == 5) pq.push('D');
			if(ws[i] == 4) pq.push('S');
			if(ws[i] == 0) pq.push('W');
			if(ws[i] == 2) pq.push('K');
		}
		printf("Case %d: ", ++tc);
		while(!pq.empty()) {
			printf("%c", pq.top());
			pq.pop();
		}
		printf("\n");
		// printf("ccw: %d ccb: %d\n", ccw, ccb);

	}


	return 0;
}


