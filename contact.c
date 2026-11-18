#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"


void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria

    // Bubble sort
    Contact temp;
    for(int i=0;i<addressBook->Contactcount-1;i++)
    {
        for(int j=0;j<addressBook->Contactcount-1-i;j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] =  temp;
            }
        }
    }

    //Loop from 0 to addressBook->contactCount;
   printf("\n");
printf("=============================================================================\n");
printf("| %-4s | %-25s | %-15s | %-25s |\n",
       "S.No", "Name", "Phone", "Email");
printf("=============================================================================\n");

for(int i = 0; i < addressBook->Contactcount; i++)
{
    printf("| %-4d | %-25s | %-15s | %-25s |\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
}

printf("=============================================================================\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->Contactcount = 0;
    //populateAddressBook(addressBook);
    loadContactsFromFile(addressBook);

    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
     if (addressBook->Contactcount >= MAX_CONTACTS)
    {
        printf("\n-------------------------------------------------\n");
        printf("  Address book is full! Delete a contact first.\n");
        printf("-------------------------------------------------\n");
        return;
    }
    char str[50], str1[50], str2[50]; 
    //this is string and last char is for '\0' NULL

    int res=0;
    do{
        printf("Enter the name : ");
        scanf(" %49[^\n]", str);

     res = validate_name(str);

    }while(res == 0);

    do{
        printf("Enter the phone : ");
        scanf("%49s", str1);

     res = validate_phone(str1);
     
          for(int i=0;i<addressBook->Contactcount;i++)
        {
            if(strcmp(str1,addressBook->contacts[i].phone) == 0)
            {
                printf("\n-------------------------------------------------\n");
                printf("  Phone number already exists in the Address Book!\n");
                printf("  Please enter a different phone number.\n");
                printf("-------------------------------------------------\n");
                res = 0;
                break;
                
            }
        }
    }while(res == 0);

    do{
        printf("Enter the email : ");
        scanf(" %49[^\n]", str2);

     res = validate_email(str2);

        for(int i=0;i<addressBook->Contactcount;i++)
        {
            if(strcmp(str2,addressBook->contacts[i].email) == 0)
            {
                printf("\n-------------------------------------------------\n");
                printf("  Email address already exists in the Address Book!\n");
                printf("  Please enter a different email address.\n");
                printf("-------------------------------------------------\n");
                res = 0;
                break;
                
            }
        }

    }while(res == 0);


   strcpy(addressBook->contacts[addressBook->Contactcount].name,str);
   strcpy(addressBook->contacts[addressBook->Contactcount].phone,str1);
   strcpy(addressBook->contacts[addressBook->Contactcount].email,str2);

   addressBook->Contactcount++;



    
}

//--------------------------------------------------------------------------------------------------------------

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    
    do
    {
       int index=-1;
   printf("\n");
printf("=================================================\n");
printf("                 SEARCH CONTACT                  \n");
printf("=================================================\n");
printf("|  1.  Search by Name                           |\n");
printf("|  2.  Search by Phone Number                   |\n");
printf("|  3.  Search by Email                          |\n");
printf("|  4.  Exit                                     |\n");
printf("=================================================\n");
printf("Enter your choice: ");
    
    if(scanf("%d", &choice) != 1)
{
    choice = 8;
    while(getchar() != '\n');
}
    
    switch(choice)
    {
        case 1:
            index = search_by_name(addressBook);
            break;
        case 2:
            index = search_by_phone(addressBook);
            break;
        case 3:
            index = search_by_email(addressBook);
            break;
        case 4:
             printf("Exiting from this menu\n");
             return;  
        default :
        printf("\n-------------------------------------------------\n");
        printf("  Invalid choice! Please enter a valid option.\n");
        printf("-------------------------------------------------\n");
        continue;
       
    }

    if(index<0)
    {
        printf("\n-------------------------------------------------\n");
        printf("  Contact not found! Please try again.\n");
        printf("-------------------------------------------------\n");
    }
    
}while( choice != 4);
  
}

//------------------------------------------------------------------------------------------------------------------

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;
    int choice2;
    int index=-1;
    do{
    printf("\n");
printf("=================================================\n");
printf("                  EDIT CONTACT                   \n");
printf("=================================================\n");
printf("|  1.  Search by Name                           |\n");
printf("|  2.  Search by Phone Number                   |\n");
printf("|  3.  Search by Email                          |\n");
printf("|  4.  Exit                                     |\n");
printf("=================================================\n");
printf("Enter your choice: ");

if(scanf("%d", &choice) != 1)
{
    choice = 8;
    while(getchar() != '\n');
}
    
    switch(choice)
    {
        case 1:
           index = search_by_name(addressBook);
            break;
        case 2:
            index = search_by_phone(addressBook);
            break;
        case 3:
            index = search_by_email(addressBook);
            break;
        case 4:
             printf("Exit from this menu\n");
             return;  
        default :
        printf("\n-------------------------------------------------\n");
        printf("  Invalid choice! Please enter a valid option.\n");
        printf("-------------------------------------------------\n");
        break;
    }
    }while(choice < 1 || choice > 4 );

        if(index<0)
    {
        printf("\n-------------------------------------------------\n");
        printf("  Contact not found! Please try again.\n");
        printf("-------------------------------------------------\n");
        
    }

    if(index>=0)
    {
        do{
        printf("\n");
printf("=================================================\n");
printf("                 EDIT FIELD                     \n");
printf("=================================================\n");
printf("|  1.  Edit Name                                |\n");
printf("|  2.  Edit Phone Number                        |\n");
printf("|  3.  Edit Email                               |\n");
printf("|  4.  Exit                                     |\n");
printf("=================================================\n");
printf("Enter your choice: ");

if(scanf("%d", &choice2) != 1)
{
    choice2 = 8;
    while(getchar() != '\n');
}
switch(choice2)
{
    case 1:
        edit_name(addressBook,index);
        break;
    case 2:
        edit_phone(addressBook,index);
        break;
    case 3: 
        edit_email(addressBook,index);
        break;
    case 4:
        printf("EXIT");
        return;
    default:
     printf("\n-------------------------------------------------\n");
        printf("  Invalid choice! Please enter a valid option.\n");
        printf("-------------------------------------------------\n"); 
}
} while(choice2 < 1 || choice2 > 4 );  
}
}

// ------------------------------------------------------****************** =================================================
void edit_name(AddressBook *addressBook,int index)
{
    char str[50];
    int res=0;
      do{
        printf("Enter the new name : ");
        scanf(" %49[^\n]", str);

     res = validate_name(str);

    }while(res == 0);

    strcpy(addressBook->contacts[index].name,str);
   printf("\n-------------------------------------------------\n");
printf("  Contact name updated successfully!\n");
printf("-------------------------------------------------\n");
    return;
}

// ------------------------------------------------------****************** =================================================


void edit_phone(AddressBook *addressBook,int index)
{
    char str1[50];
    int res = 0;
    do{
        printf("Enter the new phone number : ");
        scanf("%49s", str1);

     res = validate_phone(str1);
     //*************************************************************************************
     for(int i=0;i<addressBook->Contactcount;i++)
        {
           if(i != index && strcmp(str1, addressBook->contacts[i].phone) == 0)
            {
                printf("\n-------------------------------------------------\n");
printf("  Phone number already exists in the Address Book!\n");
printf("  Please enter a different phone number.\n");
printf("-------------------------------------------------\n");
                res = 0;
                break;
                
            }
        }
     
    }while(res == 0);

    strcpy(addressBook->contacts[index].phone,str1);
    printf("\n-------------------------------------------------\n");
printf("  Phone number updated successfully!\n");
printf("-------------------------------------------------\n");
    return;
}

// ------------------------------------------------------****************** =================================================


void edit_email(AddressBook *addressBook,int index)
{
    char str2[50];
    int res=0;
     do{
        printf("Enter the new email : ");
        scanf(" %49[^\n]", str2);

     res = validate_email(str2);
     //****************************************************************************************
       for(int i=0;i<addressBook->Contactcount;i++)
        {
            if(i != index && strcmp(str2, addressBook->contacts[i].email) == 0)
            {
                printf("\n-------------------------------------------------\n");
printf("  Email address already exists in the Address Book!\n");
printf("  Please enter a different email address.\n");
printf("-------------------------------------------------\n");
                res = 0;
                break;
                
            }
        }
    }while(res == 0);

    strcpy(addressBook->contacts[index].email,str2);
   printf("\n-------------------------------------------------\n");
printf("  Email address updated successfully!\n");
printf("-------------------------------------------------\n");
    return;
}

//----------------------------------------------------------------------------------------------------------------

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    
    int choice;
   
    int index=-1;
    do{
    printf("\n");
printf("=================================================\n");
printf("                 DELETE CONTACT                  \n");
printf("=================================================\n");
printf("|  1.  Search by Name                           |\n");
printf("|  2.  Search by Phone Number                   |\n");
printf("|  3.  Search by Email                          |\n");
printf("|  4.  Exit                                     |\n");
printf("=================================================\n");
printf("Enter your choice: ");

if(scanf("%d", &choice) != 1)
{
    choice = 8;
    while(getchar() != '\n');
}
    
    switch(choice)
    {
        case 1:
           index = search_by_name(addressBook);
            break;
        case 2:
            index = search_by_phone(addressBook);
            break;
        case 3:
            index = search_by_email(addressBook);
            break;
        case 4:
             printf("Exit from this menu\n");
             return;  
        default :
        printf("\n-------------------------------------------------\n");
        printf("  Invalid choice! Please enter a valid option.\n");
        printf("-------------------------------------------------\n");
        break;
    }
    }while(choice < 1 || choice > 4 );

        if(index<0)
    {
       printf("\n-------------------------------------------------\n");
       printf("  Contact not found! Please try again.\n");
       printf("-------------------------------------------------\n");
        
    }

     if(index >= 0)
{
    for(int i = index; i < addressBook->Contactcount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->Contactcount--;

    printf("\n-------------------------------------------------\n");
    printf("  Contact deleted successfully!\n");
    printf("-------------------------------------------------\n");
}
   
}

//------------------------------------------------------------------------------------------------------------------


int validate_name(char *str)
{
    for(int i = 0; str[i]; i++)
    {
        if(!((str[i] >= 'A' && str[i] <= 'Z') || 
             (str[i] >= 'a' && str[i] <= 'z') || 
             str[i] == ' ' ||
              str[i] == '.'))
        {
            printf("\n-------------------------------------------------\n");
            printf("  Invalid name! Please enter a valid name.\n");
            printf("-------------------------------------------------\n");
            return 0; // invalid
        }
    }

    return 1; // valid
}
// ------------------------------------------------------****************** =================================================


int validate_phone(char *str)
{
    int len = strlen(str);

    if (len != 10)
    {
        printf("\n-------------------------------------------------\n");
        printf("  Invalid phone number! Please enter a valid number.\n");
        printf("-------------------------------------------------\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("\n-------------------------------------------------\n");
            printf("  Invalid phone number! Please enter a valid number.\n");
            printf("-------------------------------------------------\n");
            return 0;
        }
    }
    return 1;
}

// ------------------------------------------------------****************** =================================================


int validate_email(char *str)
{
    int len = strlen(str);
    int count = 0;
    

    if(len <=5 || !(str[0] >= 'a' && str[0] <= 'z'))
    {
        printf("\n-------------------------------------------------\n");
        printf("  Invalid email address! Please enter a valid email.\n");
        printf("-------------------------------------------------\n");
            return 0; //invalid 
    }
    
    for(int i=0;str[i];i++)
    {
        if(str[i] == '.' && str[i+1] == '.')
        {
           printf("\n-------------------------------------------------\n");
        printf("  Invalid email address! Please enter a valid email.\n");
        printf("-------------------------------------------------\n");
            return 0; //invalid  
        }
        if(str[i]=='@')
        {
            count++;
            if(!(str[i+1] >= 'a' && str[i+1] <= 'z' ))
            {
                printf("\n-------------------------------------------------\n");
        printf("  Invalid email address! Please enter a valid email.\n");
        printf("-------------------------------------------------\n");
            return 0; //invalid 
            }     
        }
        
        if(!((str[i] >= 'a' && str[i] <= 'z' ) || 
             (str[i] >= '0' && str[i] <= '9')  ||
             str[i] == '@' || str[i] == '.'))
        {
           printf("\n-------------------------------------------------\n");
        printf("  Invalid email address! Please enter a valid email.\n");
        printf("-------------------------------------------------\n");
            return 0; //invalid 
        }
    }

    if(!((count == 1) && str[len-1] == 'm' && 
        str[len-2] == 'o' && str[len-3] == 'c' && str[len-4] == '.'))
       {
        printf("\n-------------------------------------------------\n");
        printf("  Invalid email address! Please enter a valid email.\n");
        printf("-------------------------------------------------\n");
            return 0; //invalid 
       }

       return 1;
}

//-----------------------------------------------------------------------------------------------------------------




int search_by_name(AddressBook *addressBook)
{
    char str[50];
    int flag =0;
    int i=0;
    int i_value=-1;
    int k=1;
    int own =0;

  printf("\nEnter the name to search: ");
scanf(" %49[^\n]", str);
   
printf("%-5s %-25s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");
printf("--------------------------------------------------------------------------\n");
    
    for( i=0;i<addressBook->Contactcount;i++)
    {
        if(strcmp(addressBook->contacts[i].name,str) == 0)
        {



printf("%-5d %-25s %-15s %-30s\n",
       k,
       addressBook->contacts[i].name,
       addressBook->contacts[i].phone,
       addressBook->contacts[i].email);
       
            flag++;
            k++;
            i_value = i;
          
        }
        
    }
    
    
   if(flag > 1)
{
    printf("\n-------------------------------------------------\n");
    printf("  Multiple contacts found with this name.\n");
    printf("  Please select a contact using the serial number.\n");
    printf("-------------------------------------------------\n");

    own = multiple_names(addressBook, str);

    printf("\nSelected Contact:\n");
    printf("%-5s %-25s %-15s %-30s\n",
           "S.No", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------------------\n");

    printf("%-5d %-25s %-15s %-30s\n",
           1,
           addressBook->contacts[own].name,
           addressBook->contacts[own].phone,
           addressBook->contacts[own].email);

    return own;
}


  if(flag == 0)
  {
    return -1;
  }
  return i_value;

  
}

// ------------------------------------------------------****************** =================================================

int search_by_phone(AddressBook * addressBook)
{
    char str[50];
    int i=0;

    //Get the phone number 
    printf("\nEnter the phone number to search: ");
    scanf("%49s",str);

    for(i=0;i<addressBook->Contactcount;i++)
    {
         if(strcmp(addressBook->contacts[i].phone,str) == 0)
        {
printf("\n");
printf("S.No\tName\t\tPhone\t\tEmail\n");
printf("------------------------------------------------------------\n");

printf("%d\t%s\t\t%s\t\t%s\n",
       1,
       addressBook->contacts[i].name,
       addressBook->contacts[i].phone,
       addressBook->contacts[i].email);
                   return i;
        }
    }
    return -1;
    
}

// ------------------------------------------------------****************** =================================================

int search_by_email(AddressBook * addressBook)
{
    char str[50];
    int i=0;
    printf("\nEnter the email to search: ");
    scanf("%49s",str);

    for( i=0;i<addressBook->Contactcount;i++)
    {
         if(strcmp(addressBook->contacts[i].email,str) == 0)
        {
printf("S.No\tName\t\tPhone\t\tEmail\n");
printf("------------------------------------------------------------\n");

printf("%d\t%s\t\t%s\t\t%s\n",
       1,
       addressBook->contacts[i].name,
       addressBook->contacts[i].phone,
       addressBook->contacts[i].email);
                   return i;
        }
    }
    return -1;
}

int multiple_names(AddressBook * addressBook,char *str)
{
    int n_count=0;
    int arr_index[100];
    int nn;
    for(int i=0;i<addressBook->Contactcount;i++)
    {
        if(strcmp(addressBook->contacts[i].name,str) == 0)
        {
            
         arr_index[n_count] = i;
         n_count++;
        }
        
    }
    printf("enter the serial number to choose the contact");
    scanf("%d",&nn);

    while(nn < 1 || nn > n_count)
    {
        printf("Invalid serial number. Enter again: ");
        scanf("%d", &nn);
    }

    return arr_index[nn - 1];

}
  