
struct heap *pq_init(int len);
void pq_insert(struct heap *h, int n);
int pd_peek_min(struct heap *h);
int pd_extract_min(struct heap *h);
void pq_free(struct heap* h);
