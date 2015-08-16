/*
 * segment_tree_attempt.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */

// my attempt to code a segment tree
// let's see how it goes

#include <vector>
using std::vector;

typedef vector<int> vi;

class Node {
public:
	int x;
	Node left;
	Node right;
	int L, R;
	Node(int value, int l, int r) {
		x = value;
		L = l;
		R = r;
	}
};

class SegmentTree {
public:
	int N;
	vi tree;
	SegmentTree(int *array, int size) {
		N = size;
		tree.assign(size + 1, 0);
		createTree(array);
	}
	void createTree(int *array) {

	}
};


