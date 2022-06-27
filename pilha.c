#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
  Carta *topo;
} Pilha;

Pilha *inicializaPilha()
{
  Pilha *p;
  p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}

void colocaDadoPilha(Naipe naipe, Valor valor, Pilha *p)
{
  Carta *novoDado;
  novoDado = (Carta *)malloc(sizeof(Carta));
  novoDado->c_Naipe = naipe;
  novoDado->c_Valor = valor;
  novoDado->prox = p->topo;
  p->topo = novoDado;
}

Carta *retiraDadoPilha(Pilha *p)
{
  if (p != NULL || p->topo != NULL)
  {
    Carta *saida = p->topo;
    Carta *aux = p->topo;
    p->topo = p->topo->prox;
    aux = NULL;
    return saida;
  }
}

void imprimePilha(Pilha *p)
{
  Carta *iterador;
  iterador = p->topo;
  while (iterador != NULL)
  {
    printf("%i - %i", iterador->c_Naipe, iterador->c_Valor);
    iterador = iterador->prox;
  }
  printf("\n");
}