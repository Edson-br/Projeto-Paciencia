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

int trasferencia(Pilha *inicial, Pilha *final, int n)
{ // funcao que recebe a pilha incial e fina e quantas caratas serao transferidas
    Pilha *aux = inicializaPilha();

    for (int i = 0; i < n; i++)
    { // passa o numero de cartas para a aux
        colocaDadoPilha(inicial->topo->c_Naipe, inicial->topo->c_Valor, aux);
        retiraDadoPilha(inicial);
    } // aqui eh comparado se o valor do topo da aux eh 1 maior que a aux e se os naipes sao de cores diferentes
    if ((aux->topo->c_Valor == final->topo->c_Valor - 1) && ((aux->topo->c_Naipe % 2 == 0 && final->topo->c_Naipe % 2 == 1) || (aux->topo->c_Naipe % 2 == 1 && final->topo->c_Naipe % 2 == 0)))
    {
        while (aux->topo != NULL)
        {
            colocaDadoPilha(aux->topo->c_Naipe, aux->topo->c_Valor, final);
            retiraDadoPilha(aux);
        }
        return 0;
    }
    else
    { // se nao tiver o naipe de outra cor e um valor estar uma acima ele so coloca novamente na incial e retorna 1
        while (aux->topo != NULL)
        {
            colocaDadoPilha(aux->topo->c_Naipe, aux->topo->c_Valor, inicial);
            retiraDadoPilha(aux);
        }
        return 1;
    }
}

int separaCartas(Fila *f, Pilha *p, int qtd)
{
    // Pega a fila remove alguns elementos e joga para a pilha
    for (int i = 0; i < qtd; i++)
    {
        // Remove dado da fila e coloca ele na pilha
        Carta *retirada = retiraDaFila(f);
        colocaDadoPilha(retirada->c_Naipe, retirada->c_Valor, p);
    }
}

int main()
{
    srand(time(0));

    Pilha *cartas1 = inicializaPilha();
    Pilha *cartas2 = inicializaPilha();

    Fila *f = inicializaFila();
    f = embaralhaFila(f);
    separaCartas(f, cartas2, 8);
    separaCartas(f, cartas1, 8);

    imprimeFila(f);
}