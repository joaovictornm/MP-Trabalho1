CC		  = gcc
CFLAGS  = -I
INCLUDE = ./include
BIN	  = ./src/bin
OBJ     = ./src/obj
SRC 	  = ./src

din:
	echo "Pilha Dinâmica"
	$(CC) -c $(SRC)/pilhaDin.c $(CFLAGS) $(INCLUDE) -o $(OBJ)/PilhaDin.o
	$(CC) $(SRC)/testa_pilha.c $(OBJ)/*.o $(CFLAGS) $(INCLUDE) -o $(BIN)/Pilha

est:
	echo "Pilha Estática"
	$(CC) -c $(SRC)/pilhaEst.c $(CFLAGS) $(INCLUDE) -o $(OBJ)/PilhaEst.o
	$(CC) $(SRC)/testa_pilha.c $(OBJ)/*.o $(CFLAGS) $(INCLUDE) -o $(BIN)/Pilha

run:
	$(BIN)/Pilha

.PHONY: clean

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
