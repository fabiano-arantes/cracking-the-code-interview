typedef struct str_node{
	int d;
	struct str_node *next;
} node;

node *new_node(const int d, node *parent);

void fill_linked_list(node **phead);

void print_linked_list(node *head);
