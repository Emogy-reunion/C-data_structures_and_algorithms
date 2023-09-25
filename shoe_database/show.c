#include "list.h"

/**
 * show_list - prints the records in the database
 * Return: nothing
 */

void show_list()
{
	int record_no = 1;
	struct shoe_stock *current;

	if (first == NULL)
	{
		puts("NO RECORDS IN THE DATABASE");
		return;
	}
	puts("\nEMOGY@EMOGY MAGICLAND INVENTORY");
	printf("NO\tNAME\t\tSIZE\tQUANTITY\tPRICE\t\tTOTAL\n");
	current = first;
	while (current)
	{
		printf("%d:\t%-15s\t%-4d\t%-d\t%.2lf\t\t%.2lf\n", record_no, current->shoe_name, current->size, current->quantity, current->price, current->price * current->quantity);
		current = current->next;
		record_no++;
	}
}
