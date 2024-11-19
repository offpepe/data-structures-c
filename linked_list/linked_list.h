#ifndef LINKED_LIST
#define LINKED_LIST

#define NULL (void*)0

typedef struct {
	Node* next;
	void* value;
} Node;

typedef struct {
	Node* first;
	Node* last;
	int	  size;
} LinkedList;


void insert_start(LinkedList* list, Node* node);
void insert_end(LinkedList* list, Node* node);
Node* search_node(LinkedList* list, void* value);
void remove_node(LinkedList* list, void* value);

#endif
