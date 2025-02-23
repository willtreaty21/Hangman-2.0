all:
		gcc -o Hangman main.c
		./Hangman
clean:
		rm edit main.o