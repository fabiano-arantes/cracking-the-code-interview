#include "utilcci.h"
#include <stdio.h>

node_int *new_node_int(const int d, node_int *parent)
{
	node_int *n = NULL;

	n = malloc(sizeof(node_int));

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

void fill_linked_list_int(node_int **head)
{
	node_int *tmp = NULL;
	int count, v;

	printf("Number of elements: ");
	scanf("%d", &count);

	while(count > 0)
	{
		--count;

		scanf("%d", &v);

		tmp = new_node_int(v, tmp);

		if(!*head)
		{
			*head = tmp;
		}
	}

}

void print_linked_list_int(node_int *head)
{
	node_int *tmp = head;

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

