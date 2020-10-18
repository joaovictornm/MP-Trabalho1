#include <stdio.h>
#include <stdlib.h>
#include "pilha.h" // Inclui os Protótipos das minhas Funções

// Definição do tipo Pilha
struct elemento
{
    int qtd;
    ItemType dados[MAX];
};

// Minhas funções para manipular a Pilha Dinãmica
int Push(Pilha *pilha, ItemType item)
{
    if (pilha == NULL)
        return 0;
    if (pilha->qtd == MAX) // Pilha com o máximo de elementos possíveis
        return 0;

    pilha->dados[pilha->qtd] = item;
    pilha->qtd++;
    return 1;
}

int Pop(Pilha *pilha)
{
    if (pilha == NULL || pilha->qtd == 0)
        return 0;
    pilha->qtd--;
    return 1;
}

int Top(Pilha *pilha)
{
    if (pilha == NULL || pilha->qtd == 0)
        return 0;
    return pilha->dados[pilha->qtd - 1].inteiro;
}

int Size(Pilha *pilha)
{
    if (pilha == NULL)
        return 0;
    else
        return pilha->qtd;
}

int SetSize(Pilha *pilha, int tamanho)
{
    int size = pilha->qtd;

    if (size > tamanho)
    {
        while (size > tamanho)
        {
            Pop(pilha);
            size--;
        }
    }
    else if (size < tamanho)
    {
        while (size < tamanho)
        {
            ItemType temp = {2};
            Push(pilha, temp);
            size++;
        }
    }

    if (size == tamanho)
        return 1;
    else
        return 0;
}

int IsFull(Pilha *pilha)
{
    if (pilha == NULL)
        return -1;
    if (pilha->qtd < MAX)
        return 0;
    else
        return 1;
}


int IsEmpty(Pilha *pilha)
{
    if (pilha == NULL)
        return -1;
    if (pilha->qtd == 0)
        return 1;
    else
        return 0;
}

Pilha *CreateStack()
{
    Pilha *pilha;
    pilha = (Pilha *)malloc(sizeof(struct elemento));
    if (pilha != NULL)
        pilha->qtd = 0;
    return pilha;
}

void DestroyStack(Pilha *pilha)
{
    free(pilha);
}

void Print(Pilha *pilha)
{
    if (pilha == NULL)
        return;
    int i;
    for (i = pilha->qtd - 1; i >= 0; i--)
    {
        printf("Dado: %d\n", pilha->dados[i].inteiro);
    }
}
