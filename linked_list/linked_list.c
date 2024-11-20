#include <stdlib.h>
#include <stdio.h>
#include "./linked_list.h"

void insert_start(LinkedList* list, void* value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    if (list->first == NULL) {
        list->first = node;
        list->size += 1;
        return;
    }
    node->next = list->first;
    list->first = node;
    list->size += 1;
}

void insert_end(LinkedList* list, void* value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    if (list->first == NULL) {
        list->first = node;
        list->size += 1;
        return;    
    }
    if (list->last == NULL) {
        list->last = node;
        list->first->next = node;
        list->size += 1;
        return;
    }
    list->last->next = node;
    list->last = node;
    list->size += 1;
}

Node* search_node(LinkedList* list, void* value) {
    if (list->first == NULL) return list->first;
    Node* actual = list->first;
    while(actual != NULL && actual->value != value) {
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
    if (list->last != NULL && list->last->value == value) {
        target = list->last;
        while (previous->next != target) previous = previous->next;
        previous->next = NULL;
        list->last = previous;
        free(target);
        list->size-=1;
        return;
    }
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