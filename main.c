#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
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
        app_response = home_screen(app_response);
    }
    printf("\n");
    cls(hStdout);
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