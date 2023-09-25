#include "list.h"

/**
 * create_node - creates the nodes in the list
 * Return: pointer to the created node
 */
struct shoe_stock *create_node(void)
{
	struct shoe_stock *node;

	node = (struct shoe_stock *)malloc(sizeof(struct shoe_stock) * 1);
	if (node == NULL)
	{
		puts("FAILED MEMORY ALLOCATION");
		exit(1);
	}
	return (node);
}

