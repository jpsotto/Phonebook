#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ListSLL.h"
#include "ListSLL.c"
#include "main_app.h"
#include "main_app.c"
#include "terminal_ctrl.c"

//App code initialization
struct node *_firstnode, *_lastnode;
struct Entry *_entry;
struct record *firstrecord, *lastrecord;
long int _numberbuffer;
char app_response=0x00;
char list_response = 0x00;
char *_enter_key_indicator;//This pointer indicates when a enter is pressed.


int main(){
int ch;
int _testvar;
// char *_name,*_affiliation;
// long int *_phone_number;
/*
Windows.h terminal_ctrl Initialization
*/
HANDLE hStdout;
hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

/*
Initialize Key Indicator
*/
_enter_key_indicator = (char *)malloc(sizeof(char));

/*
Initiate Entry buffer;
*/
 _entry = (struct Entry*)malloc(sizeof(struct Entry)); //allocate a memory location for the firstletter of the entry
/*
Main App Code
*/
while(1){
    if(app_response == DEFAULT){
        app_response = home_screen(app_response);
    }
    else {
        if(app_response == ENTER){
            if(*_enter_key_indicator == 0x00){
                switch(_main_app_indicator){
                    case 0:
                        printf("Execute add command!\n");
                        list_response = OG;
                        list_response = add();
                        if(list_response == DONE){
                            app_response = DEFAULT;
                            cls(hStdout);//clear screen
                        }
                        break;
                    case 1:
                        printf("Execute browse command!\n");
                        list_response = OG;
                        list_response = browse();
                        if(list_response == DONE){
                            app_response = DEFAULT;
                            cls(hStdout);//clear screen
                        }
                        break;
                    case 2:
                        printf("Execute change command!");
                        break;
                    case 3:
                        printf("Execute delete command!\n");
                        list_response = NS;
                        while(list_response != DONE){
                            switch(list_response){
                            case NS:
                                list_response = delete_display(_dresponse);
                                break;
                            case DONE:
                                app_response = DEFAULT;
                                cls(hStdout);//clear screen
                                break;
                            case OG:
                                cls(hStdout);//clear screen
                                list_response = delete_display(_dresponse);
                                break;
                            default:
                                break;
                            }
                        }
                        app_response = DEFAULT;
                         cls(hStdout);//clear screen
                        break;
                    default:
                        cls(hStdout);//clear screen
                        printf("Nothing is chosen yet! Please select from the options!\n");
                        app_response = 0x10;
                        break;
                }
                *_enter_key_indicator = 0x01;
            }    
        }
        else{
            cls(hStdout);//clear screen
            app_response = home_screen(app_response);
            printf("\n");
        }
    }
}

    // insert(10,_firstnode);
    // browse();
    // insert(11,_firstnode);
    // browse();
    // insert(12,_firstnode);
    // browse();
    // cls(hStdout); // Clear Screen
    // printf("CODE SUCCESSFUL!");
    getchar();
    return 0;
}