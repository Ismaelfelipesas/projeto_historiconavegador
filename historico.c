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

// Fun��es para salvar e carregar o hist�rico
void saveHistory(BrowserHistory *history) {
    FILE *file;
    int i;

    file = fopen("historico.txt", "w");
    if (!file) {
        printf("Erro ao salvar o hist�rico.\n");
        return;
    }

    fprintf(file, "%d\n", history->current); // Salva a posi��o atual
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
        // Se o arquivo n�o existir, inicializa o hist�rico vazio
        history->current = -1;
        history->total = 0;
        return;
    }

    fscanf(file, "%d", &history->current); // Carrega a posi��o atual
    fscanf(file, "%d", &history->total);  // Carrega o total de URLs

    for (i = 0; i < history->total; i++) {
        fscanf(file, "%s", history->urls[i]); // Carrega cada URL
    }

    fclose(file);
}

// Fun��es do navegador
void visitPage(BrowserHistory *history, const char *url) {
    if (history->current < MAX_HISTORY - 1) {
        history->current++;
        strcpy(history->urls[history->current], url);
        history->total = history->current + 1; // Remove o "futuro"
    } else {
        printf("Hist�rico cheio! N�o � poss�vel adicionar mais URLs.\n");
    }
}

void goBack(BrowserHistory *history) {
    if (history->current > 0) {
        history->current--;
    } else {
        printf("N�o h� p�ginas anteriores!\n");
    }
}

void goForward(BrowserHistory *history) {
    if (history->current < history->total - 1) {
        history->current++;
    } else {
        printf("N�o h� p�ginas futuras!\n");
    }
}

void displayCurrentPage(BrowserHistory *history) {
    if (history->current >= 0) {
        printf("P�gina atual: %s\n", history->urls[history->current]);
    } else {
        printf("Nenhuma p�gina visitada ainda!\n");
    }
}

// Menu principal
void menu(BrowserHistory *history) {
    int option;
    char url[MAX_URL];

    do {
        printf("\nMenu:\n");
        printf("1. Visitar p�gina\n");
        printf("2. Voltar\n");
        printf("3. Avan�ar\n");
        printf("4. Mostrar p�gina atual\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
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
                saveHistory(history); // Salva o hist�rico antes de sair
                printf("Hist�rico salvo. Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (option != 5);
}

int main() {
    BrowserHistory history;

    loadHistory(&history); // Carrega o hist�rico no in�cio
    menu(&history);

    return 0;
}
