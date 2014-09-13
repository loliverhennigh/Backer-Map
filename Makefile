

backer: backer.o 
	gcc $(CFLAGS) -o backer.o 

backer.o: backer.c
	gcc $(CFLAGS) -c backer.c

clean:
	rm -f *.o backer
