// "Copyright 2020 João Magalhães"

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h" // Inclui os Protótipos das minhas Funções

// Definição do tipo Pilha contendo o ItemType dado que facilmente ser alterado
struct elemento {
  int qtd;
  ItemType dados[MAX];
};

// Minhas funções para manipular a Pilha Estática
int Push(Pilha *pilha, ItemType item) {
  if (pilha == NULL)     // Se a pilha for igual a NULL, não existe uma pilha
    return 0;
  if (pilha->qtd == MAX) // Pilha com o máximo de elementos possíveis, não é possível adicionar mais
    return 0;

  pilha->dados[pilha->qtd] = item;  // Adiciona um elemento no final do vetor, que é considerado o topo da pilha
  pilha->qtd++;                     // Incrementa a quantidade
  return 1;
}

int Pop(Pilha *pilha) {
  if (pilha == NULL || pilha->qtd == 0)   // Se a pilha for igual a NULL ou não tiver elementos, não há o que fazer
    return 0;
  pilha->qtd--;   // Diminui a quantidade, assim, desconsiderando aquele elemento
  return 1;
}

int Top(Pilha *pilha) {
  if (pilha == NULL || pilha->qtd == 0)   // Se a pilha for igual a NULL ou não tiver elementos, não há o que fazer
    return 0;
  return pilha->dados[pilha->qtd - 1].inteiro;  // Retorna o dado do último elemento do vetor, que é considerado o topo da pilha
}

int Size(Pilha *pilha) {
  if (pilha == NULL)    // Se a pilha for igual a NULL, não existe uma pilha, ou seja, tamanho 0
    return 0;
  else
    return pilha->qtd;  // Retorna qtd com a quantidade de elementos que se tem na pilha
}

int SetSize(Pilha *pilha, int tamanho) {
  int size = pilha->qtd;  // Captura o tamanho da pilha

  if (size > tamanho)
  {
    while (size > tamanho)  // Enquanto o tamanho da pilha for maior que o tamanho que se quer
    {
      Pop(pilha);           // Remove um elemento do topo, que no fim das contas é decrementar qtd
      size--;
    }
  }
  else if (size < tamanho)
  {
    while (size < tamanho)  // Enquanto o tamanho da pilha for menor que o tamanho que se quer
    {
      ItemType temp = {2};
      Push(pilha, temp);    // Insere um elemento no topo cujo dado é igual a 2
      size++;
    }
  }

  if (size == tamanho)      // Se o tamanho da pilha for igual ao tamanho que se quer, retorna 1 confirmando que deu certo
    return 1;
  else
    return 0;               // Ou 0 para informar que não deu certo
}

int IsFull(Pilha *pilha) {
  if (pilha == NULL)        // Se a pilha for igual a NULL, não se tem uma pilha, então não há o que verificar
    return -1;
  if (pilha->qtd < MAX)     // Se a quantidade de elementos na pilha for igual a MAX, ela está cheia
    return 0;
  else
    return 1;
}

int IsEmpty(Pilha *pilha) {
  if (pilha == NULL)        // Se a pilha for igual a NULL, não se tem uma pilha, então não há o que verificar
    return -1;
  if (pilha->qtd == 0)      // Se a quantidade de elementos na pilha for igual a 0, ela está vazia
    return 1;
  else
    return 0;
}

Pilha *CreateStack() {
  Pilha *pilha;             // Aloca um elemento do tipo pilha
  pilha = (Pilha *)malloc(sizeof(struct elemento));
  if (pilha != NULL)        // Se a alocação tiver ocorrido corretamente, qtd é igual a 0 pois inicia vazia
    pilha->qtd = 0;
  return pilha;
}

void DestroyStack(Pilha *pilha) {
  free(pilha);    // Desaloca a pilha
}

void Print(Pilha *pilha) {
  if (pilha == NULL)    // Se a pilha for igual a NULL, não existe uma pilha, não há o que imprimir
    return;
  int i;
  for (i = pilha->qtd - 1; i >= 0; i--)   // Percore a pilha imprimindo o dado do elemento desde o topo até a base
  {
    printf("Dado: %d\n", pilha->dados[i].inteiro);
  }
}
