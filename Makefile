# ========================
# Configurações básicas
# ========================
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -std=c11 -Iinclude -g
LDFLAGS :=

# ========================
# Diretórios
# ========================
SRC_DIR    := src
TEST_DIR   := tests
OBJ_DIR    := build/obj
BIN_DIR    := build/bin

# ========================
# Arquivos fonte
# ========================
SRC_FILES  := $(wildcard $(SRC_DIR)/*.c)
TEST_FILES := $(wildcard $(TEST_DIR)/test_*.c)

# ========================
# Objetos
# ========================
OBJ_FILES       := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES  := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_FILES))

# ========================
# Binários de teste
# ========================
TEST_BINS := $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TEST_FILES))

# ========================
# Alvos principais
# ========================
.PHONY: all test clean run dirs

all: dirs test

# ========================
# Criação de diretórios
# ========================
dirs:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# ========================
# Compilação dos .o
# ========================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ========================
# Linkagem dos testes
# ========================
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(OBJ_FILES)
	$(CC) $^ -o $@ $(LDFLAGS)

# ========================
# Executa todos os testes
# ========================
test: $(TEST_BINS)

run: test
	@for test in $(TEST_BINS); do \
		echo "==> Running $$test"; \
		$$test; \
	done

# ========================
# Limpeza
# ========================
clean:
	rm -rf build

