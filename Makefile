CC=gcc
CFLAGS=-g -Wall
SRCDIR=./src/
BINDIR=./bin/

lista: $(SRCDIR)lista.c $(SRCDIR)lista.h
	$(CC) -c $(SRCDIR)lista.c $(CFLAGS) -o $(BINDIR)lista.o

grafo: $(SRCDIR)grafo.c $(SRCDIR)grafo.h
	$(CC) -c $(SRCDIR)grafo.c $(CFLAGS) -o $(BINDIR)grafo.o

all: lista grafo $(SRCDIR)main.c
	$(CC) -o tpmd $(BINDIR)grafo.o $(BINDIR)lista.o $(SRCDIR)main.c $(CFLAGS)

run: all 
	./tpmd ./entradas/e1

clean:
	rm -rf tpmd $(SRCDIR)*.o $(SRCDIR)*.mk $(SRCDIR)*.d $(SRCDIR)*.h.* $(SRCDIR)*.o.* 
