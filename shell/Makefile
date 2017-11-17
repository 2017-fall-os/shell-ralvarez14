
run: shell.o Methods.o
	cc shell.o Methods.o -o run
	
shell.o: shell.c
	cc -c -g shell.c

Methods.o: Methods.c
	cc -c  -g Methods.c

clean:
	rm -f *.o out
