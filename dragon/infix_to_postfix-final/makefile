CC=clang
FLAGS=

all:  myapp

debug: FLAGS += -g
debug: myapp

%.o: %.c %.h
	$(CC) $(FLAGS) -c $^

myapp: symbol.o init.o error.o lexer.o parser.o emitter.o main.c
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm *.o main
 
