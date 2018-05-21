//Jason Chen
//Jadchen 1467583
//PA5

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#define MAX_LEN 250

int main(int argc, char* argv[]) {
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	int order; //get the Order of the graph
	fscanf(in, "%d", &order);
	Graph G = newGraph(order);

	int vertex, adj; //record the graph before 0 0
	fscanf(in, "%d %d", &vertex, &adj);
	while (!(vertex == 0 && adj == 0)) {
		addArc(G, vertex, adj);
		fscanf(in, "%d %d", &vertex, &adj);
	}

	//Print the recorded graph
	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, G);

	//create a List that contain the order of vertices
	List L = newList();
	for (int i = 1; i <= getOrder(G); i++) {
		append(L, i);
	}

	//Transpose the recorded graph
	DFS(G, L);
	Graph T = transpose(G);
	DFS(T, L);

	// find number of strongly connected components
	int scc = 0;
	for (moveFront(L); index(L) >= 0; moveNext(L)) {
		if (getParent(T, get(L)) == NIL) {
			scc++;
		}
	}

	//create a list of strong connected components
	List Lscc[scc];
	for (int i = 0; i < scc; i++) {
		Lscc[i] = newList();
	}
	int j = scc;
	for (moveFront(L); index(L) >= 0; moveNext(L)) {
		if (getParent(T, get(L)) == NIL) {
			j--;
		}
		append(Lscc[j], get(L));
	}
	printList(out, L);
	//print out the list of connected components in order
	fprintf(out, "\nG contains %d strongly connected components:", scc);
	for (int i = 0; i < scc; i++) {
		fprintf(out, "\nComponent %d: ", i + 1);
		printList(out, Lscc[i]);
		freeList(&(Lscc[i]));
	}

	//Free memory
	freeGraph(&G);
	freeGraph(&T);
	freeList(&L);

	fclose(in);
	fclose(out);
}
