#ifndef main_app
#define main_app

#define UP      0x01
#define DOWN    0x02
#define LEFT    0x03
#define RIGHT   0x04
#define ENTER   0x05

char home_screen(char);
void app_indicator(char);
void footer();

char _main_app_indicator = 4;
char *_enter_key_indicator;//This pointer indicates when a enter is pressed.






#endif