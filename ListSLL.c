#include <stdio.h>
#include <stdlib.h>
#include "ListSLL.h"

extern struct node *_firstnode, *_lastnode;
extern struct Name *firstletter_name, *lastletter_name;
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
    firstletter_name = add_name();
    printf("Name was added!\n");
    _numberbuffer = add_number();
    // _name = 0;
    // _firstletter_name = (struct name*)malloc(sizeof(struct name));
    // _lastletter_name = _firstletter_name;
    // _lastletter_name->letter = _letter;
    // _lastletter_name->nxt_letter = NULL;
    return DONE;
}

/*
add_name - this function allocates memory of the added name.
*/
struct Name *add_name(){
    char *_name;
    int _i = 0, _space = 0;
    printf("Please type in the full name: ");
    _name = (char *)malloc(sizeof(char)); //allocate a memory location to a pointer variable _name
    scanf("%[^\n]%*c", _name); //scan all incoming characters from keyboard except enter '\n' and put it in the memory location of pointer _name
    do{ //loop until '\0' value was found in the _name memory location
        // _buffer = *_name; //pass the value of the memory pointer _name to buffer
        // if(*_name == '\0'){
        //     _space++;
        //     printf("space detected");//FOR DEBUG PURPOSES
        // }
        // else{
        //     _space = 0;
        // }
        if(*_name != '\0'){
            if(_i == 0){
                firstletter_name = (struct Name*)malloc(sizeof(struct Name)); //allocate a memory location for the firstletter of the name
                firstletter_name->letter = *_name; //pass the value in the pointer _name to the element letter if the 'Name' structure
                lastletter_name = firstletter_name; //pass the pointer memory address of the firstletter_name to the lastletter_name
                lastletter_name->nxt_letter = NULL; //terminate the latest node
                printf("%c", lastletter_name->letter);//FOR DEBUG PURPOSES
            }
            else{
                lastletter_name->nxt_letter = (struct Name*)malloc(sizeof(struct Name)); //allocate a memoryfor the succeding letters of the name
                lastletter_name->nxt_letter->letter = *_name; //pass the value in the pointer  _name to the element letter of the 'Name' structure
                printf("%c", lastletter_name->nxt_letter->letter); //FOR DEBUG PURPOSES
                lastletter_name->nxt_letter->nxt_letter = NULL; //terminate the latest node
                lastletter_name = lastletter_name->nxt_letter; //pass the pointer memory address of the last node to the pointer variable lastletter_name
            }
            // printf("%c", _buffer);//FOR DEBUG PURPOSES
            // _name++;
            _i++;
        }
        _name++;
    }while(*_name != '\0');

    printf("%d",_i); //print size of name (FOR DEBUG PURPOSES)
    return firstletter_name;
}

/*
add_number - this function asks the user's number. 
*/
long int add_number(){
    long int _buffer;
    printf("Please input your number: ");
    scanf("%ld", &_buffer);
    printf("%ld", _buffer);
    // printf("%ld", _buffer); //for DEBUG purposes
    return _buffer;
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
