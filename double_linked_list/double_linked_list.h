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


void d_insert_start(DoubleLinkedList* list, void* value);
void d_insert_end(DoubleLinkedList* list, void* value);
DNode* d_search_node(DoubleLinkedList* list, void* value);
void d_remove_node(DoubleLinkedList* list, void* value);

#endif
