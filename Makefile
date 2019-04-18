CC=g++
IDIR = ../include
ODIR=src
LDIR= ./
CFLAGS= -lgtest -lpthread -I$(IDIR) -I$(LDIR)
LIBS= -std=c++11 -stdlib=libc++

_DEPS = romano.h
DEPS = $(patsubst %,$(LDIR)/%,$(_DEPS))

_OBJ = romano.cpp testa_romano.cpp 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romano: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) 

all: run

run: romano
	$(LDIR)romano

clean:
	rm -f $(LDIR)romano
.PHONY: all run