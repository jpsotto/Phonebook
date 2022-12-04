#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main_app.h"
/*
Update the cursor in the Main App
*/
void app_indicator(char _input){
    switch(_input){
        case DOWN:
            if(_main_app_indicator == 3){
                _main_app_indicator = 0;
            }
            else{
                _main_app_indicator++;
            }
            break;
        case UP:
            if(_main_app_indicator == 0){
                _main_app_indicator = 3;
            }
            else{
                _main_app_indicator--;
            }
            break;
    }
}

char home_screen(char _response){
    int ch;
    char _marker[4];
    app_indicator(_response);
    for(int i = 0; i < 4; i++){
        _marker[i] = 0;
    }
    _marker[_main_app_indicator] = '>';
    printf("***Phonebook List***\n");
    printf("\n");
    printf("***OPTIONS***\n");
    printf("ADD[%c]\n", _marker[0]);
    printf("BROWSE[%c]\n", _marker[1]);
    printf("CHANGE[%c]\n", _marker[2]);
    printf("DELETE[%c]\n", _marker[3]);

/*
NOTE: Using getch.
If you press Enter, the getch function will return the value 13.
When you press any arrow key, the getch function returns 2 values.
If you press the arrowkeys it will return the value 224 followed by another value.
When numlock is activated when you pressed the keyboard, it will return 0 instead of 224.
Then the next value depends on what you press.
72 when you press up
80 when you press down
75 when you press left
77 when you pressed right
*/
    ch = _getch();
    // printf("%d\n",ch);//this is for debugging
    if(ch == 13){
        printf("Enter Key was pressed!");
        _enter_key_indicator = (char *)malloc(sizeof(char));
        *_enter_key_indicator = 0x00;
        return ENTER;
    }
    else if (ch == 0 || ch == 224){

        switch(_getch()) { // the real value
            case 72:
                // code for arrow up
                if(_main_app_indicator == 4){ //this snippet initiates the first indicator to the down most option.
                    _main_app_indicator = 4;
                }
                // printf("Arrow up has been pressed!");
                return UP;
                break;
            case 80:
                // code for arrow down
                if(_main_app_indicator == 4){ // this snippet initiates the first indicator to the top most option.
                    _main_app_indicator = -1;
                }
                // printf("Arrow down has been pressed!");
                return DOWN;
                break;
            case 75:
                // code for arrow left
                // printf("Arrow left has been pressed!");
                return LEFT;
                break;
            case 77:
                // code for arrow right
                // printf("Arrow right has been pressed!");
                return RIGHT;
                break;
            default:
                return 0x10;
        }
    }
    else{
        return 0x10;
    }
}

char intro_screen(){
    printf("***FORMATIVE ASSESSMENT1***\n");
    printf("Created by: John Perloe M. Sotto\n");
    printf("MS Computer Engineering Major in Software Engineering\n");
    printf("\n");
    home_screen(0x00);
}