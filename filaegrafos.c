#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// ---------- ESTRUTURAS ----------

typedef struct No {
    int vizinho;
    struct No* proximo;
} No;

typedef struct NoPilha {
    int valor;
    struct NoPilha* proximo;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

// ---------- VARIÁVEIS GLOBAIS ----------

No* grafo[TAM];       // Lista de adjacência
int visitado[TAM];    // Visitados para BFS
int fila[TAM];        // Fila para BFS
int inicio = 0, fim = 0;

// ---------- FILA ----------

void enfileirar(int valor) {
    fila[fim++] = valor;
}

int desenfileirar() {
    return fila[inicio++];
}

int filaVazia() {
    return inicio == fim;
}

// ---------- PILHA ----------

void inicializar(Pilha* p) {
    p->topo = NULL;
    printf("Pilha foi criada com topo nulo\n");
    
}

void push(Pilha* p, int valor) {
    NoPilha* novo = malloc(sizeof(NoPilha));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pop(Pilha* p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    NoPilha* temp = p->topo;
    int valor = temp->valor;
    p->topo = temp->proximo;
    free(temp);
    return valor;
}

int topo(Pilha* p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->topo->valor;
}

// ---------- GRAFO ----------

void adicionarAresta(int origem, int destino) {
    No* novo = malloc(sizeof(No));
    novo->vizinho = destino;
    novo->proximo = grafo[origem];
    grafo[origem] = novo;
}

void bfs(int inicioBusca, int destino) {
	int i;
    for (i = 0; i < TAM; i++) {
        visitado[i] = 0;
    }

    enfileirar(inicioBusca);
    visitado[inicioBusca] = 1;

    while (!filaVazia()) {
        int atual = desenfileirar();
        printf("Visitando: %d\n", atual);

        if (atual == destino) {
            printf("Destino %d encontrado!\n", destino);
            return;
        }

        No* temp = grafo[atual];
        while (temp != NULL) {
            if (!visitado[temp->vizinho]) {
                enfileirar(temp->vizinho);
                visitado[temp->vizinho] = 1;
            }
            temp = temp->proximo;
        }
    }

    printf("Destino %d não foi encontrado.\n", destino);
}

// ---------- MAIN ----------

int main() {
	int i;
    // Inicializar lista de adjacência
    for (i = 0; i < TAM; i++) {
        grafo[i] = NULL;
    }

    adicionarAresta(0, 1);
    adicionarAresta(0, 2);
    adicionarAresta(1, 3);
    adicionarAresta(2, 4);
    adicionarAresta(2, 6);
    adicionarAresta(3, 2);
    adicionarAresta(4, 5);
    adicionarAresta(5, 6);

    int origem = 0;
    int destino = 6;
    bfs(origem, destino);
    
    
	 Pilha p;
     inicializar(&p);

    return 0;
}
