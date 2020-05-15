#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack_array.h"
//#include "queue.h"

struct vertex *gr_get_vertex(struct graph *gr, char n)
{
	//TODO: correlation of vertex name and index can be kept more efficiently in a hash table or a binary tree
	for (int i = 0; i < gr->count; i++)
		if (gr->vert[i]->name == n)
			return gr->vert[i];
	return NULL;
}

int gr_get_vertex_indx(struct graph *gr, char n)
{
	//TODO: correlation of vertex name and index can be kept more efficiently in a hash table or a binary tree
	for (int i = 0; i < gr->count; i++)
		if (gr->vert[i]->name == n)
			return i;
	return -1;
}

int check_cyclic(struct graph *gr, int parent, int indx)
{
	for (int i = 0; i < gr->count; i++) {
		// check if it is not parent
		//if (gr->vert[i] != gr->vert[parent] && i != indx) {
		if (i != parent && i != indx) {
			printf("i %d parent %d indx %d vert[i]->vis=%d\n", i, parent, indx, gr->vert[i]->visit);
			if (gr->adj_matrx[indx][i] != 0 && gr->vert[i]->visit == 1) {
				return 1;
			}
		}
	}
	return 0;
}

void gr_dfs_iter(struct graph *gr, int indx, char *traversal)
{
	// TODO:1 replace visited in struct with array
	struct sa_stack *st = sa_init();
	sa_push(st, indx);
	gr->vert[indx]->visit = 1;
	int travindx = 0;
	int is_cyclic = 0;
	traversal[travindx++] = gr->vert[indx]->name;
	int parent = -1;
	while (!sa_isempty(st)) {
		for (int i = 0; i < gr->count; i++) {
			if (gr->adj_matrx[indx][i] != 0 && gr->vert[i]->visit == 0) {
				gr->vert[i]->visit = 1;
				sa_push(st, i);
				traversal[travindx++] = gr->vert[i]->name;
			}
		}
		if (is_cyclic == 0 && parent != -1)
			is_cyclic = check_cyclic(gr, parent, indx);
		parent = indx;
		indx = sa_pop(st);
	}
	sa_free(st);
	
	printf("is_cyclic = %d\n", is_cyclic);

	// reset visited
	for (int i = 0; i < gr->count; i++)
		gr->vert[i]->visit = 0;
}

void gr_dfs(struct graph *gr, char n, char *trav)
{
	//struct vertex *v = gr_get_vertex(gr, n);
	int vindx = gr_get_vertex_indx(gr, n);
	//char *trav = (char *) malloc(gr->count * sizeof(char));
	gr_dfs_iter(gr, vindx, trav);
}

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
		gr->vert[gr->count]->visit = 0;
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
