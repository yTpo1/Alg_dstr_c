struct vertex {
	char name;
};

struct graph {
	struct vertex **vert;
	int **adj_matrx;
	int count; //index
	int size;
};

struct graph *gr_init(int size);
void gr_insert_vertex(struct graph *gr, char name);
void gr_connect_vertices(struct graph *gr, int x, int y);
void gr_delete(struct graph *gr);
