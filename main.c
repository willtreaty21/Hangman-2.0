#include <stdio.h>
#include <unistd.h>

int playerInput; // a number the player inputs
int* playerinputlocation = &playerInput; // used to get the input from scanf
int wordlen; // length of the word the player guesses
int* wordlenloc = &wordlen; // 
int guessesWrong = 0; // guesses wrong for player 1
int missed = 0;
int lettersCorrect;

char letterInput;
char letterInputLocation;
char stringInput[11];
char guessed[20];
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
    printHangman(guessesWrong);
    // print out wrong guesses
    printf("you have guessed \033[1;31m%d\033[0;37m letters wrong, those letters were: \033[1;31m", guessesWrong);

    for (int i = 0; i< guessesWrong; i++) {
        printf("\033[1;31m%c\033[0;37m, ", incorrectGuesses[i]);
    }
    printf("\033[0;37m\nYou have currently guessed %s\nPlease input your guess\n", guessed);
    scanf(" %c", &guessedLetter); // take new input
    
    // run through each letter of the word and check if it equals the guessed letter
    missed = 0;
    for (int i = 0; i<wordlen; i++){
        (stringInput[i] == guessedLetter) ? guessed[i]=guessedLetter: missed++;
    }
    if (missed == wordlen){
        guessesWrong++;
        incorrectGuesses[guessesWrong - 1] = guessedLetter;
    }
}

void twoPlayerGuess(char player2sWordToGuess[11], char player1sWordToGuess[11], char player1sGuessed[11], char player2sGuessed[11], int player1Guesseswrong, int player2Guesseswrong) {
    // player 1's turn
    printf("\033[2JPlayer 1's turn\n");
    printHangman(player1Guesseswrong);
    printf("you have guessed \033[1;31m%d\033[0;37m letters wrong, those letters were: \033[1;31m", player1Guesseswrong);

    for (int i = 0; i< guessesWrong; i++) {
        printf("\033[1;31m%c\033[0;37m, ", incorrectGuesses[i]);
    }
    printf("\033[0;37m\nYou have currently guessed %s\nPlease input your guess\n", guessed);
    scanf(" %c", &guessedLetter); // take new input

    // run through each letter of the word and check if it equals the letter
    missed = 0; // make sure this is 0 before hand
    for (int i = 0; i < wordlen; i++){
        (player1sWordToGuess == letterInput) ? player1sGuessed[i] == letterInput : missed ++ ;
    }

    if (missed == wordlen) {
        player1Guesseswrong ++;
    }
    
    // player 2's turn
    
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
        printf("\033[2J\n");
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

int competetiveGuessing() {
    char player2sWordToGuess[11];
    char player1sWordToGuess[11];

    char player1sGuessed[11];
    char player2sGuessed[11];

    int player1Guesseswrong;
    int player2Guesseswrong;

    printf("Welcome to competetive guessing, decide on than input a word length\n");
    scanf(" %d", wordlenloc);
    printf("\033[2JYour word will be %d letters long. Player 1 input a word that is %d letters long\n", wordlen, wordlen);
    switch (wordlen) {  // take the input and put it into player2sWordToGuess, because player 1 inputs player2's word
        case 1:
            scanf("%1s", player2sWordToGuess);
            break;
        case 2:
            scanf("%2s", player2sWordToGuess);
            break;
        case 3:
            scanf("%3s", player2sWordToGuess);
            break;
        case 4:
            scanf("%4s", player2sWordToGuess);
            break;
        case 5:
            scanf("%5s", player2sWordToGuess);
            break;
        case 6:
            scanf("%6s", player2sWordToGuess);
            break;
        case 7:
            scanf("%7s", player2sWordToGuess);
            break;
        case 8:
            scanf("%8s", player2sWordToGuess);
            break;
        case 9:
            scanf("%9s", player2sWordToGuess);
            break;
        case 10:
            scanf("%10s", player2sWordToGuess);
            break;
    }

    printf("\033[2JYour word will be %d letters long. Player 1 input a word that is %d letters long\n", wordlen, wordlen);
    switch (wordlen) {  // take the input and put it into player1sWordToGuess, because player 2 inputs player1's word
        case 1:
            scanf("%1s", player1sWordToGuess);
            break;
        case 2:
            scanf("%2s", player1sWordToGuess);
            break;
        case 3:
            scanf("%3s", player1sWordToGuess);
            break;
        case 4:
            scanf("%4s", player1sWordToGuess);
            break;
        case 5:
            scanf("%5s", player1sWordToGuess);
            break;
        case 6:
            scanf("%6s", player1sWordToGuess);
            break;
        case 7:
            scanf("%7s", player1sWordToGuess);
            break;
        case 8:
            scanf("%8s", player1sWordToGuess);
            break;
        case 9:
            scanf("%9s", player1sWordToGuess);
            break;
        case 10:
            scanf("%10s", player1sWordToGuess);
            break;
    }


    // prep both words -'s for guessing
    for (int i = 0; i < wordlen; i++) {
        player1sGuessed[i] = '-';
        player2sGuessed[i] = '-';
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