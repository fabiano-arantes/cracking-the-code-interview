#include <utilcci.h>
#include <stdio.h>
#include "common.h"


int main(int argc, char * argv[])
{
	node *head = NULL;
	node *first = NULL;
	node *second = NULL;
	node *past = NULL;

	fill_linked_list(&head);

	print_linked_list(head);

	first = head;

	while(first != NULL)
	{
		second = first->next;
		past = second;

		DBG("first[%p] = %d", first, first->d);
		while(second)
		{
			DBG("second[%p] = %d", second, second->d);
			if(second->d == first->d)
			{
				DBG("Duplicate found: %d", second->d);
				past->next = second->next;
				free(second);

				if(past->next == NULL)
				{
					break;
				}

				second = past;
			}
			past = second;
			second = second->next;
		}

		first = first->next;
	}

	print_linked_list(head);

	free(head);

	return 0;
}
