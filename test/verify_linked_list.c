#include "verify_linked_list.h";
#include "../linked_list/linked_list.h";
#include "../double_linked_list/double_linked_list.h";
#include "stdlib.h";
#include "stdio.h";

void verify_linked_list_integrity(LinkedList* list, const int* values, const int size) {
    if (list == NULL) return;
    printf("[LINKED_LIST] Verificando tamanho da lista após inserção: ");
    if (list->size != size) {
        printf("\nErro ao inserir no ínicio da lista encadeada\n");
        return;
    }
    printf("OK\n");
    Node* node = list->first;
    printf("[LINKED_LIST] Verificando integridade da lista encadeada: ");
    for (int i = size - 1; i >= 0; i--) {
        if ((int*)node->value != (int*) values[i]) {
            printf("\nErro durante verificação de integridade da lista encadeada\n");
            return;
        }
        node = node->next;
    }
    printf("OK\n");
    printf("[LINKED_LIST] Verificando integridade de busca da lista encadeada: ");
    for (int i = size - 1; i >= 0; i--) {
        node = search_node(list, (void*) values[i]);
        if ((int*)node->value != (int*) values[i]) {
            printf("\nErro durante verificação de integridade da busca em lista encadeada\n");
            return;
        }
    }
    printf("OK\n");
    printf("[LINKED_LIST] Verificando integridade da remoção de nó: ");
    for (int i = 0; i < size; i++) {
        remove_node(list, (void*) values[i]);
        if (search_node(list, (void*) values[i]) != NULL) {
            printf("\nErro ao remover nó\n");
            return;
        }
    }
    if (list->size > 0) printf("\nErro ao limpar lista\n");
    printf("OK\n");
}

void verify__double_linked_list_integrity(DoubleLinkedList* list, const int* values, const int size) {
    if (list == NULL) return;
    printf("[DOUBLE_LINKED_LIST] Verificando tamanho da lista após inserção: ");
    if (list->size != size) {
        printf("\n[DOUBLE_LINKED_LIST] Erro ao inserir no ínicio da lista encadeada\n");
        return;
    }
    printf("OK\n");
    DNode* node = list->first;
    printf("[DOUBLE_LINKED_LIST] Verificando integridade da lista encadeada: ");
    for (int i = size - 1; i >= 0; i--) {
        if ((int*)node->value != (int*) values[i]) {
            printf("\nErro durante verificação de integridade da lista encadeada\n");
            return;
        }
        node = node->next;
    }
    printf("OK\n");
    printf("[DOUBLE_LINKED_LIST] Verificando integridade de busca da lista encadeada: ");
    for (int i = size - 1; i >= 0; i--) {
        node = d_search_node(list, (void*) values[i]);
        if ((int*)node->value != (int*) values[i]) {
            printf("\nErro durante verificação de integridade da busca em lista encadeada\n");
            return;
        }
    }
    printf("OK\n");
    printf("[DOUBLE_LINKED_LIST] Verificando integridade da remoção de nó: ");
    for (int i = 0; i < size; i++) {
        d_remove_node(list, (void*) values[i]);
        if (d_search_node(list, (void*) values[i]) != NULL) {
            printf("\nErro ao remover nó\n");
            return;
        }
    }
    if (list->size > 0) printf("\nErro ao limpar lista\n");
    printf("OK\n");
}

void verify_linked_list(int* values, const int size) {
    LinkedList* list = malloc(sizeof(LinkedList));
    printf("[LINKED_LIST] Verficando inserção ao ínicio da lista: ");
    for (int i = 0; i < size; i++)
    {
        insert_start(list, (void*) values[i]);
    }
    printf("OK\n");
    verify_linked_list_integrity(list, values, size);
    printf("[LINKED_LIST] Verficando inserção ao final da lista: ");
    for (int i = size - 1; i >= 0; i--)
    {
        insert_end(list, (void*) values[i]);
    }
    printf("OK\n"); 
    verify_linked_list_integrity(list, values, size);
    DoubleLinkedList* dList = malloc(sizeof(DoubleLinkedList));
    printf("[DOUBLE_LINKED_LIST] Verficando inserção ao ínicio da lista: ");
    for (int i = 0; i < size; i++)
    {
        d_insert_start(list, (void*) values[i]);
    }
    printf("OK\n");
    printf("[DOUBLE_LINKED_LIST] Verficando inserção ao final da lista: ");
    for (int i = size - 1; i >= 0; i--)
    {
        insert_end(list, (void*) values[i]);
    }
    printf("OK\n");
    verify__double_linked_list_integrity(dList, values, size);

}