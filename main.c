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

int trasferenciaPP(Pilha *inicial, Pilha *final, int n)
{ // funcao que recebe a pilha incial e fina e quantas caratas serao transferidas
    Pilha *aux = inicializaPilha();

    for (int i = 0; i < n; i++)
    { // passa o numero de cartas para a aux
        if (inicial->topo->c_Naipe)
        {
            colocaDadoPilha(inicial->topo->c_Naipe, inicial->topo->c_Valor, aux);
            retiraDadoPilha(inicial);
        }
        else
        {
            return 1;
        }
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

int trasferenciaFP(Fila *f, Pilha *final)
{ // uma versao mais simples da funcao de transferencia de cima, nesse caso eh apenas checado se os valores batem, sem nenhuma auxiliar
    if ((f->inicio->c_Valor == final->topo->c_Valor - 1) && ((f->inicio->c_Naipe % 2 == 0 && final->topo->c_Naipe % 2 == 1) || (f->inicio->c_Naipe % 2 == 1 && final->topo->c_Naipe % 2 == 0)))
    {
        colocaDadoPilha(f->inicio->c_Naipe, f->inicio->c_Valor, final);
        retiraDaFila(f);
        return 0;
    }
    else
    {
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

void imprimeJogo(Pilha *p[], Fila *f)
{
    switch (f->inicio->c_Naipe)
    { // desse ponto ate o proximo comentario eh feito a impressao do inicio da fila
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
    if (f->inicio->c_Valor < Valete)
    {
        printf("%i", f->inicio->c_Valor + 2);
    }
    else
    {
        switch (f->inicio->c_Valor)
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
    } // desse ponto em diante eh feito a impressao das pilhas
    int x = 0, count = 0, j = 0;
    Carta *iterador;
    while (x != 7)
    { // a variavel x serve para checar se todas as pilhas ja foram impressas ate seu ultimo valor
        printf("\n");
        x = 0;
        for (int i = 0; i < 7; i++)
        { // percorre cada uma das pilhas
            iterador = p[i]->topo;
            while (j < count && iterador != NULL)
            { // o count se refere a ultima altura registrada
                iterador = iterador->prox;
                j++;
            }
            j = 0;
            if (iterador != NULL)
            { // apenas se o interador nao for null que o valor sera impresso
                printf(" ");
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
            }
            else
            { // senao sera impresso um espaco em branco em seu lugar
                printf("   ");
                x++; // e o contador de x ira aumentar, representando que mais uma pilha ja foi percorrida por completo
            }
        }
        count++; // aumenta em 1 a altura
    }
    printf("\n");
}

void rodarFila(Fila *f)
{ // funcao simples, coloca o valor do inicio da fila no final dela
    Carta *iterador;
    iterador = f->inicio;
    f->inicio = iterador->prox;
    f->fim = iterador;
}

int escolhaPilha(Pilha *p[], Fila *f) // funcao de jogabiblidade, recebe a fila e o array das pilhas de gameplay
{
    int inicial, final, valor;
    printf("Qual pilha deseja retirar (0 para acabar o jogo)\n (8 para selecionar a da fila) \n (9 para rodar a da fila): ");
    scanf("%d", &inicial);
    if (inicial == 0)
    { // se o jogador digitar 0, a funcao sai do loop na main
        return 1;
    }
    if (inicial == 9)
    { // se o jogador digitar 9, a funcao vai rodar o valor da fila
        rodarFila(f);
        imprimeJogo(p, f);
        return 0;
    }
    if (inicial == 8)
    { // se o jogador digitar 8, a funcao vai chamar a funcao de transferencia da fila-pilha FP
        printf("Qual pilha deseja colocar: ");
        scanf("%d", &final);
        if (trasferenciaFP(f, p[final - 1]) == 0)
        {
            printf("Jogada realizada\n");
        }
        else
        {
            printf("Jogada impossivel\n");
        }
        imprimeJogo(p, f);
        return 0;
    } // se o jogador digitar de 1 a 7, sera chamado a funcao de transferencia de pilha-pilha PP
    printf("Qual pilha deseja colocar: ");
    scanf("%d", &final);
    printf("Quantas cartas: ");
    scanf("%d", &valor);

    if (trasferenciaPP(p[inicial - 1], p[final - 1], valor) == 0)
    {
        printf("Jogada realizada\n");
    }
    else
    {
        printf("Jogada impossivel\n");
    }
    imprimeJogo(p, f);
    return 0;
}

int main()
{
    srand(time(0));
    Pilha *p1 = inicializaPilha(); // cria cada pilha de gameplay
    Pilha *p2 = inicializaPilha();
    Pilha *p3 = inicializaPilha();
    Pilha *p4 = inicializaPilha();
    Pilha *p5 = inicializaPilha();
    Pilha *p6 = inicializaPilha();
    Pilha *p7 = inicializaPilha();

    Pilha *p[7] = {p1, p2, p3, p4, p5, p6, p7}; // cria um arry com as pilhas de gameplay

    Fila *f = inicializaFila();
    f = embaralhaFila(f);
    for (int i = 0; i < 7; i++)
    {
        separaCartas(f, p[i], i + 1);
    }

    imprimeJogo(p, f);
    while (escolhaPilha(p, f) == 0)
    { // chama a funcao de jogabilidade em loop ate o jogador digitar 0 (dentro da funcao)
    }
}