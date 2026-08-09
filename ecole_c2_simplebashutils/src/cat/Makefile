# Makefile
# /src/Makefile

# ---------- Variables-----------
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: my_cat

##compile all available c files to object files
#%.o : %.c
#     $(CC) $(CFLAGS) $< -o $@

## libraries
#compile lib objects
my_cat.o: my_cat.c my_cat.h 
	$(CC) $(CFLAGS) -c $< -o $@

arg_parsing.o: ../common/arg_parsing.c ../common/arg_parsing.h
	$(CC) $(CFLAGS) -I ../common -c ../common/arg_parsing.c -o ../common/arg_parsing.o

my_string.o: ../common/my_string.c ../common/my_string.h
	$(CC) $(CFLAGS) -I ../common -c ../common/my_string.c -o ../common/my_string.o
# assemble the library
libmy_cat.a: my_cat.o
	ar rcs $@ $^

libarg_parsing.a: arg_parsing.o
	ar rcs ../common/libarg_parsing.a ../common/arg_parsing.o 

libmy_string.a: my_string.o
	ar rcs ../common/libmy_string.a ../common/my_string.o

# compile main object
main.o : main.c my_cat.h ../common/arg_parsing.h ../common/my_string.h
	$(CC) $(CFLAGS) -I ../common -c main.c -o main.o

#link executable with lib
my_cat: main.o libmy_cat.a libarg_parsing.a libmy_string.a
	$(CC) $(CFLAGS) -o $@ main.o libmy_cat.a ../common/libarg_parsing.a ../common/libmy_string.a

# "clean" target tells make utility to clean all of the objects files and executables
clean:
	rm -rf *.o *.a ../common/*.o ../common/*.a my_cat

rebuild: clean all

.PHONY: all my_cat clean rebuild
