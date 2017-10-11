 
run: shell.o tokenizer.o Methods.o
	cc shell.o tokenizer.o Methods.o -o run

shell.o: shell.c
	cc -c -g shell.c

tokenizer.o: tokenizer.c
	cc -c -g tokenizer.c

Methods.o: Methods.c
	cc -c  -g Methods.c

clean:
	rm -f *.o out
