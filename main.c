/*Address Book Project Description

PROJECT NAME : ADDRESS BOOK

Developed a C-based Address Book application to manage contacts efficiently.
The project supports creating, searching, editing, deleting, and listing contacts.
Contacts can be searched using name, phone number, or email.
Implemented input validation, bubble sorting, and file handling for permanent data storage.
Used structures, pointers, strings, functions, and file operations to build the application.*/

#include <stdio.h>
#include "contact.h"


int main() 
{
    int choice;
    AddressBook addressBook;

    addressBook.Contactcount = 0;
    initialize(&addressBook); // Initialize the address book

    do 
    {
printf("\n");
printf("=================================================\n");
printf("                 ADDRESS BOOK                    \n");
printf("=================================================\n");
printf("|  1.  Create Contact                           |\n");
printf("|  2.  Search Contact                           |\n");
printf("|  3.  Edit Contact                             |\n");
printf("|  4.  Delete Contact                           |\n");
printf("|  5.  List All Contacts                        |\n");
printf("|  6.  Save and Exit                            |\n");
printf("|  7.  Exit Without Saving                      |\n");
printf("=================================================\n");
printf("Enter your choice: ");
if(scanf("%d", &choice) != 1)
{
    choice = 8;
    while(getchar() != '\n');
}
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                 searchContact(&addressBook);
                break;
            case 3:
                  editContact(&addressBook);
                break;
            case 4:
                  deleteContact(&addressBook);
                break;
            case 5:          
                 listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
