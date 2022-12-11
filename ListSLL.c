#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListSLL.h"

extern struct node *_firstnode, *_lastnode;
extern struct Entry *first_entry, *last_entry;
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
    printf("Initiating add function...\n");
    printf("Please type the full name: \n");
    first_entry = _add();
    printf("\nName was added!\n");

    return DONE;
}

/*
add_name - this function allocates memory of the added name.
*/
struct Entry *_add(){
    char *_entry,*_bufferptr;
    size_t _buffersize;
    _entry = (char *)malloc(sizeof(_entry)); //allocate a memory location to a pointer variable _entry
    // _buffer = (char *)malloc(sizeof(_buffer));
    // scanf("%[^'\n']%*c", _name); //scan all incoming characters from keyboard except enter '\n' and put it in the memory location of pointer _entry
    gets(_entry); //scan a string
    // printf("%s\n", _entry);//FOR DEBUG PURPOSES
    // printf("%s\n", _entry);//FOR DEBUG PURPOSES
    // printf("%s\n", _entry);//FOR DEBUG PURPOSES
    // _entry = (char *)calloc(strlen(_entry));
    _buffersize = strlen(_entry);
    // printf("%i\n", _buffersize);
    _bufferptr = (char *)malloc(_buffersize);
    _bufferptr = _entry;
    // // strcpy(_bufferptr,_entry);
    // // printf(".");
    // char _buffer[_buffersize];  
    // for(int _i = 0; *_entry != '\0'; _i++){
    //     _buffer[_i] = *_entry;
    //     _entry++;
    // }
    // printf(".");
    // _bufferptr = _buffer;
    // printf(".");
    first_entry = (struct Entry*)malloc(sizeof(struct Entry)); //allocate a memory location for the firstletter of the entry
    printf(".");
    last_entry = first_entry;
    // printf(".");
    last_entry->letter = _bufferptr;
    // printf(".");
    printf("%s", last_entry->letter);
    last_entry = first_entry; //entrypass the pointer memory address of the firstletter_name to the last_entry
    // printf(".");
    // last_entry->nxt_letter = NULL; //terminate the latest node
    // printf("%s",*firstletter_name->letter);
    // printf("%s", _name); // FOR DEBUG PURPOSES
    // printf(".");
    getch();
    free(_entry);//free the allocated memory on the pointer variable '_entry'
    return 0;
}

/*
This function checks on all the contents of the node and prints it.
*/
void browse(){
    //SIMULATED CODE ONLY
    printf("Browsing phonebook...");
    //***LATEST CODE
    // struct node *browsebuffer;
    // browsebuffer = _firstnode;
    // // check if node is empty
    // if(browsebuffer == NULL){
    //     printf("Node is empty!");
    // }
    // else{
    //     while(browsebuffer != NULL){
    //         //print data of the recent node
    //         printf("CONTENT: %d \n", browsebuffer->x);
    //         browsebuffer = browsebuffer->nxt;
    //     }
    // }
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
