#ifndef ListSLL
#define ListSLL

struct node{
    int x;
    struct node *nxt;
};

void create_node(int _x);
void insert(int _x,struct node *_L);
void browse(void);

#endif