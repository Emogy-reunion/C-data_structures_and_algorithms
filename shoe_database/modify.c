#include "list.h"

/**
 * modify_list - modifies the records in the list
 * Return: nothing
 */
int modify_list()
{
	int record_no;
	int to_modify;
	struct shoe_stock *current;

	if (first == NULL)
	{
		puts("NO RECORDS IN THE DATABASE");
		return (1);
	}
	show_list();
	printf("\nENTER NUMBER OF THE RECORD TO MODIFY: ");
	scanf("%d", &to_modify);
	while (getchar() != '\n')
		;
	record_no = 1;
	current = first;
	while (current != NULL && record_no != to_modify)
	{
		current = current->next;
		record_no++;
	}
	if (current == NULL)
	{
		puts("RECORD NOT FOUND");
		return (1);
	}
	fill_node(current);
	printf("RECORD %d MODIFIED SUCCESSFULLY\n", record_no);
	save_list();
	return (0);
}

