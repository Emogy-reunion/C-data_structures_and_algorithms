#include "list.h"

/**
 * fill_node - fills the nodes in the list with data
 * @current: pointer to the current node in the list
 * Return: nothing
 */

void fill_node(struct shoe_stock *current)
{
	char kicks_name[21];

	printf("\nEnter name of the shoes: ");
	fgets(kicks_name, 21, stdin);
	strcpy(current->shoe_name, kicks_name);
	printf("Enter shoes size: ");
	scanf("%d", &current->size);
	printf("Enter number of shoe pairs in stock: ");
	scanf("%d", &current->quantity);
	printf("Enter price of one pair of shoe: ");
	scanf("%lf", &current->price);
	while (getchar() != '\n')
		;
	save_list();
}
