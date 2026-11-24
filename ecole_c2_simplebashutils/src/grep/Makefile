# Makefile
# /src/Makefile

# ---------- Variables-----------
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: my_grep 

##compile all available c files to object files
#%.o : %.c
#     $(CC) $(CFLAGS) $< -o $@

## libraries
# assemble the library
libmy_grep.a: my_grep.o
	ar rcs $@ $^

libarg_parsing.a: arg_parsing.o
	ar rcs ../common/libarg_parsing.a ../common/arg_parsing.o

libmy_string.a: my_string.o
	ar rcs ../common/libmy_string.a ../common/my_string.o

#compile lib objects
my_grep.o: my_grep.c my_grep.h
	$(CC) $(CFLAGS) -c $< -o $@

my_string.o: ../common/my_string.c ../common/my_string.h
	$(CC) $(CFLAGS) -I ../common -c ../common/my_string.c -o ../common/my_string.o

arg_parsing.o: ../common/arg_parsing.c ../common/arg_parsing.h
	$(CC) $(CFLAGS) -I ../common -c ../common/arg_parsing.c -o ../common/arg_parsing.o

# compile main object
main.o : main.c my_grep.h ../common/arg_parsing.h ../common/my_string.h
	$(CC) $(CFLAGS) -I ../common -c main.c -o main.o

#link executable with lib
my_grep: main.o libmy_grep.a libarg_parsing.a libmy_string.a
	$(CC) $(CFLAGS) -o $@ main.o libmy_grep.a ../common/libarg_parsing.a ../common/libmy_string.a

# "clean" target tells make utility to clean all of the objects files and executables
clean:
	rm -rf *.a *.o ../common/*.a ../common/*.o my_grep

rebuild: clean all

.PHONY: all my_grep clean rebuild
