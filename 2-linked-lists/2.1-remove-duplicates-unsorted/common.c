#include <utilcci.h>
#include <stdio.h>

typedef struct str_node{
	int d;
	struct str_node *next;
} node;

node *new_node(const int d, node *parent)
{
	node *n = NULL;

	n = malloc(sizeof(node));	
	
	if(n == NULL)
	{
		return NULL;
	}

	n->d = d;
	n->next = NULL;

	if(parent)
	{
		parent->next = n;
	}

	return n;
}

void fill_linked_list(node **head)
{
	node *tmp = NULL;
	int count, v;

	printf("Number of elements: ");
	scanf("%d", &count);

	while(count > 0)
	{
		--count;

		scanf("%d", &v);

		tmp = new_node(v, tmp);

		if(!*head)
		{
			*head = tmp;
		}
	}

}

void print_linked_list(node *head)
{
	node *tmp = head;
	
	while(tmp != NULL)
	{
		printf("%d", tmp->d);
		
		if(tmp->next != NULL)
		{
			printf("->");
		}
		
		tmp = tmp->next;
	}
	printf("\n");
}

