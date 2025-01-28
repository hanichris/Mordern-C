#include <limits.h>
#include <math.h>

#include "graph.h"
#include "queue.h"


graph* graph_init(graph *g, unsigned v) {
	if (g) {
		float value;
		g->vertices = v;

		puts("Enter the node values for the graph.");
		for (unsigned i = 0; i < v; i++) {
			fprintf(stdout, "Node [%u]: ", i);
			scanf("%g", &value);
			g->list[i].val = value;
			g->list[i].c = WHITE;
			g->list[i].parent = NAN;
			g->list[i].weight = 1.0;
			g->list[i].dist = UINT_MAX;
			g->list[i].index = i;
			g->list[i].next = nullptr;
		}
	}
	return g;
}

void graph_destroy(graph* g) {
	if (g) {
		for (unsigned i = 0; i < g->vertices; i++) {
			node* cur = g->list[i].next;
			while (cur) {
				node* tmp = cur;
				cur = cur->next;
				free(tmp);
			}
			g->list[i].next = nullptr;
		}
	}
}

graph* graph_edge(graph* g, unsigned src, unsigned dest, float weight) {
	if (!g || src >= g->vertices || dest >= g->vertices)
		return g;
	node* n = malloc(sizeof(node));
	if (!n) {
		perror("Unable to allocate memory.");
		return g;
	}
	n->c = WHITE;
	n->val = g->list[dest].val;
	n->index = dest;
	n->weight = weight;
	n->parent = NAN;
	n->dist = UINT_MAX;
	n->next = g->list[src].next;
	g->list[src].next = n;
	return g;
}

void graph_fput(graph*g, FILE* s) {
	if (g) {
		unsigned count = g->vertices;
		fprintf(s, "%p+%u: \n", (void*)g->list, count);

		for (unsigned i = 0; i < count; i++) {
			fprintf(s, "(%g)=>", g->list[i].val);
			node* cur = g->list[i].next;
			while (cur) {
				fprintf(s, " (%g)-", cur->val);
				cur = cur->next;
			}
			fputs("-|\n", s);
		}
		return;
	}
	fputs("Invalid graph.\n", s);
}

void bfs(graph* G, unsigned s) {
	if (!G || s >= G->vertices)
		return;
	G->list[s].c = GREY;
	G->list[s].dist = 0;

	queue* Q = queue_new(G->vertices);
	queue_enqueue(Q, s);

	while (queue_getcount(Q) > 0) {
		unsigned idx = queue_dequeue(Q);
		printf("Processing node value: %g", G->list[idx].val);
		for (node* cur = G->list[idx].next; cur; cur = cur->next) {
			node* tmp = &G->list[cur->index];
			if (tmp->c == WHITE) {
				tmp->c = GREY;
				cur->c = GREY;
				tmp->dist = G->list[idx].dist + 1;
				cur->dist = G->list[idx].dist + 1;
				tmp->parent = idx;
				cur->parent = idx;
				queue_enqueue(Q, cur->index);
			}
		}
		G->list[idx].c = BLACK;
		printf("\rFinished processing node value: %g\n", G->list[idx].val);
		fflush(stdout);
	}
	puts("FIN!");
	queue_delete(Q);
}
