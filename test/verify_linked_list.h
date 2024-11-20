#include "../linked_list/linked_list.h";
#include "../double_linked_list/double_linked_list.h";

#ifndef VERIFY_LINKED_LIST
#define VERIFY_LINKED_LIST

void verify_linked_list_integrity(LinkedList* list, const int* values, const int size);
void verify__double_linked_list_integrity(DoubleLinkedList* list, const int* values, const int size);
void verify_linked_list(int* values, const int size);

#endif