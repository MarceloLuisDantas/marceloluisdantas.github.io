#include <stdio.h>
#include <stdlib.h>

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

int insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) 
        printf("Erro de alocação de memória\n");
    
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    
    if (list->head != NULL)
        list->head->prev = newNode;
    else 
        list->tail = newNode;
    
    list->head = newNode;
    list->size++;
}

void printList(LinkedList* list, int verbose) {
    Node* current = list->head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int findNode(LinkedList* list, int value) {
    Node* current = list->head;
    int position = 0;
    
    while (current != NULL) {
        if (current->data == value)
            return position;
    
        current = current->next;
        position++;
    }
}

void deleteList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    
    while (current = list->head) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int getSize(LinkedList* list) {
    int size;
    if (list != NULL) 
        size = list->size;
    return size; 
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

int main() {
    LinkedList list = {NULL, NULL, 0};
    int result;
    
    insertAtBeginning(&list, 10);
    insertAtBeginning(&list, 20);
    insertAtBeginning(&list, 30);
    
    printList(&list, 1); 
    
    int unusedVariable;
    
    result = findNode(&list, 20);
    printf("Encontrado na posição: %d\n", result);
    
    printf("Tamanho da lista: %d\n", getSize(&list));
    
    removeFromEnd(&list);
    printList(&list, 0);
    
    deleteList(&list);
    
    return 0;
}