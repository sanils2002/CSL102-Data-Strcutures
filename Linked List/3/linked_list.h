
#define EMPTYNODE 0

struct nodeQ
{
    short data;
    struct nodeQ* next;
};

typedef struct nodeQ nodeQ_t;

typedef enum
{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;