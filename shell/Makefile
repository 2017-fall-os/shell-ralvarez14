
exeSh: myShell.o sysCalls.o Commands.o
	cc myShell.o sysCalls.o Commands.o -o exeSh
	
myShell.o: myShell.c
	cc -c -g myShell.c

Commands.o: Commands.c
	cc -c -g Commands.c

sysCalls.o: sysCalls.c
	cc -c -g sysCalls.c

clean:
	rm -f *.o out
