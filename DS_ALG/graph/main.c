#include "graph.h"

int main(void) {
	graph* G = graph_new(5);

	graph_edge(G, 0, 1, 1);
	graph_edge(G, 1, 0, 1);
	graph_edge(G, 0, 4, 1);
	graph_edge(G, 4, 0, 1);
	graph_edge(G, 1, 4, 1);
	graph_edge(G, 4, 1, 1);
	graph_edge(G, 1, 3, 1);
	graph_edge(G, 3, 1, 1);
	graph_edge(G, 1, 2, 1);
	graph_edge(G, 2, 1, 1);
	graph_edge(G, 2, 3, 1);
	graph_edge(G, 3, 2, 1);
	graph_edge(G, 3, 4, 1);
	graph_edge(G, 4, 3, 1);

	graph_fput(G, stdout);
	bfs(G, 0);
	graph_delete(G);
	return 0;
}
