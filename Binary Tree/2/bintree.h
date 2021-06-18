
#define EMPTYNODE 0
#define SPACE_GAP_LEVEL 10
#define FALSE 0
#define TRUE 1

struct node {
	short data;
	struct node* left;
	struct node* right;
};

typedef struct node node_t;

short trackerArr[2048] = {0};
short trackerIdx = 0;