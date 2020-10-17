struct elemento
{
   int itemType;
   struct elemento *prox;
};

// Redefinição do tipo struct elemento como Elem
typedef struct elemento Elem;

// Definição do tipo Pilha
typedef struct elemento *Pilha;


// Protótipo das funções essenciais
int Push(Pilha *pilha, int);
int Pop(Pilha *pilha);
int Top(Pilha *pilha);
int Size(Pilha *piha);
int SetSize(Pilha *pilha, int);
int IsFull(Pilha *pilha);
int IsEmpty(Pilha *pilha);
Pilha *CreateStack();
void DestroyStack(Pilha *pilha);

// Protótipo das funções extras
void Print(Pilha *pilha);
