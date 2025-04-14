#include <stdio.h>
#include <stdlib.h>

// Estrutura da pilha
typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

// FunÃ§Ã£o para criar a pilha
Pilha* criarPilha(int capacidade) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (int*) malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

// Adiciona um valor ao topo da pilha
void push(Pilha* p, int valor) {
    if (p->topo == p->capacidade - 1) {
        // Realoca com o dobro da capacidade
        p->capacidade *= 2;
        p->dados = realloc(p->dados, p->capacidade * sizeof(int));
        printf("Capacidade aumentada para %d.\n", p->capacidade);
    }
    p->dados[++p->topo] = valor;
}

// Remove o valor do topo
int pop(Pilha* p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo--];
}

// Mostra o topo da pilha
int topo(Pilha* p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}

// Mostra todos os elementos
void mostrar(Pilha* p) {
	int  i;
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Elementos da pilha (topo -> base):\n");
    for (i = p->topo; i >= 0; i--) {
        printf("%d\n", p->dados[i]);
    }
}

// Libera a memÃ³ria
void liberar(Pilha* p) {
    free(p->dados);
    free(p);
    printf("MemÃ³ria liberada.\n");
}

// Menu principal
int main() {
    Pilha* pilha = NULL;
    int opcao, valor;

    do {
        printf("\n==== MENU PILHA ====\n");
        printf("1 - Criar pilha\n");
        printf("2 - Inserir (push)\n");
        printf("3 - Remover (pop)\n");
        printf("4 - Ver topo\n");
        printf("5 - Mostrar pilha\n");
        printf("6 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (pilha != NULL) {
                    printf("Pilha jÃ¡ criada!\n");
                } else {
                    pilha = criarPilha(5);
                    printf("Pilha criada com capacidade inicial 5.\n");
                }
                break;
            case 2:
                if (pilha == NULL) {
                    printf("Crie a pilha primeiro!\n");
                } else {
                    printf("Valor: ");
                    scanf("%d", &valor);
                    push(pilha, valor);
                }
                break;
            case 3:
                if (pilha != NULL) {
                    int removido = pop(pilha);
                    if (removido != -1)
                        printf("Removido: %d\n", removido);
                } else {
                    printf("Crie a pilha primeiro!\n");
                }
                break;
            case 4:
                if (pilha != NULL) {
                    int t = topo(pilha);
                    if (t != -1)
                        printf("Topo: %d\n", t);
                } else {
                    printf("Crie a pilha primeiro!\n");
                }
                break;
            case 5:
                if (pilha != NULL) {
                    mostrar(pilha);
                } else {
                    printf("Crie a pilha primeiro!\n");
                }
                break;
            case 6:
                if (pilha != NULL) liberar(pilha);
                printf("Saindo...\n");
                break;
            default:
                printf("OpÃ§Ã£o invÃ¡lida!\n");
        }
    } while (opcao != 6);

    return 0;
}
