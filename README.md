# Rodando o Projeto

## Pré requisitos

Para executar o programa localmente, são necessárias as seguintes ferramentas:

- [GCC](https://gcc.gnu.org/) (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

## Instalação

### 1 - Baixe o repositório

git clone https://github.com/joaovictornm/MP-Trabalho1.git

### 2 - Entre na pasta do projeto

cd MP-Trabalho1

### 3 - Compile o programa utilizando Pilha Dinâmica

make din

### 4 - Execute o programa utilizando Pilha Dinâmica

make run

### 5 - Remova os arquivos gerados pela compilação

make clean

### 3 - Compile o programa utilizando Pilha Estática

make est

### 4 - Execute o programa utilizando Pilha Estática

make run

# Autor

- [João Magalhães](https://github.com/joaovictornm)

# O que foi desenvolvido

Foi desenvolvido dois módulos pilha em C, um implementando como um vetor e outra como uma lista encadeada.

As seguintes funções obrigatórias foram desenvolvidas:

- [Push (pilha, elemento)]() - coloca elemento no topo da pilha
- [Pop (pilha)]() - retira elemento do topo da pilha – retorna um elemento
- [Top (pilha)]() – retorna elemento do topo da pilha sem modificar a pilha – retorna um elemento
- [Size (pilha)]() – retorna int tamanho da pilha
- [SetSize (pilha, int)]() – muda o tamanho da pilha – retorna True se deu certo, False caso contrário
- [IsFull (pilha)]() – retorna verdadeiro se a pilha está cheia e falso caso contrário
- [IsEmpty (pilha)]() - retorna verdadeiro se a pilha está vazia e falso caso contrário
- [CreateStack ()]() – cria pilha – retorna pilha
- [DestroyStack (pilha)]() – destrói pilha

além da função extra:

- [Print (pilha)]() – imprime a pilha ordenada do topo a base


