#include "list.h"

/**
 * load_new - prompts user to select either load database or new database
 * Return: 0 on success
 */
int load_new(void)
{
	int choice = 0;

	while (1)
	{
		puts("Press L to load existing database, if it doesn't exist it will be created");
		puts("press N to create a new database. Existing data will be lost");
		choice = getchar();
		choice = toupper(choice);
		while (getchar() != '\n')
			;

		if (choice == 'L')
		{
			load_list();
			puts("Database loaded successfully");
		}
		else if (choice == 'N')
		{
			puts("New database");
		}
		else
		{
			puts("Invalid choice!");
		}
		if (choice == 'L' || choice == 'N')
			break;
	}
	return (0);
}
			
