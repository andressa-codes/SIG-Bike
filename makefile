# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -g -Iinclude -MMD -MP

# Pastas
SRC_DIR = src
OBJ_DIR = obj

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Arquivos objeto
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Arquivos de dependência
DEPS = $(OBJS:.o=.d)

# Nome do executável
TARGET = sigbike

# Regra padrão
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar cada .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar pasta de objetos se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Incluir dependências
-include $(DEPS)

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Compilar e executar
run: all
	./$(TARGET)
