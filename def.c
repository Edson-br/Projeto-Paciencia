typedef enum naipe
{
  Paus,
  Copas,
  Espadas,
  Ouros
} Naipe;

typedef enum valor
{
  Dois,
  Tres,
  Quatro,
  Cinco,
  Seis,
  Sete,
  Oito,
  Nove,
  Dez,
  Valete,
  Dama,
  Rei,
  As
} Valor;

typedef struct carta
{
  struct carta *prox;
  Naipe c_Naipe;
  Valor c_Valor;
} Carta;

typedef struct fila
{
  Carta *inicio;
  Carta *fim;
} Fila;

void colocaDadoFila(int naipe, int valor, Fila *f)
{
  Carta *novoDado;
  novoDado = (Carta *)malloc(sizeof(Carta));
  novoDado->c_Naipe = naipe;
  novoDado->c_Valor = valor;
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
