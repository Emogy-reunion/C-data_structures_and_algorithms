#include "list.h"

/**
 * delete_node - deletes a node in the list
 * Return: nothing
 */
int delete_node()
{
	int record_no;
	int to_delete;
	struct shoe_stock *current;
	struct shoe_stock *previous;

	if (first == NULL)
	{
		puts("NO RECORDS TO DELETE");
		return (1);
	}
	show_list();
	printf("\nENTER RECORD NUMBER OF RECORD TO DELETE: ");
	scanf("%d", &to_delete);
	while (getchar() != '\n')
		;

	record_no = 1;
	current = first;
	previous = NULL;
	while (current != NULL && record_no != to_delete)
	{
		previous = current;
		current = current->next;
		record_no++;
	}

	if (current == NULL)
	{
		puts("RECORD DOESN'T EXIST");
		return (1);
	}
	if (previous == NULL)
	{
		first = current->next;
	}
	else
	{
		previous->next = current->next;
	}
	printf("RECORD %d REMOVED SUCCESSFULLY\n", record_no);
	save_list();
	free(current);
	return (0);
}
