# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -g -Iinclude

# Arquivos fonte dentro de src/
SRCS = src/main.c src/tela_inicial.c src/tela_principal.c src/modulos_info.c src/bicicletas.c src/clientes.c src/funcionarios.c src/vendas.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Nome do executável
TARGET = sigbike

# Regra padrão
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Como compilar cada .c em .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Compilar e executar
run: $(TARGET)
	./$(TARGET)
