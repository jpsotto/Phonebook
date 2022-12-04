#include <stdio.h>
#include <stdlib.h>
#include "ListSLL.h"
#include "ListSLL.c"
#include "terminal_ctrl.c"

//App code initialization
struct node *_firstnode, *_lastnode;

int main(){
/*
Windows.h terminal_ctrl Initialization
*/
HANDLE hStdout;
hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

/*
Main App Code
*/


    insert(10,_firstnode);
    browse();
    insert(11,_firstnode);
    browse();
    insert(12,_firstnode);
    browse();
    cls(hStdout); // Clear Screen
    printf("CODE SUCCESSFUL!");
    getchar();
    return 0;
}