
#define EMPTYNODE 0
#define TRUE 1
#define FALSE 0

struct node
{
    short data; // 16
    struct node* left; // 64
    struct node* right; // 64
};

typedef struct node nodeQ_t;