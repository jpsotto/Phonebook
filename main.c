#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ListSLL.h"
#include "ListSLL.c"
#include "terminal_ctrl.c"

//App code initialization
struct node *_firstnode, *_lastnode;


// void insert(int _x){
//     _firstnode = (struct node*)malloc(sizeof(struct node));
//     nextnode = _firstnode;
//     nextnode->x = _x;
//     nextnode->nxt = NULL;
// }

void browse(){
    struct node *browsebuffer;
    browsebuffer = _firstnode;
    // check if node is empty
    if(browsebuffer == NULL){
        printf("Node is empty!");
    }
    else{
        while(browsebuffer != NULL){
            //print data of the recent node
            printf("CONTENT: %d \n", browsebuffer->x);
            browsebuffer = browsebuffer->nxt;
        }
    }
}


int main(){
/*
Windows.h terminal_ctrl Initialization
*/
HANDLE hStdout;
hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

/*
Main App Code
*/


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