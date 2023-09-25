#include "list.h"

/**
 * menu - picks the users choice on what to do to the list
 * Return: user's choice
 */

int menu(void)
{
	int ch;

	puts("A)dd, S)how, M)odify, D)elete, Q)uit");
	printf("Enter your choice: ");
	ch = getchar();
	while (getchar() != '\n')
		;
	return (toupper(ch));
}

