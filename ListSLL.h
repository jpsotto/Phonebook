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
Requirement functions for add
*/
struct Entry *_add(void);
/*
Requirement functions!
*/
char add();
void browse(void);
void change(void);
void delete(void);

/*
Requirement Structure
*/
struct record{
    struct Name *record_name;
    long int record_number;
    struct Affiliation *record_affiliation;
};

/*
Structure for Name
*/
struct Entry{
    char *letter;
    struct Entry *nxt_letter;
};
int namesize;
/*
Structure for Name
*/
struct Affiliation{
    char _letter;
    struct Affiliation *next_letter;
};

#endif