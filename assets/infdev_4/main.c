#include <stdio.h>

int soma_20(int x) {
    return x + 20;
}

int quadrado(int x) {
    return x * x; 
}

void apply(int *x, int len, int (*fun)(int)) {
    for (int i = 0; i < len; i++)
        x[i] = fun(x[i]);
}

void print_lista(int *x, int len) {
    printf("Lista: ");
    for (int i = 0; i < len; i++)
        printf("%d ", x[i]);
    printf("\n");
}

int main() {
    int lista[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(lista)/sizeof(int); // sizeof(lista) indica o tamanho da lista em bytes, sizeof(int) diz o tamanho de um int em bytes
     
    print_lista(&lista[0], len);      // Lista: 1 2 3 4 5 6 7 8 9 10
    
    apply(&lista[0], len, &quadrado);
    print_lista(&lista[0], len);      // Lista: 1 4 9 16 25 36 49 64 81 100 

    apply(&lista[0], len, &soma_20);
    print_lista(&lista[0], len);      // Lista: 21 24 29 36 45 56 69 84 101 120 

    return 0;
}