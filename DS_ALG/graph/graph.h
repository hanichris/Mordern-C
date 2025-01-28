#ifndef MY_GRAPH_H
#define MY_GRAPH_H 1

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum colour: uint8_t {
	WHITE = 0,
	GREY,
	BLACK,
};
typedef enum colour colour;

typedef struct node node;
struct node {
	node* next;
	float val;
	float weight;
	float parent;
	unsigned dist;
	unsigned index;
	colour c;
};

typedef struct graph graph;
struct graph {
	unsigned vertices;
	node list[];
};

/**
 * graph_init - initialise a graph object with `v` vertices. Use this
 * function on an uninitalised graph. Each graph initialised with
 * this function must be destroyed with a call to `graph_destroy`.
 */
graph* graph_init(graph* g, unsigned v);

/**
 * graph_destroy - destroy the linked lists in each slot of the
 * adjacency list representing the graph.
 */
void graph_destroy(graph* g);

/**
 * graph_edge - defines the existence of an undirected edge between two vertices
 * represented by their index in the adjacency list.
 */
graph* graph_edge(graph* g, unsigned src, unsigned dest, float weight);


void graph_fput(graph*g, FILE* s);

static
inline
void graph_delete(graph* g) {
	graph_destroy(g);
	free(g);
	g = 0;
}

/**
 * graph_new - allocate and initialise a graph object with
 * maximally `v` vertices.
 **/
[[nodiscard("Pointer to allocated graph object dropped.")]]
[[__gnu__::__malloc__]]
static
inline
graph* graph_new(unsigned v) {
	size_t size = offsetof(graph, list) + sizeof(node[v]);
	if (size < sizeof(graph))
		size = sizeof(graph);
	return graph_init((graph*)malloc(size), v);
}

/**
 * bfs - breadth-first search of graph G starting at the
 * source vertex denoted by the index s.
 */
void bfs(graph* G, unsigned s);

#endif
