#include "double_linked_list/double_linked_list.h"
#include "stdlib.h"

void d_insert_start(DoubleLinkedList *list, void *value)
{
    DNode *node = malloc(sizeof(DNode));
    node->value = value;
    if (list->first == NULL)
    {
        list->first = node;
        list->size += 1;
        return;
    }
    if (list->last == NULL)
    {
        list->last = node;
        list->last->previous = list->first;
        list->first->next = node;
        list->size += 1;
        return;
    }
    node->next = list->first;
    node->next->previous = node;
    list->first = node;
    list->size += 1;
}

void d_insert_end(DoubleLinkedList *list, void *value)
{
    DNode *node = malloc(sizeof(DNode));
    node->value = value;
    if (list->first == NULL)
    {
        list->first = node;
        list->size += 1;
        return;
    }
    if (list->last == NULL)
    {
        list->last = node;
        list->last->previous = list->first;
        list->first->next = node;
        list->size += 1;
        return;
    }
    node->previous = list->last;
    list->last->next = node;
    list->last = node;
    list->size += 1;
}

DNode* d_search_node(DoubleLinkedList* list, void* value) {
    if (list->first == NULL) return NULL;
    DNode* right = list->first;
    DNode* left = list->last;
    if (left == NULL && right->value != value) return NULL;
    while(right->next != left) {
        if (right->value == value) return right;
        if (left->value == value) return left;
        right = right->next;
        left = left->previous;
    }
    return NULL;
}

void d_remove_node(DoubleLinkedList* list, void* value) {
    DNode* target = d_search_node(list, value);
    if (target->next == NULL) {
        list->last = target->previous != list->first ? target->previous : NULL;
        list->size -= 1;
    } else if (target->previous == NULL) {
        target->next->previous = NULL;
        list->first = target->next;
    } else {
        target->previous->next = target->next->previous;
    }
    list->size-=1;
    free(target);
}