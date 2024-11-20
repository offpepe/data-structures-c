#include <stdlib.h>
#include <stdio.h>
#include "linked_list/linked_list.h"

#define VALUES_SIZE 10

void verify_linked_list_integrity(LinkedList* list, const int* values) {
    if (list == NULL) return;
    printf("Verificando tamanho da lista após inserção: ");
    if (list->size != VALUES_SIZE) {
        printf("\nErro ao inserir no ínicio da lista encadeada");
        return;
    }
    printf("OK\n");
    Node* node = list->first;
    printf("Verificando integridade da lista encadeada: ");
    for (int i = VALUES_SIZE - 1; i >= 0; i--) {
        if ((int*)node->value != (int*) values[i]) {
            printf("\nErro durante verificação de integridade da lista encadeada");
            return;
        }
        node = node->next;
    }
    printf("OK\n");
    printf("Verificando integridade de busca da lista encadeada: ");
    for (int i = VALUES_SIZE - 1; i >= 0; i--) {
        node = search_node(list, (void*) values[i]);
        if ((int*)node->value != (int*) values[i]) {
            printf("\nErro durante verificação de integridade da busca em lista encadeada");
            return;
        }
    }
    printf("OK\n");
    printf("Verificando integridade da remoção de nó: ");
    for (int i = 0; i < VALUES_SIZE; i++) {
        remove_node(list, (void*) values[i]);
        if (search_node(list, (void*) values[i]) != NULL) {
            printf("\nErro ao remover nó");
            return;
        }
    }
    if (list->size > 0) printf("\nErro ao limpar lista");
    printf("OK\n");
}

void verify_linked_list(int* values) {
    LinkedList* list = malloc(sizeof(LinkedList));
    printf("Verficando inserção ao ínicio da lista: ");
    for (int i = 0; i < VALUES_SIZE; i++)
    {
        insert_start(list, (void*) values[i]);
    }
    printf("OK\n");
    verify_linked_list_integrity(list, values);
    printf("Verficando inserção ao final da lista: ");
    for (int i = VALUES_SIZE - 1; i >= 0; i--)
    {
        insert_end(list, (void*) values[i]);
    }
    printf("OK\n"); 
    verify_linked_list_integrity(list, values);
}

int main() {
    int values[10] = {1,2,3,4,5,6,7,8,9,10};
    verify_linked_list(values);
}