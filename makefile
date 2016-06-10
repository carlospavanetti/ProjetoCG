COMPILADOR = gcc
CFLAGS = -c -Wall

BIBLIOTECAS = -lm

FONTES = main.c contexto.c desenhar.c matriz.c
OBJETOS = $(FONTES:.c=.o)
EXECUTAVEL = hello.out

all: $(FONTES) $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	$(COMPILADOR) $(BIBLIOTECAS) $(OBJETOS) -o $@

.c.o:
	$(COMPILADOR) $(CFLAGS) $< -o $@
