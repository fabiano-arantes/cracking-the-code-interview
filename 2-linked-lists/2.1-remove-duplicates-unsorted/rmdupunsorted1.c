#include <utilcci.h>
#include <stdio.h>
#include "common.h"

static node *sorted_list = NULL;

int check_duplicate(int value)
{
	node *tmp;
	node *last = NULL;
	node *n = NULL;

	if(sorted_list == NULL)
	{
		DBG("Creating sorted list: %d", value);
		sorted_list = new_node(value, NULL);
		return 0;
	}

	tmp = sorted_list;
	last = sorted_list;

	while(tmp)
	{
		if(value > tmp->d)
		{
			DBG("value > tmp->d : %d > %d", value, tmp->d);
			last = tmp;
			tmp = tmp->next;
		}
		else if(tmp->d == value)
		{
			return 1;
		}
		else
		{
			DBG("New unique value: %d", value);
			n = new_node(value, last);
			n->d = value;
			n->next = tmp;

			return 0;
		}
	}

	DBG("New unique value: %d", value);
	n = new_node(value, last);
	n->d = value;

	return 0;
}

int main(int argc, char * argv[])
{
	node *head = NULL;
	node *n = NULL;
	node *last = NULL;

	fill_linked_list(&head);

	print_linked_list(head);

	n = head;

	while(n != NULL)
	{
		DBG("Checking [%p] = %d", n, n->d);
		if(check_duplicate(n->d))
		{
			DBG("Duplicate found: %d", n->d);
			last->next = n->next;
			free(n);

			if(last->next == NULL)
			{
				break;
			}

			n = last;
		}
		last = n;
		n = n->next;
	}

	print_linked_list(head);

	free(head);

	return 0;
}
