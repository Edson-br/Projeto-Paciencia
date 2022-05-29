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

typedef struct pilha {
    Carta *topo;
} Pilha;

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

void colocaDado(int n, int v, Pilha *p) {
    Carta *novoDado;
    novoDado = (Carta *)malloc(sizeof(Carta));
    novoDado->c_Naipe = n;
    novoDado->c_Valor = v;
    novoDado->prox = p->topo;
    p->topo = novoDado;
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
	printf("\n");
}

int main()
{
    Pilha *p = inicializaPilha();
    imprimePilha(p);
}