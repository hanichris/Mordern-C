#ifndef MY_BST_H
#define MY_BST_H 1


#include <stdlib.h>


/**
 * node - a new type that defines an element in a binary search tree.
 * Each element has a `key` attribute. Additionally, three other
 * attributes are defined, i.e, p, left, and right that are pointers
 * to the element's parent, left child and right child respectively.
 */
typedef struct node node;
struct node {
	double k;
	node* p;
	node* left;
	node* right;
};

/**
 * node_init - initialises a node element. Only utilise this function on
 * an unintialised element.
 * @n: a pointer to an unintialised node type.
 * @k: The key attribute for this given node.
 * @Returns: pointer to an initialised node. Otherwise, null.
 */
node* node_init(node* n, double k);

/**
 * node_destroy - destroys a node element. The node element must have been
 * initialied through the function call `node_init`.
 * @n: pointer to the node element to destroy.
 * @Returns: void.
 */
void node_destroy(node* n);

[[nodiscard("Pointer to allocated node dropped.")]]
[[__gnu__::__malloc__]]
inline
node* node_new(double k) {
	return node_init((node*)malloc(sizeof(node)), k);
}

/**
 * tree - a new type that defines a binary search tree. The tree only has one
 * attribute, root, which is the root of the tree.
 */
typedef struct tree tree;
struct tree {
	node* root;
};

/**
 * inorder_traversal - walks a binary search tree in sorted
 * order.
 * @n: pointer to a subtree rooted at node n.
 */
void inorder_traversal(node* n);

/**
 * tree_init - initialises a tree element. Only utilise this function on an
 * unintialised tree.
 * @t: pointer to an unintialised tree.
 * @Returns: pointer to an initialised tree.
 */
tree* tree_init(tree* t);

/**
 * post_order_destroy - destroys a binary search tree `t`
 * using the post-order traversal algorithm. The bst MUST
 * have been initialised with a call to `tree_init`.
 * @t: pointer to an initialised binary search tree.
 * @Returns: void.
 */
void post_order_destroy(node* n);

/**
 * tree_insert - insert node z into the bst t.
 * @Returns: void.
 */
void tree_insert(tree* t, node* z);

/**
 * tree_del_node - deletes the node `z` from the binary search
 * tree `T`.
 * @Returns: void.
 */
void tree_del_node(tree* t, node* z);

/**
 * tree_search - iteratively searches for the node with the given key `k`
 * in the subtree rooted at `n`. If found, returns a pointer
 * to the node with key `k`. Otherwise, null.
 * @n: pointer to the subtree rooted at node n.
 * @k: key value to search for.
 * @Returns: pointer to the node with the given key attribute.
 * Null, otherwise.*/
node* tree_search(node* n, double k);

/**
 * tree_min - returns a pointer to the minimum element in the
 * subtree rooted at `n`.
 * @n: pointer to the subtree rooted at node n.
 * @Returns: pointer to the minimum element. Null, otherwise.
 */
node* tree_min(node* n);

/**
 * tree_max - returns a pointer to the maximum element in the
 * subtree rooted at `n`.
 * @n: pointer to the subtree rooted at n.
 * @Returns: pointer to the maximum element. Null, otherwise.
 */
node* tree_max(node* n);

/**
 * tree_predecessor - returns a pointer to the element that
 * would preceed `x` in an inorder walk of a bst. Null, otherwise.
 */
node* tree_predecessor(node* x);

/**
 * tree_successor - returns a pointer to the element that
 * would succeed `x` in an inoder walk of a bst. Null, otherwise.
 */
node* tree_successor(node* x);

[[nodiscard("Pointer to allocated tree dropped.")]]
[[__gnu__::__malloc__]]
inline
tree* tree_new(void) {
	return tree_init((tree*)malloc(sizeof(tree)));
}

/**
 * tree_delete - delete a binary search tree `t`. The tree
 * MUST have been allocated through a call to `tree_new`
 */
inline
void tree_delete(tree* t) {
	post_order_destroy(t->root);
	free(t);
	t = nullptr;
}
#endif
