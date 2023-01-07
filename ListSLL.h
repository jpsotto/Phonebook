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
char browse(void);
void change(void);
char delete(void);
char delete_display(char _dresponse);
char change_display(char _cresponse);
char _dresponse = 0, delete_indicator = 0, _di = 0, _cresponse = 0, change_indicator = 0, _ci = 0;
int _n;


/*
Structure for Name
*/
struct Entry{
    char _data[32];
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

struct Entry browse_buffer;
struct record *_browse;
struct record *_delete;
struct record *_change;
#endif