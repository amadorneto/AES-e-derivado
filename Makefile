all:
	gcc -g -o A2ES.out main.c aesToolBox.c a2esToolBox.c

clean:
	rm A2ES.out

run:
	./A2ES.out
