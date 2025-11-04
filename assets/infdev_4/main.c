#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa {
    char *nome;
    int idade;
    char *(*toString)(struct Pessoa*);
    void (*free)(struct Pessoa*);
} Pessoa;

char *toStringPessoa(Pessoa *p) {
    // +1 para o caracteres nulo \0 no final da string
    int tamanho = snprintf(NULL, 0, "Nome: %s\nIdade: %d", p->nome, p->idade) + 1;
    
    char *resultado = malloc(tamanho);
    if (!resultado) return NULL;
    
    snprintf(resultado, tamanho, "Nome: %s\nIdade: %d", p->nome, p->idade);
    return resultado;
}

void freePessoa(Pessoa *p) {
    free(p->nome);
    free(p);
    p = NULL;
}

// Metodo construtor
Pessoa *newPessoa(char *nome, int idade) {
    Pessoa *p = malloc(sizeof(Pessoa)); 
    if (!p) return NULL;

    p->nome = malloc(strlen(nome) + 1);
    memcpy(p->nome, nome, strlen(nome) + 1);

    p->idade = idade;
    p->toString = toStringPessoa;
    p->free = freePessoa;

    return p;
}

int main() {
    Pessoa *p1 = newPessoa("Marceline", 23);
    if (!p1) return -1;

    printf("%s\n", p1->toString(p1));
    p1->free(p1);
    return 0;
}