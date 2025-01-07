#include <stdio.h>

#include "bst.h"


node* node_init(node *n, double k) {
	if (n) {
		n->k = k;
		n->left = nullptr;
		n->right = nullptr;
		n->p = nullptr;
	}

	return n;
}

void node_destroy(node *n) {
	if (n)
		free(n);
	n = nullptr;
}

tree* tree_init(tree *t) {
	if (t) {
		t->root = nullptr;
	}
	return t;
}

void post_order_destroy(node* n) {
	if (n) {
		post_order_destroy(n->left);
		post_order_destroy(n->right);
		node_destroy(n);
	}
}

void tree_insert(tree* t, node* z) {
	node* x = t->root;
	node* y = nullptr;

	while (x) {
		y = x;
		if (z->k < x->k)
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if (!y)
		t->root = z;
	else if (z->k < y->k)
		y->left = z;
	else
		y->right = z;
}

node* tree_search(node* n, double k) {
	node* cur = n;
	while (cur && cur->k != k) {
		if (k < cur->k) 
			cur = cur->left;
		else
			cur = cur->right;
	}
	return cur;
}

node* tree_min(node* n) {
	node* cur = n;
	while (cur && cur->left)
		cur = cur->left;
	return cur;
}

node* tree_max(node* n) {
	node* cur = n;
	while (cur && cur->right)
		cur = cur->right;
	return cur;
}

node* tree_successor(node* x) {
	if (x && x->right)
		return tree_min(x->right);
	node* y = x->p;
	node* cur = x;
	while (y && y->right == cur) {
		cur = y;
		y = y->p;
	}
	return y;
}

node* tree_predecessor(node* x) {
	if (x && x->left)
		return tree_max(x->left);
	node* y = x->p;
	node* cur = x;
	while (y && y->left == cur) {
		cur = y;
		y = y->p;
	}
	return y;
}

void inorder_traversal(node* n) {
	if (n) {
		inorder_traversal(n->left);
		printf("( %g ) --> ", n->k);
		inorder_traversal(n->right);
	}
}
