#include <stdio.h>
#include <unistd.h>

int playerInput;
int *playerinputlocation = &playerInput;


char stringInput[11];


void onePlayer() {
    printf("Generating a word");
}

void singleGuesser() {
    printf("Welcome to single guesser, please input a length for your word(max length 10 characters)");
    scanf(" %d", playerinputlocation);
    playerInput++;
    printf("please input a word");
    switch (playerInput) {
    case 1:
        break;
    case 2:
        scanf("%2s", stringInput);
        break;
    case 3:
        scanf("%3s", stringInput);
        break;
    case 4:
        scanf("%4s", stringInput);
        break;
    case 5:
        scanf("%5s", stringInput);
        break;
    case 6:
        scanf("%6s", stringInput);
        break;
    case 7:
        scanf("%7s", stringInput);
        break;
    case 8:
        scanf("%8s", stringInput);
        break;
    case 9:
        scanf("%9s", stringInput);
        break;
    case 10:
        scanf("%10s", stringInput);
        break;
    }
    printf(" \033[2J");
}

void competetiveGuessing() {
    printf("Does not exist yet\n");
}

void twoPlayer() {
    printf("There are are two modes available, Single guesser or competetive guessing, Single guesser is where one person inputs a word and the other tries to guess it and \n competetive guessing is where both players select a word of the same length and both take turns guessing \n Which would you like to select? (Single guesser(1)/Competetive Guessing(2))\n");
    scanf(" %d", playerinputlocation);
    (playerInput == 1) ? singleGuesser() : competetiveGuessing();
}

int main() {
    // scanf("%4s", str);
    // printf("\n%s", str);

    printf("Welcome to hangman 2.0! Would you like to play one player or two player? (1/2)\n");
    scanf(" %d", playerinputlocation);

    // same as an if else but more efficent
    (playerInput == 1) ? onePlayer() : twoPlayer();
    return 0;
}