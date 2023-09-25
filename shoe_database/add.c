#include "list.h"

/**
 * add_node - adds a node in the list
 * Return: 0 on success
 */

int add_node()
{
	struct shoe_stock *current;
	struct shoe_stock *new;

	if (first == NULL)
	{
		first = create_node();
		current = first;
	}
	else
	{
		current = first;
		while (current->next)
		{
			current = current->next;
		}
		new = create_node();
		current->next = new;
		current = new;
	}
	fill_node(current);
	return (0);
}
