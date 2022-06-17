#include <stdlib.h>
#include <stdio.h>

typedef enum naipe{
	Paus, Copas, Espadas, Ouros
} Naipe;

typedef enum valor{
	 Dois, Tres, Quatro, Cinco, Seis, Sete, Oito, Nove, Dez, Dama, Valete, Rei, As
} Valor ;

typedef struct carta{
    struct carta *prox;
    Naipe c_Naipe;
    Valor c_Valor;
} Carta;

typedef struct fila {
    Carta *inicio;
    Carta *fim;
} Fila;


void colocaDadoFila(int n, int v, Fila *f) {
    Carta *novoDado;
    novoDado = (Carta *)malloc(sizeof(Carta));
    novoDado->c_Naipe = n;
    novoDado->c_Valor = v;
    novoDado->prox = NULL;
    if (f->inicio == NULL && f->fim == NULL)
    {
        f->fim = f->inicio = novoDado;
    }
    else
    {
        f->fim->prox = novoDado;
        f->fim = novoDado;
    }
}

Fila *inicializaFila() {
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            colocaDadoFila(j,i,f);
        }
    }
    return f;
}

void imprimeFila(Fila *f) {
    Carta *iterador;    
    iterador = f->inicio;
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
}

//aqui estava o codigo para aplicao em pilha, mas o inicializaPilha esta pra fazer um baralho novo
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
    Fila *f = inicializaFila();
    imprimeFila(f);
}