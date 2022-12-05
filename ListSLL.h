#ifndef ListSLL
#define ListSLL

struct node{
    int x;
    struct node *nxt;
};

void create_node(int _x);
void insert(int _x,struct node *_L);

/*
Requirement functions!
*/
void add(void);
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