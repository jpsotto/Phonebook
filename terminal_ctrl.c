#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
//This library contains the needed dependencies to be able to clear the terminal as needed in a windows gcc compiler.


void cls(HANDLE hConsole)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SMALL_RECT scrollRect;
    COORD scrollTarget;
    CHAR_INFO fill;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Scroll the rectangle of the entire buffer.
    scrollRect.Left = 0;
    scrollRect.Top = 0;
    scrollRect.Right = csbi.dwSize.X;
    scrollRect.Bottom = csbi.dwSize.Y;

    // Scroll it upwards off the top of the buffer with a magnitude of the entire height.
    scrollTarget.X = 0;
    scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

    // Fill with empty spaces with the buffer's default text attribute.
    fill.Char.UnicodeChar = TEXT(' ');
    fill.Attributes = csbi.wAttributes;

    // Do the scroll
    ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

    // Move the cursor to the top left corner too.
    csbi.dwCursorPosition.X = 0;
    csbi.dwCursorPosition.Y = 0;

    SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}

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
UINT8 wait_for_response(char *app_indicator){
    int ch;
    ch = _getch();
    // printf("%d\n",ch);//this is for debugging
    if(ch == 13){
        printf("Enter Key was pressed!");
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
