#include <stdio.h>
#include <stdlib.h>
#include "ListSLL.h"

extern struct node *_firstnode, *_lastnode;
extern struct name *_firstletter_name, *_lastletter_name;
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
    char *_name;
    int _i = 0;
    printf("Initiating add function...\n");
    printf("Please type in the name: ");
    // _name = 0;
    _name = (char *)malloc(32);
    scanf("%[^\n]%*c", _name);
    // scanf("%c", _name);
    // printf("%s",_name);
    while(*_name != '\0'){
        printf("%c",*_name);
        _name++;
        _i++;
    }
    printf("%d",_i);
    // _firstletter_name = (struct name*)malloc(sizeof(struct name));
    // _lastletter_name = _firstletter_name;
    // _lastletter_name->letter = _letter;
    // _lastletter_name->nxt_letter = NULL;
    return DONE;
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
