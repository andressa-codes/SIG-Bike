# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -std=c11 -Wall -Wextra -g -Iinclude -MMD -MP

# Pastas
SRC_DIR = src
OBJ_DIR = obj
DADOS_DIR = dados

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

# Como gerar o executável (certifica-se que pasta dados existe)
$(TARGET): $(OBJS) | $(DADOS_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar cada .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar pasta de objetos se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Criar pasta dados se não existir
$(DADOS_DIR):
	mkdir -p $(DADOS_DIR)

# Incluir dependências
-include $(DEPS)

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Preparar ambiente (cria pastas necessárias)
setup: $(DADOS_DIR) $(OBJ_DIR)
	@echo "Pastas preparadas: $(DADOS_DIR), $(OBJ_DIR)"

# Compilar e executar (garante setup)
run: setup all
	./$(TARGET)

.PHONY: all clean run setup
