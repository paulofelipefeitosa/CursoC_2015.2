SRC = src
INC = inc
OBJ = obj
DIST = dist
EXE = questao_4.exe
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))