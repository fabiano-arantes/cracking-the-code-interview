#include <stdlib.h>

#ifdef DEBUG
	#define DBG(x, ...) printf(x"\n", __VA_ARGS__)
#else
	#define DBG(x, ...)
#endif

typedef struct str_node_int{
	int d;
	struct str_node_int *next;
} node_int;

node_int *new_node_int(const int d, node_int *parent);

void fill_linked_list_int(node_int **phead);

void print_linked_list_int(node_int *head);
