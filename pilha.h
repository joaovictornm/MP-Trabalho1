#define MAX 100     // Tamanho máximo para a pilha estática

// Definição do tipo Pilha para Dinâmica ou Estática
#ifdef DINAMICA
   typedef struct elemento *Pilha;
#else
   typedef struct elemento Pilha;
#endif

// Definição do tipo ItemType
struct item
{
   int inteiro;
};

// Redefinição do tipo struct item como ItemType
typedef struct item ItemType;


// Protótipo das funções essenciais
int Push(Pilha *pilha, ItemType);
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
