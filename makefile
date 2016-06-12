COMPILADOR = @gcc
PARAMETROS = -c -Wall -Iinclude

BIBLIOTECAS = -lm

FONTES = $(shell find . -name '*.c')
OBJETOS = $(FONTES:.c=.o)
EXECUTAVEL = hello.out

all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	$(COMPILADOR) $(BIBLIOTECAS) $^ -o $@

.c.o:
	$(COMPILADOR) $(PARAMETROS) $^ -o $@

clean:
	@rm $(OBJETOS) $(EXECUTAVEL)
