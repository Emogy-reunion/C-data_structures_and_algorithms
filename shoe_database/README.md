## CREATING DATABASE USING LINKED LISTS IN C
* The code below is a database I created using LINKED LISTS
* The database keeps an inventory for the EMogy@EMogy magicland kicks business
* It also calculates the value of the stock
* The database can do the following:
1. Add a new node to the list
2. Fill the list with data
3. Display the list's data
4. Delete items from the list
5. Modify the list's data
6. Save the data in files
7. Load saved data from files

## TECHNOLOGIES USED
1. C PROGRAMMING LANGUAGE
2. Compiled using GCC 
3. Tested on UBUNTU 20.04.6 LTS

##  FILES AND WHAT THEIR FUNCTIONS DO
## MAIN.C
* The main.c file contains the main() function
* The main() function serves as the entry point to the program
* First it declares the variable choice and declares it to 0
* This variable is used to store the user's choice on what they want to do to the database
* The it initializes first (the head node in the list) to NULL to show that the list is initially empty
* It calls the load_new() function which loads an existing database from a file
* The function starts an infinite loop
* In the loop, the menu() function is called and it's return values is stored in the choice variable
* The menu() function provides the user with a menu to choose what he wants to do to the database
* A switch case statement begins, with the choice value as it's expression
* If the user's choice is A, the add_node() function is called - it adds a new node to the list
* If S, the show_list() function is called - it prints the database
* if user's choice is M, the mmodify_list function is called - modifies data in the nodes
* If D, the delete_node() function is called - it deletes a node in the list
* If user's choice is Q, the program breaks out of the switch-case statement and the endless while loop thus close the database
* If any other choice was entered the default statement is executed, it prints that you have entered an invalid choice and you are asked to try again

## LOAD_NEW.C
* It contains the load_new() function
* The function prompts the user to either load database or create a new database
* First, it declares a choice variable which store's the user's choice
* An infinite loop is spinned
* The while loops statements are executed
* Pressing L loads an existing database, while pressing N creates a new database overwriting the existing one
* The getchar() function gets the input from the user and stores it in the choice variable
* The the toupper() function is used to convert the user's choice to uppercase
* The while (getchar() != '\n') reads and discards any remaining characters in the stdin until a newline character is encountered
* The if-else ladder is used to make decisions based on the user's input
* If the user entered L, the if statements are executed, the load_list() function is called and it loads the database from the files
* If the user entered N, the else if statements are executed and a new database is created ddiscarding the existing one
* If the user didn't enter any of the above, the else statement is executed, printing the user entered an invalid choice
*  The second if statement is used to break out of the infinite loop
* If the user's choice is either L or N it evaluates to true thus breaking out of the loop, otherwise the loop spins forever

## MENU.C
* The menu.c file contains the menu() function
* The menu function picks the user's choice on what they want to do to their database
* A variable ch is declared to store the user's pick
* The menu is displayed, A for add, S for show, M for modify, D for delete, and Q for quit
* The getchar() function picks the user's input and stores it in the ch variable
* Any remaining characters that might have been entered are discarded
* The function returns the uppercase of the user's input

## LOAD.C
* The load.c file contains the load_list() function
* The function loads an existing database from a file
* This function declares a file pointer which will point to the file we are reading from
* variables of the type struct shoe_stock are declared, temp to help clear any existing databaase, record stores the node being read, new_node points to the new node created to store the node in the record variable, current to help iterate through the database
* The file is opened in read mode using fopen()
* If the file didn't open, the neccesary error messages were printed
* A loop is used to clear any existing database, If first is not equal to NULL, it means that the database is not empty, the while loop clears that database
* The we read each node one at a time using a loop, the data is stored in the record variable temporarily
* Then a new_node is created - the node will hold the data that is being read
* We use memcpy() to copy the data from the record variable to the new node
* The if-else statement is used to make decisions
* If first == NULL, it means that the list is empty thus first will be assigned the new node
* The current is set to point to first
* If first != NULL, it means the list is not empty, thus the next pointer of the current node is set to point to the new node then current is updated to point to the new_node
* The file is closed when all data has been read and the file returns 0

## ADD.C
* Contains the add_node function
* This function adds a new node to the list
* Two struct pointers are declared, current points to the node being worked on and new points to the newly created node
* In the if-else statement, if first is equal to null, it means the list is empty we have to create a new node
* The create_node(0 function is called and its return value is assigned to first (head node)
* Then current is set to point to first
* Otherwise, when first is not null, the if statements are skipped and else statements executed
* Current is set to point to first since we traverse a linked list from the first node
* We use a while loop to traverse the linked list, if current->next is not NULL it means we haven't reached the end of the list
* Inside the loop current is set to point to the next node in the list
* Once the next pointer of the current node is NULL it means we have reached the end of the list thus exiting the loop
* Then the create_node() function is called and it's return value is assigned to new
* The next pointer of the current node is set to point to the new node thus linking them together
* Then current is set to point to the new node
* The fill_node() function is called and current is passed as an argument

## CREATE.C
* It contains the create_node() function
* This function allocates memory for a new node
* A struct pointer node is declared to hold the address of the allocated memory
* malloc is used to allocate memory same as the size of the shoe_stock struct
* If memory allocation fails, malloc() returns NULL
* The address to the newly created node is returnedd

## FILL.C
* Contains the fill_node() function
* It is used to fill each node in the list with data
* When filling is complete, it calls the save_list() function to save the data to a file

## SAVE.C
* Contains the save_list() function
* It saves the database to a file
* This prevents data loss when the program quits
* A file pointer is declared to point to the address of the file
* A current pointer is declared to help traverse the list
* The file is opened in write mode using the fopen() function
* If there were issues during the opening of the file fopen() returns a NULL pointer and an error message displayed
* Then current is set to point to first since we start traversing a list from the first node
* A while loop is spinned, it spins as long as current doesn't point to NULL meaning we have reached the end of the list
* If the loop fwrite() is used to write data in the current node to the file, if fwrite() doesn't return 1, it means there was an error when in writing and an error message is displayed
* The current is set to point to the next node, the loop spins until the end of the list is reached
* The file is then closed and 0 returned to indicate success

## MODIFY.C
* Contains the modify_list() function
* It is used to modify the data in the database
* Three variables are declared, record_no to keep count of the record number, to_modify to store the record the user wants to modify, current to help traverse the list
* We check if first is NULL meaning the list is empty
* If the list is empty the function is exited
* The show_list() function is called to display the list
* The user chooses the record they want to modify and the choice is stored in the to_modify variable
* An remaining characters are discarded
* Record_no is set to 1
* A while loop spins, the conditions being, current should not be NULL and Record_no should not be equal to the to_modify value
* Inside the loop, current is set to point to the next node and record_no is incremented by 1
* If current equals NULL it means we have reached the end of the loop without finding the record we wanted to modify so we exit the function
* If we record_no = to_modify it means we have found the node we want to modify
* Thus the fill_node function is called and we pass the current node as an argument
* Once the node is modified, the save_list() function is called to save the changes
* We exit the function with a success status

## SHOW.C
* Contains the Show_list() function
* It prints the records in the database
* Two variables are declared, record_no to keep count of the record number, current to traverse the listt
* If first is NULL, it means the list is empty so we quit the function since we have nothing to print
* Current is set to first
* A while loop is used to print the database node by node
* It spins as long as current is not equal to NULL - meaning we haven't reached the end of the list
* Inside the loop we print data for each node one by one
* Once we print data for one node, current is set to point to the next node
* The record number counter is updated as well

## DELETE.C
* Contains the delete_node() function
* It removes a node from the list
* Inside the function, four variables are declared, record_no to keep count of the record number, to_delete to store the user's choice of the record they want to delete, current to help traverse the list, previous to keep track of the previous node while traversing the list
* we check if the list is empty, if it is we exit the function
* The show_list() function is called to display the records in the database
* The user is then prompted to enter the record number of the record they want to delete and the input is stored in the to_delete variable
* record_no is set to 1 and current is set to point to the first node in the list
* Previous is set to NULL to show that the first record has no previous node
* A while loop spins as long as current is not null, and the record_no is not equal to to_delete meaning we haven't found the record we want to delete
* Inside the loop, previous is set to point to the current node and current is set to point to the next node
* If current is NULL it means we have reached the end of the list without finding the record ro be deleted, thus the function is exited because the record doesn't exist
* If record_no equals to_delete, it means we have found the record we want to delete
* We use if-else for decision making
* If previous is NULL it means we are deleting the first node, so first is set to point to the next node effectively removing the first record
* Otherwise, the else statements are executed, the next pointer of the previous node is set to point to the next node, thus linking the previous node and the next node effectively removing the current node
* The the save_list() function is called to save the changes
* The memory held by the deleted node is freed and we return 0 indicating success
