#ifndef ListSLL
#define ListSLL

#define NS      0
#define OG      1
#define DONE    2

struct node{
    int x;
    struct node *nxt;
};

void create_node(int _x);
void insert(int _x,struct node *_L);

/*
Requirement functions!
*/
char add();
void browse(void);
void change(void);
void delete(void);

/*
structure to allocating abstract variable for the inputs
*/
struct name{
    char letter;
    struct name *nxt_letter;
};

#endif