#include <stdlib.h>
#include "graph.h"

struct graph *gr_init(int size)
{
	struct graph *vert = (struct graph *) malloc(sizeof(struct graph));
	vert->adj_matrx = (int **) malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++)
		vert->adj_matrx[i] = (int *) malloc(sizeof(int));
		//vert->adj_matrx[i] = NULL;

	vert->size = size;
	vert->count = 0;

	struct vertex **vertices = (struct vertex **) malloc(size * sizeof(struct vertex *));
	vert->vert = vertices;
	for (int i = 0; i < size; i++)
		vert->vert[i] = NULL;

	return vert;
}

void gr_insert_vertex(struct graph *gr, char name)
{
	if (gr->count < gr->size) {
		gr->vert[gr->count] = (struct vertex *) malloc(sizeof(struct vertex));

		gr->vert[gr->count]->name = name;
		gr->count++;
	}

}

void gr_connect_vertices(struct graph *gr, int x, int y)
{
	//if (gr->adj_matrx[x] != NULL)
	//if (gr->adj_matrx[y] != NULL)
	//gr->adj_matrx[x] = (int *) malloc(sizeof(int));
	//gr->adj_matrx[y] = (int *) malloc(sizeof(int));
	gr->adj_matrx[x][y] = 1;
	gr->adj_matrx[y][x] = 1;
}

void gr_delete(struct graph *gr)
{
	for (int i = 0; i < gr->size; i++) {
		if (gr->vert[i] != NULL) {
			free(gr->vert[i]);
			gr->vert[i] = NULL;
		}
		//free(gr->adj_matrx[i]);
		if (gr->adj_matrx[i] != NULL) {
			free(gr->adj_matrx[i]);
			//for (int j = 0; j < gr->size; j++)
			//	gr->adj_matrx[i][j] = NULL;
		}
	}
	free(gr->vert);
	gr->vert = NULL;
	free(gr->adj_matrx);
	gr->adj_matrx = NULL;
	free(gr);
}
