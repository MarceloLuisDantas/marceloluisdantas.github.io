#include <stdio.h>

// Funções de exemplo
int dobrar(int x) { 
    return x * 2; 
}

int triplicar(int x) { 
    return x * 3; 
}

static int aplicar_duas_vezes(int x) {
        return funcao_entrada(funcao_entrada(x));
    }

// 🔥 FUNÇÃO CRUA: recebe e retorna ponteiro para função
// int (*      receber_e_retornar_funcao(      int (*funcao_entrada)(int)      ))(int)
int (*receber_e_retornar_funcao(int (*funcao_entrada)(int)))(int) {
    // Retorna uma nova função que aplica a função de entrada duas vezes
    
    
    return aplicar_duas_vezes;
}

int main() {
    // 🔥 Uso também cru:
    // int (*      nova_funcao      )(int) = receber_e_retornar_funcao(dobrar);
    int (*nova_funcao)(int) = receber_e_retornar_funcao(dobrar);
    
    printf("Dobrar duas vezes de 3: %d\n", nova_funcao(3)); // 12
    
    // 🔥 Chamada direta ainda mais crua:
    int resultado = receber_e_retornar_funcao(triplicar)(2);
    printf("Triplicar duas vezes de 2: %d\n", resultado); // 18
    
    return 0;
}