CC		  = gcc
CFLAGS  = -I
INCLUDE = ./include
BIN	  = ./src/bin
OBJ     = ./src/obj
SRC 	  = ./src

# make din para compilar e utiliza a Pilha Dinâmica
din:
	echo "Pilha Dinâmica"
	$(CC) -c $(SRC)/pilhaDin.c $(CFLAGS) $(INCLUDE) -o $(OBJ)/PilhaDin.o
	$(CC) $(SRC)/testa_pilha.c $(OBJ)/*.o $(CFLAGS) $(INCLUDE) -o $(BIN)/Pilha

# make din para compilar e utiliza a Pilha Estática
est:
	echo "Pilha Estática"
	$(CC) -c $(SRC)/pilhaEst.c $(CFLAGS) $(INCLUDE) -o $(OBJ)/PilhaEst.o
	$(CC) $(SRC)/testa_pilha.c $(OBJ)/*.o $(CFLAGS) $(INCLUDE) -o $(BIN)/Pilha

# make run para rodar o programa
run:
	$(BIN)/Pilha

.PHONY: clean

# make clean para remover os arquivos dados pela compilação
clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
