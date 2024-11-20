#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

typedef struct DNode DNode;

struct DNode {
	DNode* next;
    DNode* previous;
	void* value;
};

typedef struct {
	DNode* first;
	DNode* last;
	int	  size;
} DoubleLinkedList;


void insert_start(DoubleLinkedList* list, void* value);
void insert_end(DoubleLinkedList* list, void* value);
DNode* search_node(DoubleLinkedList* list, void* value);
void remove_node(DoubleLinkedList* list, void* value);

#endif
