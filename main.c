#include <stdio.h>
#include <unistd.h>

int playerInput; // a number the player inputs
int* playerinputlocation = &playerInput; // used to get the input from scanf
int wordlen; // length of the word the player guesses
int* wordlenloc = &wordlen; // 
int guessesWrong = 0;
int guessesWrong2 = 0;
int missed = 0;
int lettersCorrect;

char letterInput;
char letterInputLocation;
char stringInput[11];
char stringInput2[11];
char guessed[20];
char guessed2[20];
char incorrectGuesses[8];
char incorrectGuesses2[8];
char guessedLetter;


void printHangman(int guess) {
    switch (guess) {
        case 0:
            printf("_________\n");
            printf("|        \n");
            printf("|        \n");
            printf("|        \n");
            printf("|        \n");
            break;
        case 1:
            printf("_________\n");
            printf("|     |  \n");
            printf("|        \n");
            printf("|        \n");
            printf("|        \n");
            break;
        case 2:
            printf("_________\n");
            printf("|     |  \n");
            printf("|     o  \n");
            printf("|        \n");
            printf("|        \n");
            break;
        case 3:
            printf("_________\n");
            printf("|     |  \n");
            printf("|     o  \n");
            printf("|     |  \n");
            printf("|        \n");
            break;
        case 4:
            printf("_________\n");
            printf("|     |  \n");
            printf("|     o  \n");
            printf("|    /|  \n");
            printf("|        \n");
            break;
        case 5:
            printf("_________\n");
            printf("|     |  \n");
            printf("|     o  \n");
            printf("|    /|\\\n");
            printf("|        \n");
            break;
        case 6:
            printf("_________\n");
            printf("|     |  \n");
            printf("|     o  \n");
            printf("|    /|\\\n");
            printf("|    /   \n");
            break;
        case 7:
            printf("_________\n");
            printf("|     |  \n");
            printf("|     o  \n");
            printf("|    /|\\\n");
            printf("|    / \\\n");
            break;
    }
}

void makeGuess() {
    printf("\033[2J\n");
    printHangman(guessesWrong);
    // print out wrong guesses
    printf("you have guessed \033[1;31m%d\033[0;37m letters wrong, those letters were: \033[1;31m", guessesWrong);

    for (int i = 0; i< guessesWrong; i++) {
        printf("\033[1;31m%c\033[0;37m, ", incorrectGuesses[i]);
    }
    printf("\033[0;37m\nYou have currently guessed %s\nPlease input your guess\n", guessed);
    scanf(" %c", &guessedLetter);

    missed = 0;
    for (int i = 0; i<wordlen; i++){
        (stringInput[i] == guessedLetter) ? guessed[i]=guessedLetter: missed++;
    }
    if (missed == wordlen){
        guessesWrong++;
        incorrectGuesses[guessesWrong - 1] = guessedLetter;
    }
}

void makeGuess2() {
    printf("\033[2J\n");
    printHangman(guessesWrong2);
    // print out wrong guesses
    printf("you have guessed \033[1;31m%d\033[0;37m letters wrong, those letters were: \033[1;31m", guessesWrong2);

    for (int i = 0; i< guessesWrong2; i++) {
        printf("\033[1;31m%c\033[0;37m, ", incorrectGuesses2[i]);
    }
    printf("\033[0;37m\nYou have currently guessed %s\nPlease input your guess\n", guessed2);
    scanf(" %c", &guessedLetter);

    missed = 0;
    for (int i = 0; i<wordlen; i++){
        (stringInput2[i] == guessedLetter) ? guessed2[i]=guessedLetter: missed++;
    }
    if (missed == wordlen){
        guessesWrong2++;
        incorrectGuesses[guessesWrong2 - 1] = guessedLetter;
    }
}

void onePlayer() {
    printf("Generating a word\n");
}

int singleGuesser() {
    printf("Welcome to single guesser, please input a length for your word(max length 10 characters)\n");
    scanf(" %d", wordlenloc);
    wordlen++; // add one in lenth to add the end character 
    printf("please input a word\n");
    // read the input
    switch (wordlen) {
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
    
    // prep the empty string to hold the guessed letters
    wordlen --; //remove the end character calculations
    for (int i = 0; i < wordlen; i++) {
        guessed[i] = '-';
    }
    // output the word length and let the player make a guess
    
    printf("\033[2JThe word is %d letters long. Press any letter then enter to continue\n", wordlen);
    scanf(" %c",playerinputlocation);


    while (1) {
        makeGuess();
        // check if they lose
        if (guessesWrong >= 7) {
            printf("\033[2J\n");
            printHangman(guessesWrong);
            printf("\033[1;5;31mGAME OVER\n\033[37;0mYou guessed: \033[1;31m%s\033[37;0m, the full word was: \033[0;32m%s\n", guessed, stringInput);
            return 0;
        }
        // count the correct letters
        lettersCorrect = 0;
        for(int i = 0; i< wordlen; i++) {
            if (guessed[i] == stringInput[i]) {
                lettersCorrect ++;
            }
        }
        // check if the letters correct match the length of the word if so end the game
        if (lettersCorrect == wordlen){
            printf("\033[2J\n");
            printHangman(guessesWrong);
            printf("\033[1;32mYOU WIN\n\033[37;0mThe final answer was: \033[0;32m%s\n", stringInput);
            return 0;
        }
    }
}

void competetiveGuessing() {
    printf("Welcome to competetive guessing, decide on than input a word length\n");
    scanf(" %d", wordlenloc);
    printf("\033[2JYour word will be %d letters long. Player 1 input a word that is %d letters long\n", wordlen, wordlen);
    switch (wordlen) {
        case 1:
            scanf("%1s", stringInput2);
            break;
        case 2:
            scanf("%2s", stringInput2);
            break;
        case 3:
            scanf("%3s", stringInput2);
            break;
        case 4:
            scanf("%4s", stringInput2);
            break;
        case 5:
            scanf("%5s", stringInput2);
            break;
        case 6:
            scanf("%6s", stringInput2);
            break;
        case 7:
            scanf("%7s", stringInput2);
            break;
        case 8:
            scanf("%8s", stringInput2);
            break;
        case 9:
            scanf("%9s", stringInput2);
            break;
        case 10:
            scanf("%10s", stringInput2);
            break;
    }

    // prep the word with -'s for guessing
    for (int i = 0; i < wordlen; i++) {
        guessed[i] = '-';
    }

    //clear the screen then take player two's input
    printf("\033[2JYour word will be %d letters long. Player 2 input a word that is %d letters long\n", wordlen, wordlen);
    switch (wordlen) {
        case 1:
            scanf("%1s", stringInput);
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
    
    // prep player 2's word with -'s for guessing
    for (int i = 0; i < wordlen; i++) {
        guessed2[i] = '-';
    }

    // function loop
    while (1){
        // have player 1 guess
        makeGuess();
        // have player 2 guess
        makeGuess2();

        // check endgame conditions for both players
        if (guessesWrong >= 7) { // if player 1 loses
            printf("\033[2J\n");
            printHangman(guessesWrong);
            printf("\033[1;5;31mGAME OVER\n\033[37;0mYou guessed: \033[1;31m%s\033[37;0m, the full word was: \033[0;32m%s\n", guessed, stringInput);
            return 0;
        }
        if (guessesWrong2 >= 7) { // if player 2 loses
            printf("\033[2J\n");
            printHangman(guessesWrong);
            printf("\033[1;5;31mGAME OVER\n\033[37;0mYou guessed: \033[1;31m%s\033[37;0m, the full word was: \033[0;32m%s\n", guessed, stringInput);
            return 0;
        }
    }
    
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