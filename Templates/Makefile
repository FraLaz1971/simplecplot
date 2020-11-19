CC=gcc -g -O2
SRC = $(wildcard *.c)
OBJ = *.o *.obj
CPPFLAGS = -Iinclude
LDFLAGS = -Llib -lm
TARGET0 = insults
TARGET1 = integers
TARGETS = integers insults
all: $(TARGETS)
$(TARGET0).o: insults.c
	$(CC) -c   $< -o insults.o $(CPPFLAGS)
$(TARGET0): insults.o
	$(CC) -o insults $< $(LDFLAGS)
$(TARGET1).o: integers.c
	$(CC) -c   $< -o integers.o $(CPPFLAGS)
$(TARGET1): integers.o
	$(CC) -o integers $< $(LDFLAGS)
install: all
	mv $(TARGETS) bin
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGETS)
distclean: clean
	rm -f bin/* Makefile
