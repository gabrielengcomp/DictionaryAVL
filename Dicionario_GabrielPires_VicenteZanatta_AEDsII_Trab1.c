#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char palavra[30];
    char significado[300];
    int fb;
    struct no *pai;
    struct no *esq;
    struct no *dir;
}No;

typedef struct Arvore{
    No *raiz;  
}Arv;

Arv* criaArvore(){
    Arv* nova = (Arv*) malloc(sizeof(Arv));
    nova->raiz = NULL;
    printf("Arvore vazia criada com successo\n");
    return nova;
}
No* criaNo(char* palavra, char* significado) {
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->palavra, palavra);
    strcpy(novo->significado, significado);
    novo->fb = 0;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int altura(No* no) {
    if (no == NULL) {
        return 0; // Árvore vazia ou fim do ramo
    }
    int alturaesq = altura(no->esq);
    int alturadir = altura(no->dir);
    if (alturaesq>alturadir){
        return alturaesq + 1;
    }
    else{
        return alturadir + 1;
    }
}
int fb(No* no){
    if (no == NULL) {
        return 0; // Nó nulo tem fator de balanceamento zero
    }
    return (altura(no->esq) - altura(no->dir));
}
No* RR(No* d) {
    No* aux = d->esq; // Subárvore esquerda
    if (aux->dir) {
        aux->dir->pai = d;
    }
    d->esq = aux->dir;
    aux->dir = d;

    // Ajusta os ponteiros pai
    aux->pai = d->pai;
    if (d->pai) { // Se d não é raiz
        if (d->pai->esq == d) {
            d->pai->esq = aux;
        } else {
            d->pai->dir = aux;
        }
    }
    d->pai = aux;

    return aux; // Retorna o novo nó raiz da subárvore
}


No* LL(No* d) {
    No* aux = d->dir; // Subárvore direita
    if (aux->esq) {
        aux->esq->pai = d;
    }
    d->dir = aux->esq;
    aux->esq = d;

    // Ajusta os ponteiros pai
    aux->pai = d->pai;
    if (d->pai) { // Se d não é raiz
        if (d->pai->esq == d) {
            d->pai->esq = aux;
        } else {
            d->pai->dir = aux;
        }
    }
    d->pai = aux;

    return aux; // Retorna o novo nó raiz da subárvore
}

No* RL(No* d) {
    d->dir = RR(d->dir); // Rotação RR no filho direito
    return LL(d);        // Rotação LL no nó atual
}

No* LR(No* d) {
    d->esq = LL(d->esq); // Rotação LL no filho esquerdo
    return RR(d);        // Rotação RR no nó atual
}


void Balanceamento(No* no, Arv* arv) {
    while (no != NULL) {
        no->fb = fb(no);
        if (no->fb == 2) {
            if (no->esq->fb >= 0) {
                No* novo_no = RR(no);
                if (arv->raiz == no) {
                    arv->raiz = novo_no; // Atualiza a raiz, se necessário
                }
            } else {
                No* novo_no = LR(no);
                if (arv->raiz == no) {
                    arv->raiz = novo_no; // Atualiza a raiz, se necessário
                }
            }
        } else if (no->fb == -2) {
            if (no->dir->fb <= 0) {
                No* novo_no = LL(no);
                if (arv->raiz == no) {
                    arv->raiz = novo_no; // Atualiza a raiz, se necessário
                }
            } else {
                No* novo_no = RL(no);
                if (arv->raiz == no) {
                    arv->raiz = novo_no; // Atualiza a raiz, se necessário
                }
            }
        }
        no = no->pai; // Sobe na árvore para continuar o balanceamento
    }
}


void insereAVL(Arv* arv, char* palavra, char* significado) {
    No* z = criaNo(palavra, significado);
    No* y = NULL;
    No* x = arv->raiz;

  
    while (x != NULL) {
        y = x;
        int comparacao = strcmp(z->palavra, x->palavra);
        if (comparacao == 0) {
            printf("\nPalavra '%s' já existe. Não será inserida.\n", palavra);
            free(z);
            return;
        } else if (comparacao < 0) {
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    
    z->pai = y;
    if (y == NULL) {
        arv->raiz = z; // Árvore estava vazia
        printf("\nPalavra %s inserida com sucesso\n", palavra);
    } else if (strcmp(z->palavra, y->palavra) < 0) {
        y->esq = z;
        printf("\nPalavra %s inserida com sucesso\n", palavra);        
    } else {
        y->dir = z;
        printf("\nPalavra %s inserida com sucesso\n", palavra);
    }

    Balanceamento(z, arv);
}

No* antecessor(No* no) {
    No* atual = no->esq;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

No* buscaNo(No* r, char* palavra) {
    while (r != NULL) {
        int comparacao = strcmp(palavra, r->palavra);
        if (comparacao == 0) {
            printf("\nPalavra encontrada: %s, %s\n", r->palavra, r->significado);
            return r; // Palavra encontrada
        } else if (comparacao < 0) {
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    printf("\nPalavra '%s' não encontrada\n", palavra);
    return NULL; // Palavra não encontrada
}



No* remocaoAVL(Arv* arv, No* r, char* palavra) {
    No* no = buscaNo(r, palavra);
    
    if(r == NULL){
        printf("\nERRO: Arvore vazia ou inexistente\n");
        return NULL;
    }   

    if (no == NULL) {
        printf("\nErro: Palavra '%s' não encontrada na árvore.\n", palavra);
        return r; // Retorna a raiz original sem alterações
    }

    // Caso 1: Nó folha
    if (no->esq == NULL && no->dir == NULL) {
        if (no->pai != NULL) {
            if (no->pai->esq == no) {
                no->pai->esq = NULL;
            } else {
                no->pai->dir = NULL;
            }
        } else {
            r = NULL; // Se for a raiz
        }
        printf("Palavra removida com sucesso: %s\n", palavra);
        free(no);
    }
    // Caso 2: Apenas um filho
    else if (no->esq == NULL || no->dir == NULL) {
        No* filho = (no->esq != NULL) ? no->esq : no->dir;

        if (no->pai != NULL) {
            if (no->pai->esq == no) {
                no->pai->esq = filho;
            } else {
                no->pai->dir = filho;
            }
        } else {
            r = filho; // Se for a raiz
        }
        filho->pai = no->pai;
        printf("Palavra removida com sucesso: %s\n", palavra);

        free(no);
    }
    // Caso 3: Dois filhos
    else {
        No* y = antecessor(no);
        strcpy(no->palavra, y->palavra);
        strcpy(no->significado, y->significado);
        no->esq = remocaoAVL(arv, no->esq, y->palavra); // Remove o antecessor
        printf("Palavra removida com sucesso: %s\n", palavra);

    }

    // Atualiza FB e reequilibra
    if (r != NULL) {
        Balanceamento(r, arv);
    }

    return r;
}
void Ordem(No* no){
    if(no == NULL) return;
    Ordem(no->esq);
    printf("\n%s\nSignificado: %s\n\n",no->palavra, no->significado);
    Ordem(no->dir);
}

void main(){
    char palavra[30];
    char significado[300];
    Arv* arv = NULL;
    int op = 0;

    while (1) {
        scanf("%d\n", &op);
        //printf("%d\n", op);
        switch (op) {
            case 1:
                arv = criaArvore();
                break;

            case 2:
                scanf("%s", palavra); 
                //printf("%s\n", palavra);
                remocaoAVL(arv, arv->raiz, palavra);
                break;

            case 3:
                scanf("%s\n", palavra);
                scanf("%[^\n]", significado); //lẽ até a quebra de linha
                insereAVL(arv, palavra, significado);
                //printf("%s SIG: %s\n", palavra, significado);
                break;

            case 4:
                scanf("%s", palavra); 
                //printf("%s\n", palavra);
                buscaNo(arv->raiz, palavra);    
                break;
            case 5:
                printf("\nImpressão em ordem alfabética\n");
                Ordem(arv->raiz);
                break;
            case 7:
                return;

            default:
                printf("!! OPCAO INVALIDA !!\n");
                break;
        }

    }
    return;
}
