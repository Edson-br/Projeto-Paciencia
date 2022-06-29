#include <stdio.h>
#include <stdlib.h>
#include "def.c"
#include "pilha.c"
#include <time.h>

int randomize(int lower, int upper)
{
  return (rand() %
          (upper - lower + 1)) +
         lower;
}

Carta *retiraDaFila(Fila *f)
{
  Carta *saida = f->inicio;
  Carta *retirado;
  retirado = (Carta *)malloc(sizeof(Carta));
  retirado = f->inicio;
  if (f->fim != f->inicio)
  {
    f->inicio = f->inicio->prox;
  }
  else
  {
    f->fim = f->inicio = NULL;
  }
  return saida;
}

Fila *cortaFila(Fila *f)
{

  Pilha *p = inicializaPilha();

  // Verifica se é para randomizar
  if (randomize(0, 52) > 21)
  {
    // Randomiza um valor de cartas para cortar da fila
    int valorCorta = randomize(0, 40);
    for (int i = 0; i < valorCorta; i++)
    {
      // Remove dado da fila e coloca ele na pilha
      Carta *retirada = retiraDaFila(f);
      colocaDadoPilha(retirada->c_Naipe, retirada->c_Valor, p);
    }
    // Coloca novamente o valor na fila
    for (int i = 0; i < valorCorta; i++)
    {
      Carta *retirada = retiraDadoPilha(p);
      colocaDadoFila(retirada->c_Naipe, retirada->c_Valor, f);
    }
  }

  return f;
}

Fila *embaralhaFila(Fila *f)
{
  for (int x = 0; x < 200; x++)
  {
    // Executa a função de cortar várias vezes
    f = cortaFila(f);
  }
  return f;
}
