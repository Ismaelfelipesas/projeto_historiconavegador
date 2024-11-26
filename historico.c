#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100
#define MAX_HISTORY 100

typedef struct {
    char urls[MAX_HISTORY][MAX_URL];
    int current;
    int total;
} BrowserHistory;

// Funções para salvar e carregar o histórico
void saveHistory(BrowserHistory *history) {
    FILE *file;
    int i;

    file = fopen("historico.txt", "w");
    if (!file) {
        printf("Erro ao salvar o histórico.\n");
        return;
    }

    fprintf(file, "%d\n", history->current); // Salva a posição atual
    fprintf(file, "%d\n", history->total);  // Salva o total de URLs

    for (i = 0; i < history->total; i++) {
        fprintf(file, "%s\n", history->urls[i]); // Salva cada URL
    }

    fclose(file);
}

void loadHistory(BrowserHistory *history) {
    FILE *file;
    int i;

    file = fopen("historico.txt", "r");
    if (!file) {
        // Se o arquivo não existir, inicializa o histórico vazio
        history->current = -1;
        history->total = 0;
        return;
    }

    fscanf(file, "%d", &history->current); // Carrega a posição atual
    fscanf(file, "%d", &history->total);  // Carrega o total de URLs

    for (i = 0; i < history->total; i++) {
        fscanf(file, "%s", history->urls[i]); // Carrega cada URL
    }

    fclose(file);
}

// Funções do navegador
void visitPage(BrowserHistory *history, const char *url) {
    if (history->current < MAX_HISTORY - 1) {
        history->current++;
        strcpy(history->urls[history->current], url);
        history->total = history->current + 1; // Remove o "futuro"
    } else {
        printf("Histórico cheio! Não é possível adicionar mais URLs.\n");
    }
}

void goBack(BrowserHistory *history) {
    if (history->current > 0) {
        history->current--;
    } else {
        printf("Não há páginas anteriores!\n");
    }
}

void goForward(BrowserHistory *history) {
    if (history->current < history->total - 1) {
        history->current++;
    } else {
        printf("Não há páginas futuras!\n");
    }
}

void displayCurrentPage(BrowserHistory *history) {
    if (history->current >= 0) {
        printf("Página atual: %s\n", history->urls[history->current]);
    } else {
        printf("Nenhuma página visitada ainda!\n");
    }
}

// Menu principal
void menu(BrowserHistory *history) {
    int option;
    char url[MAX_URL];

    do {
        printf("\nMenu:\n");
        printf("1. Visitar página\n");
        printf("2. Voltar\n");
        printf("3. Avançar\n");
        printf("4. Mostrar página atual\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o URL: ");
                scanf("%s", url);
                visitPage(history, url);
                break;
            case 2:
                goBack(history);
                break;
            case 3:
                goForward(history);
                break;
            case 4:
                displayCurrentPage(history);
                break;
            case 5:
                saveHistory(history); // Salva o histórico antes de sair
                printf("Histórico salvo. Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 5);
}

int main() {
    BrowserHistory history;

    loadHistory(&history); // Carrega o histórico no início
    menu(&history);

    return 0;
}
