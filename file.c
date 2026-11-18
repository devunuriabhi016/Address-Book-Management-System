#include <stdio.h>
#include "file.h"
#include<string.h>

void saveContactsToFile(AddressBook *addressBook) {
    FILE*ptr = fopen("contacts.csv","w");
    if(ptr == NULL)
    {
        printf("null null\n");
        return;
    }

    fprintf(ptr,"#%d\n",addressBook->Contactcount);
for(int i=0;i< addressBook->Contactcount;i++){
    fprintf(ptr,"%s,%s,%s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    } 
    
    fclose(ptr);
}
   

void loadContactsFromFile(AddressBook *addressBook) {

    FILE *fptr = fopen("contacts.csv","r");
    if(fptr == NULL)
    {
        printf("null null\n");
        return;
    }
     fscanf(fptr,"#%d\n",&addressBook->Contactcount);
    for(int i=0;i<addressBook->Contactcount;i++){
    fscanf(fptr,"%49[^,],%19[^,],%49[^\n]\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    } 
    
    fclose(fptr);

    
}
