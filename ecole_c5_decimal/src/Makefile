CC = gcc
CFLAGS = 

# --- Название библиотеки ---
LIB_NAME = my_decimal

LIB_STATIC = $(LIB_NAME).a
LIB_STATIC_GCOV = $(LIB_NAME)_gcov.a

# --- Пути ---
OBJ_DIR = obj
TESTS_OBJ_DIR = obj/tests
GCOV_OBJ_DIR = obj/gcov
REPORT_DIR = report

# --- Источники (структура из верхнего makefile) ---
# Основные исходники библиотеки
LIB_SRC = $(wildcard int/*.c) \
          $(wildcard helper/*.c) \
          $(wildcard decimal/*.c) \
          $(wildcard converter/*.c) \
          $(wildcard other/*.c) \
          $(wildcard compare/*.c) \
	  $(wildcard dec_u64/*.c) \
	  $(wildcard arithmetic_operators/*.c)

# Превращаем .c в .o (убираем путь к файлу, оставляем только имя для папки obj)
LIB_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(LIB_SRC:.c=.o)))
LIB_GCOV_OBJS = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(LIB_SRC:.c=.o)))

# Тесты (рекурсивный поиск)
TEST_EXE = test_build
TEST_DIR = tests
ALL_TESTS_DIRS = $(shell find $(TEST_DIR) -type d)
ALL_TESTS_C = $(notdir $(shell find $(ALL_TESTS_DIRS) -maxdepth 1 -name "*.c"))
ALL_TESTS_OBJS = $(addprefix $(TESTS_OBJ_DIR)/, $(notdir $(ALL_TESTS_C:%.c=%.o)))

# Dev (для твоей отладки temp.c)
DEV_SRC = $(wildcard dev/*.c)
DEV_OBJS = $(DEV_SRC:.c=.o)

# --- Настройка VPATH ---
# Чтобы make видел исходники в подпапках
vpath %.c $(dir $(LIB_SRC)) $(ALL_TESTS_DIRS)

# --- Определение ОС и флагов (из нижнего makefile) ---
ifeq ($(OS), Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

# Дефолтная команда открытия отчета
CMD_OPEN = open 

ifeq ($(UNAME_S), Darwin)
    # macOS
    CHECK_CFLAGS =
    CHECK_LIBS = -lcheck
    LINKER_FLAGS =
    LINK_STRING = $(LIB_NAME).a
else
    # Linux (Debian, Arch и т.д.)
    CHECK_CFLAGS = -pthread
    CHECK_LIBS = -lcheck
    LINKER_FLAGS = -lm
    LINK_STRING = -l:$(LIB_NAME).a
    # Проверяем наличие subunit
    ifneq ($(shell ldconfig -p 2>/dev/null | grep libsubunit | head -n1),)
        CHECK_LIBS += -lsubunit
    endif
endif 

# Флаги для покрытия кода
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# --- Режимы сборки (MODE) ---
# make test MODE=2 (Sanitize)
MODE=3 (Debug for Valgrind)

MODE?=1
ifeq ($(MODE), 2)
    CFLAGS += -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover
    LDFLAGS += -fsanitize=address -fsanitize=undefined
else 
    ifeq ($(MODE), 3)
        CFLAGS += -g
    endif
endif

# --- Targets ---

.PHONY: all clean test dev gcov_report rebuild clang valgrind

all: $(LIB_STATIC)

# 1. Сборка статической библиотеки
$(LIB_STATIC): $(OBJ_DIR) $(LIB_OBJS)
	@ar rcs $@ $(LIB_OBJS)

# 2. Сборка библиотеки для покрытия (с флагами gcov)
$(LIB_STATIC_GCOV): $(GCOV_OBJ_DIR) $(LIB_GCOV_OBJS)
	ar rcs $@ $(LIB_GCOV_OBJS)

# 3. Тесты
test: $(TESTS_OBJ_DIR) $(LIB_STATIC) $(ALL_TESTS_OBJS)
	$(CC) $(CFLAGS) $(ALL_TESTS_OBJS) $(LIB_STATIC) $(CHECK_LIBS) $(LDFLAGS) $(LINKER_FLAGS) -o $(TEST_EXE)
	@./$(TEST_EXE)

# 4. Отчет о покрытии (gcov/lcov)
gcov_report: $(TESTS_OBJ_DIR) $(LIB_STATIC_GCOV) $(ALL_TESTS_OBJS)
	$(CC) $(CFLAGS) $(ALL_TESTS_OBJS) $(LIB_STATIC_GCOV) $(CHECK_LIBS) $(LDFLAGS) $(GCOV_FLAGS) $(LINKER_FLAGS) -o $(TEST_EXE)
	-@./$(TEST_EXE)
	# @lcov -t "my_decimal" -o coverage.info -c -d $(GCOV_OBJ_DIR) --no-external --ignore-errors gcov
	@lcov --ignore-errors empty -t "my_decimal" -o coverage.info -c -d $(GCOV_OBJ_DIR)
	@genhtml -o $(REPORT_DIR) coverage.info
	@$(CMD_OPEN) $(REPORT_DIR)/index.html

# 5. Твоя dev сборка (temp.c)
dev: CFLAGS += -g
dev: rebuild dev_build

dev_build: $(DEV_OBJS) $(LIB_STATIC) temp.c
	$(CC) $(CFLAGS) -o dev_build temp.c $(DEV_OBJS) $(LIB_STATIC) $(CHECK_LIBS) $(LINKER_FLAGS) -g

# --- Компиляция объектов ---

# Обычные объекты библиотеки
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Объекты библиотеки с GCOV флагами
$(GCOV_OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

# Объекты тестов
$(TESTS_OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# --- Создание папок ---
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(GCOV_OBJ_DIR):
	@mkdir -p $(GCOV_OBJ_DIR)

$(TESTS_OBJ_DIR):
	@mkdir -p $(TESTS_OBJ_DIR)

# --- Утилиты ---

clean:
	rm -rf $(OBJ_DIR) $(REPORT_DIR)
	rm -f $(LIB_STATIC) $(LIB_STATIC_GCOV) $(TEST_EXE) $(DEV_OBJS) dev_build
	rm -f */*.o *.o
	rm -f *.gcno *.gcda *.gcov coverage.info

rebuild: clean all

# Проверка стилей (если скрипты лежат в ../materials/linters/)
clang:
	clang-format -style=Google -n $(LIB_SRC) $(wildcard *.h)
	clang-format -style=Google -n $(ALL_TESTS_C)

valgrind: rebuild
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./$(TEST_EXE)
