#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node Node;

struct Node {
	Node* next;
	void* value;
};

typedef struct {
	Node* first;
	Node* last;
	int	  size;
} LinkedList;


void insert_start(LinkedList* list, void* value);
void insert_end(LinkedList* list, void* value);
Node* search_node(LinkedList* list, void* value);
void remove_node(LinkedList* list, void* value);

#endif
