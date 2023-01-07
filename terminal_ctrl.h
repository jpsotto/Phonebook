#ifndef terminal_ctrl
#define terminal_ctrl
#include <windows.h>

void cls(HANDLE hConsole);
uint8_t wait_for_response(char *app_indicator);
#endif