#include <stdlib.h>
#include <stdio.h>
#include "randomiza.c"

Fila *inicializaFila()
{
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            colocaDadoFila(j, i, f);
        }
    }
    return f;
}

void imprimeFila(Fila *f)
{
    Carta *iterador;
    iterador = f->inicio;
    while (iterador != NULL)
    {
        switch (iterador->c_Naipe)
        {
        case Copas:
            printf("♥");
            break;
        case Ouros:
            printf("♦");
            break;
        case Paus:
            printf("♣");
            break;
        case Espadas:
            printf("♠");
            break;
        }
        if (iterador->c_Valor < Valete)
        {
            printf("%i", iterador->c_Valor + 2);
        }
        else
        {
            switch (iterador->c_Valor)
            {
            case Valete:
                printf("J");
                break;
            case Dama:
                printf("Q");
                break;
            case Rei:
                printf("K");
                break;
            case As:
                printf("A");
                break;
            }
        }
        printf("\n");
        iterador = iterador->prox;
    }
    printf("  ");
}

// aqui estava o codigo para aplicao em pilha, mas o inicializaPilha esta pra fazer um baralho novo
/*typedef struct pilha {
    Carta *topo;
} Pilha;

void colocaDado(int n, int v, Pilha *p) {
    Carta *novoDado;
    novoDado = (Carta *)malloc(sizeof(Carta));
    novoDado->c_Naipe = n;
    novoDado->c_Valor = v;
    novoDado->prox = p->topo;
    p->topo = novoDado;
}

Pilha *inicializaPilha() {
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            colocaDado(j,i,p);
        }
    }
    return p;
}

void imprimePilha(Pilha *p) {
    Carta *iterador;
    iterador = p->topo;
    while (iterador != NULL) {
        switch(iterador->c_Naipe) {
            case Copas:
              printf("♥");
              break;
            case Ouros:
              printf("♦");
              break;
            case Paus:
              printf("♣");
              break;
            case Espadas:
              printf("♠");
              break;
        }
        if(iterador->c_Valor<Dama){
            printf("%i",iterador->c_Valor+2);
        }else{
            switch(iterador->c_Valor) {
                case Valete:
                    printf("J");
                    break;
                case Dama:
                    printf("Q");
                    break;
                case Rei:
                    printf("K");
                    break;
                case As:
                    printf("A");
                    break;
            }
        }
        printf("\n");
        iterador = iterador->prox;
    }
    printf("  ");
}*/

int main()
{
    srand(time(0));
    Fila *f = inicializaFila();
    f = embaralhaFila(f);
    imprimeFila(f);
}