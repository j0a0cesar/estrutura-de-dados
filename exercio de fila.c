#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

No* criarNo(int valor) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

void adicionarFinal(No** cabeca, int valor) {
    No* novo = criarNo(valor);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->anterior = atual; // liga de trás para frente
    }
}

void removerInicio(No** cabeca) {
    if (*cabeca == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    No* temp = *cabeca;
    *cabeca = temp->proximo;
    if (*cabeca != NULL)
        (*cabeca)->anterior = NULL;
    free(temp);
}

void mostrarFila(No* cabeca) {
    printf("Fila: ");
    while (cabeca != NULL) {
        printf("%d <-> ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("NULL\n");
}

void liberarFila(No* cabeca) {
    while (cabeca != NULL) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }
}

void mostrarFilaInvertida(No* cabeca) {
    if (cabeca == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    // Vai até o último nó
    No* atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    // Imprime do último ao primeiro
    printf("Fila invertida: ");
    while (atual != NULL) {
        printf("%d <-> ", atual->valor);
        atual = atual->anterior;
    }
    printf("NULL\n");
}

void contarNos(No* cabeca){
	
	 int count = 0;
    while (cabeca != NULL) {

        cabeca = cabeca->proximo;
        count++;
    }
    printf("\nConatdor de nos: %d",count);
   
}

void buscarValor(No* cabeca, int pesquisa) {
    No* atual = cabeca;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->valor == pesquisa) {
            printf("\nO numero buscado: %d foi encontrado na fila.\n", pesquisa);
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }

    if (!encontrado) {
        printf("\nNumero pesquisado %d nao foi encontrado na fila.\n", pesquisa);
    }
}

int main() {
    No* fila = NULL;

    adicionarFinal(&fila, 10);
    mostrarFila(fila);

    adicionarFinal(&fila, 20);
    mostrarFila(fila);

    adicionarFinal(&fila, 30);
    mostrarFila(fila);

    adicionarFinal(&fila, 40);
    mostrarFila(fila);

    adicionarFinal(&fila, 50);
    mostrarFila(fila);
    
    mostrarFilaInvertida(fila);
	
	contarNos(fila);
    
    buscarValor(&fila,10);
    
    // Liberar memória
    liberarFila(fila);

    return 0;
}

/* Teste de remoção
    printf("Removendo elemento do inicio...\n");
    removerInicio(&fila);
    mostrarFila(fila);*/
