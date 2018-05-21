//Jason Chen
//Jadchen 1467583
//PA4

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(int argc, char* argv[]) {
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	int order; //get the Order of the graph
	fscanf(in, "%d", &order);
	Graph G = newGraph(order);

	int vertex, adj; //read in the graph before 0 0
	fscanf(in, "%d %d", &vertex, &adj);
	while (!(vertex == 0 && adj == 0)) {
		addEdge(G, vertex, adj);
		fscanf(in, "%d %d", &vertex, &adj);
	}

	printGraph(out, G);

	List L = newList();
	int source, dest;

	fscanf(in, "%d %d", &source, &dest); //read in the paths that are required to find before the second 0 0
	while (!(source == 0 && dest == 0)) {
		BFS(G, source);
		getPath(L, G, dest);
		if (length(L) == 0) {
			fprintf(out, "\nThe distance from %d to %d is infinity\n", source,
					dest);
			fprintf(out, "No %d-%d path exists\n", source, dest);
		} else {
			fprintf(out, "\nThe distance from %d to %d is %d\n", source, dest,
					getDist(G, dest));
			fprintf(out, "A shortest %d-%d path is: ", source, dest);
			printList(out, L);
			fprintf(out, "\n");
		}
		clear(L);
		fscanf(in, "%d %d", &source, &dest);
	}

	freeGraph(&G);
	freeList(&L);
	fclose(in);
	fclose(out);
}
