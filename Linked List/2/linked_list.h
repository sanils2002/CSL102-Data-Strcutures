
#define EMPTYNODE 0

typedef struct nodeQ nodeQ_t;

typedef enum{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;

struct nodeQ
{
    short data;
    struct nodeQ* next;
};