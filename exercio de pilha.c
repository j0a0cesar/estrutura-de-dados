#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;
No* criarNo(int valor) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

void push(No** topo, int valor) {
    No* novo = criarNo(valor);
    novo->proximo = *topo;
    *topo = novo;
}

void pop(No** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    No* temp = *topo;
    *topo = temp->proximo;
    printf("Elemento removido: %d\n", temp->valor);
    free(temp);
}

void mostrarPilha(No* topo) {
    printf("Pilha: ");
    while (topo != NULL) {
        printf("%d -> ", topo->valor);
        topo = topo->proximo;
    }
    printf("NULL\n");
}

void buscarValor(No* topo, int valor) {
    while (topo != NULL) {
        if (topo->valor == valor) {
            printf("Valor %d encontrado na pilha.\n", valor);
            return;
        }
        topo = topo->proximo;
    }
    printf("Valor %d nao encontrado na pilha.\n", valor);
}

void contarNos(No* topo) {
    int contador = 0;
    while (topo != NULL) {
        contador++;
        topo = topo->proximo;
    }
    printf("Total de nos na pilha: %d\n", contador);
}

void liberarPilha(No* topo) {
    while (topo != NULL) {
        No* temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}
int main() {
    No* pilha = NULL;

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    push(&pilha, 40);

    mostrarPilha(pilha);
    contarNos(pilha);
    buscarValor(pilha, 20);
    
    printf("\nRemovendo elementos do topo:\n");
    pop(&pilha);
    pop(&pilha);

    mostrarPilha(pilha);

    liberarPilha(pilha);

    return 0;
}
