/*
 * binary_tree.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */

#include <cstdio>
#include <iostream>
using std::cout;

class Node {
public:
	int x;
	Node *left;
	Node *right;
	Node(int x) {
		this->x = x;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree {
public:
	Node *root;
	BinaryTree() {
		root = NULL;
	}
	void insert(Node *root, int x) {
		if(root == NULL) {
			root = new Node(x);
		}
		else {
			if(root->left == NULL) {
				insert(root->left, x);
			}
			else if(root->right == NULL) {
				insert(root->right, x);
			}
		}
	}
	// print operations
	void preOrder(Node *root) {
		if(root != NULL) {
			printf(" %d", root->x);
			preOrder(root->left);
			preOrder(root->right);
		}
	}
    void preorderPrint( Node *root ) {
           // Print all the items in the tree to which root points.
           // The item in the root is printed first, followed by the
           // items in the left subtree and then the items in the
           // right subtree.
        if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
           cout << root->x << " ";      // Print the root item.
           preorderPrint( root->left );    // Print items in left subtree.
           preorderPrint( root->right );   // Print items in right subtree.
        }
     } // end preorderPrint()
};



int main() {
	BinaryTree *bt = new BinaryTree();
	printf("Let's do it\n");
	bt->insert(bt->root, 3);
	bt->insert(bt->root, 8);
	bt->insert(bt->root, 2);
	bt->insert(bt->root, 7);
	bt->insert(bt->root, 4);

	printf("Preorder:");
	bt->preorderPrint(bt->root);

	return 0;
}


