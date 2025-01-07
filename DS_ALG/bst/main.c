#include <stdio.h>

#include "bst.h"


int main(void) {
	double const ar[5] = {
		[0] = 1.2,
		[4] = 3.1,
		[1] = 2,
		[2] = 9,
		[3] = -12,
	};

	size_t N = sizeof ar / sizeof ar[0];

	tree* bst = tree_new();
	for (size_t i = 0; i < N; i++)
		tree_insert(bst, node_new(ar[i]));

	inorder_traversal(bst->root);
	putchar('\n');

	double search_key = 2;
	node* n = tree_search(bst->root, search_key);
	if (n){
		printf("Key [%g] found.\n", search_key);
		node* suc = tree_successor(n);
		node* pre = tree_predecessor(n);
		if (suc) {
			printf("Successor to key[%g] is '%g'.\n", search_key, suc->k);
		} else {
			printf("Key [%g] has no successor.\n", search_key);
		}

		if (pre) {
			printf("Predecessor to key[%g] is '%g'.\n", search_key, pre->k);
		} else {
			printf("Key [%g] has no predecessor.\n", search_key);
		}

		printf("Deleting key [%g].\n", search_key);
		tree_del_node(bst, n);
		inorder_traversal(bst->root);
		putchar('\n');
	}
	else printf("Key [%g] not found. \n", search_key);

	tree_delete(bst);

	return 0;
}
