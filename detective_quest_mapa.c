#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um cômodo da mansão
typedef struct Comodo {
    char nome[50];
    char descricao[200];
    struct Comodo *esquerda;  // Cômodo à esquerda
    struct Comodo *direita;   // Cômodo à direita
} Comodo;

// Função para criar um novo cômodo
Comodo* criarComodo(const char *nome, const char *descricao) {
    Comodo *novoComodo = (Comodo*)malloc(sizeof(Comodo));
    if (novoComodo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(novoComodo->nome, nome);
    strcpy(novoComodo->descricao, descricao);
    novoComodo->esquerda = NULL;
    novoComodo->direita = NULL;
    return novoComodo;
}

// Função para construir o mapa da mansão
Comodo* construirMapa() {
    // Entrada (raiz da árvore)
    Comodo *entrada = criarComodo("Entrada Principal", 
        "Um grande hall com um lustre de cristal. Portas à esquerda e direita.");
    
    // Lado esquerdo da mansão
    entrada->esquerda = criarComodo("Biblioteca", 
        "Estantes repletas de livros antigos. Há uma porta secreta na parede.");
    entrada->esquerda->esquerda = criarComodo("Escritório", 
        "Mesa de mogno com documentos espalhados. Cheiro de charuto no ar.");
    entrada->esquerda->direita = criarComodo("Sala de Música", 
        "Piano de cauda coberto de poeira. Partituras antigas sobre o piano.");
    
    // Lado direito da mansão
    entrada->direita = criarComodo("Sala de Jantar", 
        "Mesa longa com 12 cadeiras. Talheres de prata ainda sobre a mesa.");
    entrada->direita->esquerda = criarComodo("Cozinha", 
        "Fogão a lenha antigo. Utensílios pendurados nas paredes.");
    entrada->direita->direita = criarComodo("Salão de Festas", 
        "Amplo espaço com espelhos nas paredes. Pista de dança central.");
    
    return entrada;
}

// Função para exibir o cômodo atual
void exibirComodo(Comodo *comodo) {
    printf("\n============================================\n");
    printf("Localização: %s\n", comodo->nome);
    printf("============================================\n");
    printf("%s\n", comodo->descricao);
    printf("\nOpções de movimento:\n");
    
    if (comodo->esquerda != NULL) {
        printf("  [E] Ir para a esquerda (%s)\n", comodo->esquerda->nome);
    }
    if (comodo->direita != NULL) {
        printf("  [D] Ir para a direita (%s)\n", comodo->direita->nome);
    }
    printf("  [V] Voltar\n");
    printf("  [S] Sair da mansão\n");
    printf("\nEscolha uma opção: ");
}

// Função para percorrer o mapa (travessia in-ordem)
void percorrerInOrdem(Comodo *comodo) {
    if (comodo != NULL) {
        percorrerInOrdem(comodo->esquerda);
        printf("- %s\n", comodo->nome);
        percorrerInOrdem(comodo->direita);
    }
}

// Função para exibir o mapa completo
void exibirMapaCompleto(Comodo *raiz) {
    printf("\n========== MAPA DA MANSÃO ==========\n");
    printf("Cômodos disponíveis:\n");
    percorrerInOrdem(raiz);
    printf("====================================\n\n");
}

// Função para liberar memória da árvore
void liberarMapa(Comodo *comodo) {
    if (comodo != NULL) {
        liberarMapa(comodo->esquerda);
        liberarMapa(comodo->direita);
        free(comodo);
    }
}

// Função principal de navegação
void navegarMansao(Comodo *raiz) {
    Comodo *atual = raiz;
    Comodo *historico[100];  // Pilha para histórico de navegação
    int topo = -1;
    char opcao;
    
    printf("\n===== BEM-VINDO AO DETECTIVE QUEST =====\n");
    printf("Explore a mansão misteriosa...\n");
    
    while (1) {
        exibirComodo(atual);
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case 'E':
            case 'e':
                if (atual->esquerda != NULL) {
                    historico[++topo] = atual;
                    atual = atual->esquerda;
                } else {
                    printf("\nNão há caminho à esquerda!\n");
                }
                break;
                
            case 'D':
            case 'd':
                if (atual->direita != NULL) {
                    historico[++topo] = atual;
                    atual = atual->direita;
                } else {
                    printf("\nNão há caminho à direita!\n");
                }
                break;
                
            case 'V':
            case 'v':
                if (topo >= 0) {
                    atual = historico[topo--];
                } else {
                    printf("\nVocê já está na entrada!\n");
                }
                break;
                
            case 'S':
            case 's':
                printf("\nSaindo da mansão... Até a próxima investigação!\n");
                return;
                
            case 'M':
            case 'm':
                exibirMapaCompleto(raiz);
                break;
                
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}

int main() {
    // Construir o mapa da mansão
    Comodo *mapa = construirMapa();
    
    // Navegar pela mansão
    navegarMansao(mapa);
    
    // Liberar memória alocada
    liberarMapa(mapa);
    
    return 0;
}
