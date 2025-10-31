#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insertFront(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;
    
    if (list->head != NULL)
        list->head->prev = newNode;
    else
        list->tail = newNode;
    
    
    list->head = newNode;
    list->size++;
}

// Insere no final
void insertBack(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;
    
    if (list->tail != NULL)
        list->tail->next = newNode;
    else
        list->head = newNode;
    
    
    list->tail = newNode;
    list->size++;
}

int removeFront(LinkedList* list) {
    if (list->head == NULL)
        return -1; 
    
    Node* temp = list->head;
    int data = temp->data;
    
    list->head = list->head->next;
    if (list->head != NULL)
        list->head->prev = NULL;
    
    free(temp);
    list->size--;
    
    return data;
}


int removeBack(LinkedList* list) {
    if (list->tail == NULL)
        return -1; 
    
    Node* temp = list->tail;
    int data = temp->data;
    
    list->tail = list->tail->prev;
    
    if (list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;
        
    free(temp);
    list->size--;
    
    return data;
}

void printList(LinkedList* list) {
    Node* current = list->head;
    printf("Lista [%d elementos]: ", list->size);
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int main() {
    LinkedList list;
    initList(&list);
    
    insertFront(&list, 10);
    insertFront(&list, 20);
    insertBack(&list, 30);
    insertBack(&list, 40);
    
    printf("Lista inicial:\n");
    printList(&list);
    
    printf("\nRemovendo do início:\n");
    int val1 = removeFront(&list);
    printf("Removido: %d\n", val1);
    printList(&list);
    
    printf("\nRemovendo do final:\n");
    int val2 = removeBack(&list);
    printf("Removido: %d\n", val2);
    printList(&list);
    
    printf("\nRemovendo do início novamente:\n");
    int val3 = removeFront(&list);
    printf("Removido: %d\n", val3);
    printList(&list);
    
    int val4 = removeFront(&list); 
    printf("Removido: %d\n", val4);
    printList(&list);
    
    freeList(&list);
    return 0;
}