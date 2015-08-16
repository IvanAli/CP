/*
 * 1064.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: Ivan
 */

// 1064 - Network

#include <cstdio>
#include <deque>
using namespace std;

struct Overhead {
	int number;
	int begin;
	int end;
};

int main() {
	int N, M, cn;
	int *messages, *current;
	int p, minbytes;
	Overhead *packets;
	deque<Overhead> order;
	deque<Overhead> buffer;

	cn = 0;
	while(scanf("%d %d", &N, &M) && (N || M)) {
		messages = new int[N];
		current = new int[N];
		minbytes = 0;
		buffer.clear();
		order.clear();

		for(int i = 0; i < N; i++) {
			scanf("%d", &messages[i]);
		}

		packets = new Overhead[M];

		for(int i = 0; i < M; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			packets[i].number = a - 1;
			packets[i].begin = b - 1;
			packets[i].end = c - 1;

			current[i] = 0;
		}
		printf("ok\n");
		int i = 0;
		while(order.size() != M) {
			printf("Current value: %d at %d, packet begin %d\n", current[packets[i].number], packets[i].number, packets[i].begin);
			if(!buffer.empty()) {
				for(deque<Overhead>::iterator it = buffer.begin(); it != buffer.end(); it++) {
					printf("Iteration\n");
					if(it->begin == current[it->number]) {
						printf("CurrentBack: %d, messages: %d\n", current[order.back().number], messages[order.back().number]);

						if(current[order.back().number] == messages[order.back().number]) {
							printf("into\n");
							current[it->number] += it->end - it->begin + 1;
							order.push_back(*it);
							buffer.erase(it); // pop
							if(buffer.empty()) break;
							printf("outo,%d\n", current[it->number]);
						}

					}
				}
			}
			if(packets[i].begin == current[packets[i].number]) {

				if(order.empty() || packets[i].number == order.back().number || current[order.back().number] == messages[order.back().number]) {
					current[packets[i].number] += packets[i].end - packets[i].begin + 1;
					order.push_back(packets[i]);
					printf("packet %d passes. count:%d\n", i + 1, current[packets[i].number]);
					i++;
				}
				else {
					printf("to the buffer\n");
					buffer.push_back(packets[i]);
					minbytes += packets[i].end - packets[i].begin + 1;
					i++;
				}



			}
			else {
				printf("to the buffer\n");
				buffer.push_back(packets[i]);
				minbytes += packets[i].end - packets[i].begin + 1;
				i++;
			}

		}
		/*
		for(deque<Overhead>::iterator it = buffer.begin(); it != buffer.end(); it++) {
			minbytes += it->end + it->begin + 1;
		}
		*/
		printf("Case %d: %d\n", ++cn, minbytes);
		printf("\n");

	}
	return 0;
}


