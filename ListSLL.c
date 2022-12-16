#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListSLL.h"

extern struct node *_firstnode, *_lastnode;
extern struct Entry *_entry;
extern struct record *firstrecord, *lastrecord;
extern long int _numberbuffer;
// extern char *_name,*_affiliation;
// extern long int *_phone_number;
/*
_x - value of the node
_p - position of the specific node in the list to be inserted
*_L - pointer to the list
*/
void insert(int _x,struct node *_L){
    if(_L == NULL){
        printf("The node is empty!\n");
        printf("Creating Node...\n ");
        create_node(_x);
        printf("Node creation successful! \n");
    }
    else{
        printf("Creating next node...\n");
        _lastnode->nxt = (struct node*)malloc(sizeof(struct node));
        _lastnode->nxt->x = _x;
        _lastnode->nxt->nxt = NULL;
        _lastnode = _lastnode->nxt;
        // _L->nxt = (struct node*)malloc(sizeof(struct node));
        // nextnode = _L->nxt;
    }
    
    // nextnode = _L;
    // nextnode->x = _x;
    // nextnode->nxt = NULL;
}

void create_node(int _val){
    _firstnode = (struct node*)malloc(sizeof(struct node));  //allocate a memory location to the node and return the pointer to that memory location to the pointer variable *_node
    _lastnode = _firstnode;
    _lastnode->x = _val;
    _lastnode->nxt = NULL;
}

/*
****NEEDED FUNCTIONS***
*/
/*
This functions adds and instance to the phonebook.
It will first request for the name of the entry, followed by the phone number, and affiliation.

Return Value:
Status of the function
NS      - Not Started
OG      - Ongoing
DONE    - Finished
*/
char add(){
    if(firstrecord == NULL){
        printf("Initiating add function...\n");
        firstrecord = (struct record*)malloc(sizeof(struct record));
        lastrecord = firstrecord;
        printf("Please type the full name: \n");
        lastrecord->_name = _add();
        printf("\nName was added!\n");
        printf("Please type in the number: \n");
        lastrecord->_number = _add();
        printf("\nNumber was added!\n");
        printf("Please type in the affiliation: \n");
        lastrecord->_affiliation = _add();
        printf("\nAffiliation was added!\n");
        lastrecord->nxt_record = NULL;
    }
    else{
        lastrecord->nxt_record = (struct record*)malloc(sizeof(struct record));
        printf("Please type the full name: \n");
        lastrecord->nxt_record->_name = _add();
        printf("\nName was added!\n");
        printf("Please type in the number: \n");
        lastrecord->nxt_record->_number = _add();
        printf("\nNumber was added!\n");
        printf("Please type in the affiliation: \n");
        lastrecord->nxt_record->_affiliation = _add();
        printf("\nAffiliation was added!\n");
        lastrecord->nxt_record->nxt_record = NULL;
        lastrecord = lastrecord -> nxt_record;
        getch();
    }
    
    return DONE;
}

/*
_add - this function allocates memory of the added name.
*/
inline struct Entry _add(){
    char buffer[32];
    gets(buffer); //scan a string
    // printf(".");
    // printf(".");
    //transfer the value of the buffer to the data array.
    for(int _i = 0; (_i < 32) || (buffer[_i] != '\0'); _i ++){
        _entry->_data[_i] = buffer[_i];
        // printf("%c", buffer[_i]);
    }
    // printf("\n%s", buffer);
    printf("\n%s", _entry->_data);
    getch();
    return *_entry; // return the scanned value
}

/*
This function checks on all the contents of the node and prints it.
*/
char browse(){
    /*
    start of the code
    */
   if(firstrecord == NULL){
        printf("The phonebook is empty!\n");
   }
    else{
        int k = 0;
        for(int i = 0; i < 32; i++){
            k = i;
            _browse = firstrecord;
            while(k > 0){
                _browse = _browse->nxt_record;
                k--;
            }
            if(_browse != NULL){
                browse_buffer = _browse->_name;
                printf("%s\t", browse_buffer._data);
                browse_buffer = _browse->_number;
                printf("%s\t", browse_buffer._data);
                browse_buffer = _browse->_affiliation;
                printf("%s\n", browse_buffer._data);
            }
            else{
                i = 32;
            }
            // printf("\nhellow");
        }
   }
   
    getch();
    return DONE;
}

/*
This function changes the details of an already existing node in the phonebook.
*/
void change(){
    printf("An instance has been changed!");
}

/*
This function deletes an existing nod in the phonebook.
*/
void delete(){
    printf("An instance has been deleted!");
}
