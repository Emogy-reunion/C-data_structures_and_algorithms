#include "list.h"

/**
 * save_list - saves the list to a file in binary
 * this preserves the data between program execution
 * Return: 0 on success
 */
int save_list(void)
{
	FILE *file;
	struct shoe_stock *current;

	file = fopen("list.db", "wb");
	if (file == NULL)
	{
		perror("Error in opening the file for writing");
		return (1);
	}
	current = first;
	while (current)
	{
		if (fwrite(current, sizeof(struct shoe_stock), 1, file) != 1)
		{
			perror("Error in writing to the file");
			return (1);
		}
		current = current->next;
	}
	fclose(file);
	return (0);
}

