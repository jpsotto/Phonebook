#include <stdio.h>
#include <stdlib.h>
#include "ListSLL.h"
#include "ListSLL.c"
#include "main_app.h"
#include "main_app.c"
#include "terminal_ctrl.c"

//App code initialization
struct node *_firstnode, *_lastnode;
char app_response=0x00;

int main(){
int ch;
/*
Windows.h terminal_ctrl Initialization
*/
HANDLE hStdout;
hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

/*
Main App Code
*/
while(1){
    if(app_response == 0x00){
        app_response = intro_screen();
    }
    else{
        if(app_response == ENTER){
            if(*_enter_key_indicator == 0x00){
                switch(_main_app_indicator){
                    case 0:
                        printf("Execute add command!");
                        break;
                    case 1:
                        printf("Execute browse command!");
                        break;
                    case 2:
                        printf("Execute change command!");
                        break;
                    case 3:
                        printf("Execute detected command!");
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
            app_response = home_screen(app_response);
            printf("\n");
            cls(hStdout);//clear screen
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