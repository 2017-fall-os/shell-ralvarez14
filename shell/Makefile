 
run: shell.o tokenizer.o Methods.o
	cc shell.o tokenizer.o Methods.o -o run

shell.o: shell.c
	cc -c shell.c

tokenizer.o: tokenizer.c
	cc -c tokenizer.c

Methods.o: Methods.c
	cc -c Methods.c

clean:
	rm -f *.o out
