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
struct Entry _add(void);
char *mem_alloc(size_t _memsize);
/*
Requirement functions!
*/
// char add();
void browse(void);
void change(void);
void delete(void);


/*
Structure for Name
*/
struct Entry{
    char _data[32];
};
int namesize;
/*
Structure for a Info
*/
struct Affiliation{
    char _letter;
    struct Affiliation *next_letter;
};


/*
Requirement Structure
*/
struct record{
    struct Entry _name;
    struct Entry _number;
    struct Entry _affiliation;
    struct record *nxt_record;
};
#endif