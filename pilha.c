#include <stdio.h>
#include <stdlib.h>
#include "pilha.h" // Inclui os Protótipos das minhas Funções

int Push(Pilha *pilha, int item)
{
   if (pilha == NULL)
      return 0;
   Elem *no;
   no = (Elem *)malloc(sizeof(Elem));
   if (no == NULL)
      return 0;
   no->itemType = item;
   no->prox = (*pilha);
   *pilha = no;
   return 1;
}

int Pop(Pilha *pilha)
{
   if (pilha == NULL)
      return 0;
   if ((*pilha) == NULL)
      return 0;
   Elem *no = *pilha;
   *pilha = no->prox;
   free(no);
   return 1;
}

int Top(Pilha *pilha)
{
   if (pilha == NULL)
      return 0;
   if ((*pilha) == NULL)
      return 0;
   return (*pilha)->itemType;
}

int Size(Pilha *pilha)
{
   if (pilha == NULL)
      return 0;
   int cont = 0;
   Elem *no = *pilha;
   while (no != NULL)
   {
      cont++;
      no = no->prox;
   }
   return cont;
}

int SetSize(Pilha *pilha, int tamanho)
{
   int size = Size(pilha);

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
         Push(pilha, 2);
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
   return 0;
}

int IsEmpty(Pilha *pilha)
{
   if (pilha == NULL)
      return 1;
   if (*pilha == NULL)
      return 1;
   return 0;
}

Pilha *CreateStack()
{
   Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
   if (pilha != NULL)
      *pilha = NULL;
   return pilha;
}

void DestroyStack(Pilha *pilha)
{
   if (pilha != NULL)
   {
      Elem *no;
      while ((*pilha) != NULL)
      {
         no = *pilha;
         *pilha = (*pilha)->prox;
         free(no);
      }
      free(pilha);
   }
}

void Print(Pilha *pilha)
{
   if (pilha == NULL)
      return;
   Elem *no = *pilha;
   while (no != NULL)
   {
      printf("Dado: %d\n", no->itemType);
      no = no->prox;
   }
}
