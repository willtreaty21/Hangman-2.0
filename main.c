#include <stdio.h>
#include <unistd.h>

int playerInput; // a number the player inputs
int* playerinputlocation = &playerInput; // used to get the input from scanf
int wordlen; // length of the word the player guesses
int* wordlenloc = &wordlen; // 
int guessesWrong = 0; // guesses wrong for player 1
int missed = 0;
int lettersCorrect;

char letterInputLocation;
char stringInput[11];
char guessed[20];
char incorrectGuesses[8];
char incorrectGuesses2[8];
char guessedLetter;


char player2sWordToGuess[11];
char player1sWordToGuess[11];
char player1sGuessed[11];
char player2sGuessed[11];
int player1Guesseswrong = 0;
int player2Guesseswrong = 0;

int player1wins = 0;
int player2wins = 0;

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

void twoPlayerGuess() {
    // player 1's turn
    printf("\n\033[2JPlayer 1's turn\n");
    printHangman(player1Guesseswrong);
    printf("you have guessed %d letters wrong, those letters were:", player1Guesseswrong);

    // print out the letters that were wrong
    for (int i = 0; i < player1Guesseswrong; i++) {
        printf(" %c,", incorrectGuesses[i]);
    }
    printf("\nYou have currently Guessed %s\nPlease input your guess\n", player1sGuessed);
    scanf(" %c", &guessedLetter);

    // run through each letter of the given word to check if it equals the letter that the player guessed
    missed = 0;
    for (int i = 0; i < wordlen; i++) {
        (guessedLetter == player1sGuessed[i])? printf("\nrepeat letter guess"): (guessedLetter == player1sWordToGuess[i])? player1sGuessed[i] = guessedLetter: missed++;
    }
    if (missed >= wordlen) {
        player1Guesseswrong ++;
        incorrectGuesses[player1Guesseswrong - 1] = guessedLetter;
    }
    
    // player 2's turn ------------------------------
    printf("\n\033[2JPlayer 2's turn\n");
    printHangman(player2Guesseswrong);
    printf("you have guessed %d letters wrong, those letters were:", player2Guesseswrong);
    // print out wrong letters

    for (int i = 0; i < player1Guesseswrong; i ++) {
        printf(" %c,", incorrectGuesses2[i]);
    }
    printf("\nYou have currently Guessed %s\nPlease input your guess\n", player2sGuessed);
    scanf(" %c", &guessedLetter);

    // check if it was right
    missed = 0;
    for (int i = 0; i < wordlen; i++) {
        (guessedLetter == player2sWordToGuess[i])? player2sGuessed[i] = guessedLetter: missed++;
    }
    if (missed >= wordlen) {
        player2Guesseswrong ++;
        incorrectGuesses2[player2Guesseswrong - 1] = guessedLetter;
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

    // main loop
    while (1) {
        twoPlayerGuess();

        if (player1Guesseswrong == 7) {
            printf("\033[2JGameOver");
            return 0;
        }
        
        // count the letters correct for player 1
        lettersCorrect = 0;
        for(int i = 0; i< wordlen; i++) {
            if (player1sGuessed[i] == player1sWordToGuess[i]) {
                lettersCorrect ++;
            }
        }
        if (lettersCorrect == wordlen) { // check if they win
            player1wins = 1;
        }

        // count the letters correct for player 2
        lettersCorrect = 0;
        for(int i = 0; i< wordlen; i++) {
            if (player2sGuessed[i] == player2sWordToGuess[i]) {
                lettersCorrect ++;
            }
        }
        if (lettersCorrect == wordlen) { // check if they win
            player2wins = 1;
        }

        if (player1wins >= 1 && player2wins >= 1) {
            printf("Both players won on the same round\n");
            return 0;
        }
        else if (player1wins == 1 || player2wins == 1) {
            (player1wins == 1)? printf("player 1 Wins\n") : printf("player 2 wins\n");
            return 0;
        }
    }
}

void twoPlayer() {
    printf("There are are two modes available, Single guesser or competetive guessing, Single guesser is where one person inputs a word and the other tries to guess it and \nCompetetive guessing is where both players select a word of the same length and both take turns guessing \nWhich would you like to select? (Single guesser(1)/Competetive Guessing(2))\n");
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