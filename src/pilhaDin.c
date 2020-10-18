// "Copyright 2020 João Magalhães"

#define DINAMICA
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h" // Inclui os Protótipos das minhas Funções

//Definição do tipo Pilha contendo o ItemType dado que facilmente ser alterado
struct elemento
{
  ItemType dado;
  struct elemento *prox;
};

// Redefinição do tipo struct elemento como Elem
typedef struct elemento Elem;

// Minhas funções para manipular a Pilha Dinãmica
int Push(Pilha *pilha, ItemType item) {
  if (pilha == NULL)    // Se a pilha for igual a NULL, não existe uma pilha, então não é possível inserir um elemento
    return 0;
  Elem *no;             // Aloca um novo elemento para entrar na pilha
  no = (Elem *)malloc(sizeof(Elem));
  if (no == NULL)       // Caso ocorra algum problema na alocação, retorna 0
    return 0;
  no->dado = item;      // Caso tenha dado tudo certo, o dado desse elemento é igual ao que foi passado como parâmetro
  no->prox = (*pilha);  // Coloca ele no topo, ou seja, ele aponta para o elemento que estava no topo antes
  *pilha = no;          // A pilha passa a apontar para ele, pois ele é o primeiro elemento
  return 1;
}

int Pop(Pilha *pilha) {
  if (pilha == NULL)    // Se a pilha for igual a NULL, não existe uma pilha, então não é possível remover um elemento
    return 0;
  if ((*pilha) == NULL) // Se o elemento para o qual a pilha apontar for NULL, existe uma pilha que está vazia, sendo assim, não é possível remover um elemento
    return 0;
  Elem *no = *pilha;    // Desaloca o elemento que estava no topo, e a pilha passa a apontar pro seugndo elemento que passa a estar no topo
  *pilha = no->prox;
  free(no);
  return 1;
}

int Top(Pilha *pilha) {
  if (pilha == NULL)    // Se a pilha for igual a NULL, não existe uma pilha, então não é possível retornar um dado
    return 0;
  if ((*pilha) == NULL) // Se o elemento para o qual a pilha apontar for NULL, existe uma pilha que está vazia, sendo assim, não é possível retornar um dado
    return 0;
  return (*pilha)->dado.inteiro;  // Retorna o dado que se chama inteiro
}

int Size(Pilha *pilha) {
  if (pilha == NULL)    // Se a pilha for igual a NULL, não existe uma pilha, então não é possível retornar um dado
    return 0;
  int cont = 0;         // Declara um contador
  Elem *no = *pilha;
  while (no != NULL)    // Enquanto o próximo elemento não for NULL, continua passando pela lista somando 1 a cada elemento
  {
    cont++;
    no = no->prox;
  }
  return cont;          // Retorna o valor encontrado
}

int SetSize(Pilha *pilha, int tamanho) {
  int size = Size(pilha);   // Captura o tamanho da pilha

  if (size > tamanho)
  {
    while (size > tamanho)  // Enquanto o tamanho da pilha for maior que o tamanho que se quer
    {
      Pop(pilha);           // Remove um elemento do topo
      size--;
    }
  }
  else if (size < tamanho)  // Enquanto o tamanho da pilha for menor que o tamanho que se quer
  {
    while (size < tamanho)
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
  return 0;                 // Como a pilha é dinâmica, o seu limite é igual ao tamanho da memória do computador
}

int IsEmpty(Pilha *pilha) {
  if (pilha == NULL)        // Se a pilha for igual a NULL, não existe uma pilha, então ela está vazia
    return 1;
  if (*pilha == NULL)       // Se o elemento para o qual a pilha apontar for NULL, existe uma pilha que está vazia
    return 1;
  return 0;                 // Se nenhum dos casos acima forem satisfeitos, retorna 0 informando que ela não está vazia
}

Pilha *CreateStack() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));  // Aloca um elemento do tipo Pilha
  if (pilha != NULL)                              // Se a alocação tiver ocorrido corretamente, pilha aponta para NULL pois inicia vazia
    *pilha = NULL;
  return pilha;
}

void DestroyStack(Pilha *pilha) {
  if (pilha != NULL)              // Se a pilha for igual a NULL, não existe uma pilha, não há o que fazer
  {
    Elem *no;
    while ((*pilha) != NULL)      // Percorre a pilha desalocando os elemento desde o topo até a base
    {
      no = *pilha;
      *pilha = (*pilha)->prox;
      free(no);
    }
    free(pilha);                  // Desaloca a pilha
  }
}

void Print(Pilha *pilha) {
  if (pilha == NULL)              // Se a pilha for igual a NULL, não existe uma pilha, não há o que imprimir
    return;
  Elem *no = *pilha;
  while (no != NULL)              // Percore a pilha imprimindo o dado do elemento desde o topo até a base
  {
    printf("Dado: %d\n", no->dado.inteiro);
    no = no->prox;
  }
}
