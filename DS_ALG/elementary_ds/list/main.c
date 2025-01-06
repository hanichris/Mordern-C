#include "list.h"

int main(void) {
	list* l = list_new();

	print_list(l);

	list_insert(node_new(9), &l->nil);
	list_insert(node_new(25), &l->nil);
	list_insert(node_new(16), l->nil.prev);
	list_insert(node_new(100), &l->nil);
	print_list(l);

	double search_key = 100;
	node* n = list_search(l, search_key);
	if(n) {
		printf("KEY [%g] was found.\n", search_key);
		list_insert(node_new(-45), n);
	} else {
		printf("KEY [%g] was not found. Inserting it into the list.\n", search_key);
	}
	print_list(l);

	double delete_key = 9;
	n = list_search(l, delete_key);
	if(n) {
		printf("Deleting key [%g] from the list.\n", delete_key);
		node_delete(n);
	} else {
		printf("KEY [%g] was not found. Inserting it into the list.\n", delete_key);
	}
	print_list(l);

	list_delete(l);
	return 0;
}
