SRC = src
INC = inc
OBJ = obj
DIST = dist
EXE = hello_world.exe
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))