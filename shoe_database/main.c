#include "list.h"

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	int choice = 0;
	
	first = NULL;
	load_new();
	while (1)
	{
		puts("\nCHOOSE AN OPTION DEPENDING ON WHAT YOU WANT TO DO TO THE DATABASE");
		choice = menu();
		switch (choice)
		{
			case 'A':
				add_node();
				break;
			case 'S':
				show_list();
				break;
			case 'M':
				modify_list();
				break;
			case 'D':
				delete_node();
				break;

			case 'Q':
				break;
			default:
				puts("Invalid choice, try again!");
		}
		if (choice == 'Q')
			break;
	}
	return (0);
}
