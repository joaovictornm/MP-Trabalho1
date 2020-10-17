#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
   int a[6] = {1, 2, 3, 4, 3, 2};
   Pilha *pilha = CreateStack();
   printf("Tamanho: %d\n", Size(pilha));
   int i;
   for (i = 0; i < 6; i++)
      Push(pilha, a[i]);

   Print(pilha);
   printf("Tamanho: %d\n", Size(pilha));

   for (i = 0; i < 6; i++)
      Pop(pilha);
   printf("Tamanho: %d\n", Size(pilha));
   Print(pilha);

   for (i = 0; i < 6; i++)
      Push(pilha, a[i]);

   printf("Tamanho: %d\n\n\n\n", Size(pilha));
   Print(pilha);

   printf("Top: %d\n\n\n\n", Top(pilha));

   printf("1 para se deu certo e 0 para não: %d\n", SetSize(pilha, 20));

   printf("Tamanho: %d\n", Size(pilha));

   Print(pilha);

   DestroyStack(pilha);
   //system("pause");
   return 0;
}
