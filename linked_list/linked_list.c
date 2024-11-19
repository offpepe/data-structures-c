#include "./linked_list.h"

void insert_start(LinkedList* list, Node* node) {
    if (list->first == NULL) {
        list->first = node;
        list->size += 1;
        return;
    }
    node->next = list->first;
    list->first = node;
    list->size += 1;
}

void insert_end(LinkedList* list, Node* node) {
    if (list->first == NULL) {
        list->first = node;
        list->size += 1;
        return;    
    }
    list->last->next = node;
    list->last = node;
    list->size += 1;
}

Node* search_node(LinkedList* list, void* value) {
    Node* actual = list->first;
    while(actual->value != &value) {
        if (actual == NULL) break;
        actual = actual->next;
    }
    return actual;
}

void remove_node(LinkedList* list, void* value) {
    Node* target;
    if (list->first->value == value) {
        target = list->first;
        list->first = list->first->next;
        list->size-=1;
        free(target);
        return;
    }
    Node* previous = list->first;
    target = previous->next;
    while(target->value != value) {
        if (target->next == NULL) {
            return;
        }
        previous = target;
        target = target->next;
    }
    previous->next = target->next;
    list->size -= 1;
    free(target);
}