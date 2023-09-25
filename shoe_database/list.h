#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * shoe_stock - used to create every node in the linked list
 * @shoe_name: stores the name of the type of shoe
 * @size: stores the size of the shoe
 * @quantity: stores the number of pairs of shoes in stock
 * @price: stores the price of one pair
 * @next: pointer to the next node in the list
 */
struct shoe_stock
{
	char shoe_name[21];
	int size;
	int quantity;
	double price;
	struct shoe_stock *next;
};
struct shoe_stock *first;

int menu(void);
int add_node();
struct shoe_stock *create_node(void);
void fill_node(struct shoe_stock *current);
void show_list(void);
int modify_list(void);
int delete_node(void);
int save_list(void);
int load_list(void);
int load_new(void);

#endif
