CC = gcc
UNAME_S := $(shell uname -s)

# Базовые флаги
CFLAGS = -Wall -Werror -Wextra -std=c11
LIB_NAME = my_string
LIB_SRC = my_string.c
TEST_SRC = tests/*.c
OLD_TEST_SRC = old_tests/*.c
BUILD = tests.out
OLD_BUILD = old_tests.out


# Настройка флагов под платформу
ifeq ($(UNAME_S), Darwin)
    # macOS
    CHECK_CFLAGS =
    CHECK_LIBS = -lcheck
    LINKER_FLAGS =
    LINK_STRING = $(LIB_NAME).a
else
    # Linux (Debian, Arch и т.д.)
    CHECK_CFLAGS = -pthread
    CHECK_LIBS = -lcheck -lrt
    LINKER_FLAGS = -lm
    LINK_STRING = -l:$(LIB_NAME).a
    # Проверяем наличие subunit
    ifneq ($(shell ldconfig -p 2>/dev/null | grep libsubunit | head -n1),)
        CHECK_LIBS += -lsubunit
    endif
endif

.PHONY: all clean test old_test gcov_report old_gcov_report rebuild

all: $(LIB_NAME).a

$(LIB_NAME).a: $(LIB_NAME).o
	ar rcs $@ $^

$(LIB_NAME).o: $(LIB_SRC)
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(LIB_NAME).a $(BUILD)
	./$(BUILD)

old_test: $(LIB_NAME).a old_$(BUILD)
	./old_$(BUILD)

$(BUILD): $(LIB_NAME).a
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) $(TEST_SRC) -L. $(LINK_STRING) $(CHECK_LIBS) $(LINKER_FLAGS) -o $(BUILD)

old_$(BUILD): $(LIB_NAME).a
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) $(OLD_TEST_SRC) -L. $(LINK_STRING) $(CHECK_LIBS) $(LINKER_FLAGS) -o old_$(BUILD)

gcov_report: clean
	@$(MAKE) test CFLAGS="$(CFLAGS) --coverage"
	@find . -name "*.gcov" -delete
	@lcov -t "Report" -c -d . --output-file ./coverage.info
	@lcov --remove ./coverage.info "tests/*.c" --output-file ./coverage.info
	@genhtml ./coverage.info --output-directory report/

old_gcov_report: clean
	@$(MAKE) old_test CFLAGS="$(CFLAGS) --coverage"
	@find . -name "*.gcov" -delete
	@lcov -t "Report" -c -d . --output-file ./coverage.info
	@lcov --remove ./coverage.info "old_tests/*.c" --output-file ./coverage.info
	@genhtml ./coverage.info --output-directory report/

rebuild: clean all

clean:
	rm -f *.o $(LIB_NAME).a $(BUILD) $(OLD_BUILD) tests/*.o old_tests/*.o
	find . -name "*.gcno" -delete
	find . -name "*.gcov" -delete
	find . -name "*.gcda" -delete
	rm -f coverage.info
	rm -rf report/

