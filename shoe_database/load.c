#include "list.h"

/**
 * load_list - loads the list from a binary file
 * it brings up records in the database
 * Return: 0 on success
 */
int load_list(void)
{
	FILE *file;
	struct shoe_stock *temp;
	struct shoe_stock record;
	struct shoe_stock *new_node;
	struct shoe_stock *current;

	file = fopen("list.db", "rb");
	if (file == NULL)
	{
		perror("No database to load or error in opening file");
		return (1);
	}
	/*clears existing database*/
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		free(temp);
	}
	/*reads records from the file and adds them to the database*/
	while (fread(&record, sizeof(struct shoe_stock), 1, file) == 1)
	{
		/*create node to store the data*/
		new_node = create_node();
		/*copy data from the loaded record to the new node*/
		memcpy(new_node, &record, sizeof(struct shoe_stock));
		if (first == NULL)
		{
			first = new_node;
			current = first;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
	}
	fclose(file);
	return (0);
}
