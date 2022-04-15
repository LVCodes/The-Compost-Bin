permits: permits.o request.o readline.o
	gcc -Wall *.o -o permits

permits.o: permits.c request.c readline.c readline.h request.h
	gcc -Wall -c permits.c

request.o: request.c request.h
	gcc -Wall -c request.c

readline.o: readline.c readline.h
	gcc -Wall -c readline.c
