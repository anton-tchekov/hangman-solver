all: main.c
	gcc main.c -o hangman -O2 -Wall

clean:
	rm -f hangman
