#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListSLL.h"

extern struct node *_firstnode, *_lastnode;
extern struct Entry *_entry;
extern struct record *firstrecord, *lastrecord;
extern long int _numberbuffer;
//initialize getch handler
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
        if(_delete == NULL){
            printf("Initializing add function...\n");
            firstrecord = (struct record*)malloc(sizeof(struct record));
        }
        else{
            printf("Reusing memory...\n");
            firstrecord = _delete;
        }
        
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
    for(int _i = 0; (_i < 32) || (buffer[_i] != '\0'); _i ++){
        _entry->_data[_i] = buffer[_i];
        // printf("%c", buffer[_i]);
    }
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
        printf("NAME\tNUMBER\tAFFILIATION");
        printf("\n");
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
        }
   }
    getch();
    return DONE;
}

char change_display(char _cresponse){
    int _cch = 0;
    char _cmarker[32];
    // printf("An instance has been deleted!");
    /*
    Start of Code
    */
   //reset _cmarker
   for(int i = 0; i < 32; i++){
        _cmarker[i] = 0;
    }
    //set marker to specific entry
    _cmarker[change_indicator] = '>';

    //prompt if no entries
    if(firstrecord == NULL){
        printf("The phonebook is empty!\n");
        getch();
        return DONE;
    }
    //show list if there are records
    else{
        int k = 0;
        //  printf("\n");
        printf("Please select a record from the list to be changed\n");
        printf("**NOTE:Press backspace to exit.\n");
        printf("NAME\tNUMBER\tAFFILIATION");
        printf("\n");
        for(int i = 0; i < 32; i++){
            k = i;
            _change = firstrecord;
            while(k > 0){
                _change = _change->nxt_record;
                k--;
            }
            if(_change != NULL){
                browse_buffer = _change->_name;
                printf("%s\t", browse_buffer._data);
                browse_buffer = _change->_number;
                printf("%s\t", browse_buffer._data);
                browse_buffer = _change->_affiliation;
                printf("%s", browse_buffer._data);
                printf("%c\n", _cmarker[i]);
            }
            else{
                _nc = i-1;
                i = 32;
            }
        }
        _cch = getch();
        switch(_cch){
            case 8:
                return DONE;
                break;
            case 72:
                // printf("Arrow up has been pressed!");
                if(change_indicator > 0){
                    change_indicator--;
                }
                break;
            case 80:
                // printf("Arrow down has been pressed!");
                if(change_indicator < _nc){
                    change_indicator++;
                }  
                break;
            case 75:
                // printf("Arrow left has been pressed!");
                break;
            case 77:
                // printf("Arrow right has been pressed!");
                break;
            case 13:
                change();
                // getch();
                // printf("CHECK");
                return DONE;
                break;
            default:
                // printf("%i",_ch);//uncomment this for debug
                break;
        }
        return OG;
    }
}

/*
This function changes the details of an already existing node in the phonebook.
*/
inline void change(){
    // printf("An instance has been changed!");
    char buffer[32];
    _ci = change_indicator;
    _change = firstrecord;
    while(_ci > 0){
        _change = _change->nxt_record;
        _ci--;
    }

    //RESET THE VALUES IN THE ENTRY
    reset_entry();

    printf("Enter new name:\n");
    gets(buffer); //scan a string
    for(int _i = 0; (_i < 32) && (buffer[_i] != '\0'); _i ++){
        _change->_name._data[_i] = buffer[_i];
    }
    reset_buffer(buffer);
    printf("Enter new number:\n");
    gets(buffer); //scan a string
    for(int _i = 0; (_i < 32) && (buffer[_i] != '\0'); _i ++){
        _change->_number._data[_i] = buffer[_i];
    }
    reset_buffer(buffer);
    printf("Enter new affiliation:\n");
    gets(buffer); //scan a string
    for(int _i = 0; (_i < 32) && (buffer[_i] != '\0'); _i ++){
        _change->_affiliation._data[_i] = buffer[_i];
    }
}

/*
This function resets the values in the _change struct pointer
*/
inline void reset_entry(){
    for(int i = 0; i < 32; i++){
        _change->_name._data[i] = 0;
        _change->_number._data[i] = 0;
        _change->_affiliation._data[i] = 0;
    }
}

/*
This function resets the values in the 32 bytes array pointer
Input - char *
*/
inline void reset_buffer(char *_rbuffer){
    for(int i = 0; i < 32; i++){
        _rbuffer[i] = 0;
    }
}

/*
This function deletes an existing node in the phonebook.
*/
char delete_display(char _dresponse){
    int _ch = 0;
    char _dmarker[32];
    // printf("An instance has been deleted!");
    /*
    Start of Code
    */
   //reset _cmarker
   for(int i = 0; i < 32; i++){
        _dmarker[i] = 0;
    }
    //set marker to specific entry
    _dmarker[delete_indicator] = '>';

    //prompt if no entries
    if(firstrecord == NULL){
        printf("The phonebook is empty!\n");
        getch();
        return DONE;
    }
    //show list if there are records
    else{
        int k = 0;
        //  printf("\n");
        printf("Please select a record from the list to be deleted\n");
        printf("**NOTE:Press backspace to exit.\n");
        printf("NAME\tNUMBER\tAFFILIATION");
        printf("\n");
        for(int i = 0; i < 32; i++){
            k = i;
            _delete = firstrecord;
            while(k > 0){
                _delete = _delete->nxt_record;
                k--;
            }
            if(_delete != NULL){
                browse_buffer = _delete->_name;
                printf("%s\t", browse_buffer._data);
                browse_buffer = _delete->_number;
                printf("%s\t", browse_buffer._data);
                browse_buffer = _delete->_affiliation;
                printf("%s", browse_buffer._data);
                printf("%c\n", _dmarker[i]);
            }
            else{
                _n = i-1;
                i = 32;
            }
        }
        _ch = getch();
        switch(_ch){
            case 8:
                return DONE;
                break;
            case 72:
                // printf("Arrow up has been pressed!");
                if(delete_indicator > 0){
                    delete_indicator--;
                }
                break;
            case 80:
                // printf("Arrow down has been pressed!");
                if(delete_indicator < _n){
                    delete_indicator++;
                }  
                break;
            case 75:
                // printf("Arrow left has been pressed!");
                break;
            case 77:
                // printf("Arrow right has been pressed!");
                break;
            case 13:
                delete();
                return DONE;
                break;
            default:
                // printf("%i",_ch);//uncomment this for debug
                break;
        }
        return OG;
    }
    
}

/*
this function shows the screen of nodes to be deleted
*/

inline char delete(){
    struct record *_erase;
    _di = delete_indicator-1;//set the reference pointer to the entry before the deletion entry

    _delete = firstrecord; //start _delete ptr value to the firstrecord
    while(_di > 0){//iterate until the entry before the deletion entry
         _delete = _delete->nxt_record;
        _di--;
    }

    // _erase = _delete;
    if(delete_indicator == 0){
        _erase = _delete;
    }
    else{
        _erase = _delete->nxt_record;
    }
    
    if(_n > 0){
        if(_erase == firstrecord){
            // printf("CHECK1!");
            // getch();
            firstrecord = firstrecord->nxt_record;
            _delete = NULL;
            free(_delete); //free up the memory allocated to the deletion entry to prevent memory leak
        }
        else{
            _delete->nxt_record = _delete->nxt_record->nxt_record;  //move the pointer of the next entry to the end of the previous entry
            free(_erase); //free up the memory allocated to the deletion entry to prevent memory leak
        }
    }
    else{
        _delete = firstrecord;
        _delete->nxt_record = NULL;
        firstrecord = NULL;//terminate first record to prevent the bug of showing random character
        //NOTE: 'firstrecord' pointer was stored in '_delete' variable which will be reused on the next add sequence. So the memory location need not be freed.
    }
    
}
