/*-------------------------------------------
Program 2: Weaver
Course: CS 211, Spring 2023, UIC
System: Replit
Author: Giovani Barrera
------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct WordSelection{

    char startWord[60];

    char goalWord[60];

};
void displayInstructions(){
/*This function prints the starting instuctions, it can be found only at the start of the playGame() Function. */

    printf("\n");

    printf("On each move enter a word of the same length that is at most 1 character different and is also in the dictionary.\n");

    printf("You may also type in 'q' to quit guessing. \n");

    printf("\n");

}
void displayMenu(){
/*This function prints the menu options that are used once the code gets to the end of the playGame() Function. */

    printf("\n");

    printf("Enter: 1 to play again, \n");

    printf("       2 to change the number of letters in the words and then play again, or \n");

    printf("       3 to exit the program. \n");

    printf("Your choice --> ");

}

void displayIntro(){
/*This function prints the intro to the game weaver, it is used only at the start of main. */

    printf("Weaver is a game where you try to find a way to get from the starting word to the ending word.\n");

    printf("You can change only one letter at a time, and each word along the way must be a valid word.\n");

    printf("Enjoy!\n\n");

}
void displayWords(char *startWord, char *goalWord){
/*This function print the start word and goal word. The code requires two parameters, which are both pointer char values that contain the string values of the startWord, and the goalWord.*/

    printf("Your starting word is: %s. \n", startWord);

    printf("Your ending word is: %s. \n", goalWord);
}

void selectRandWord(char **selectedWordList, int countOfWords, char *wordInput){
/*This function uses 3 parameters to assign a random string value to the either startWord, or goalWord. This process is done by using the in parameter CountOfWords, which is the total amount of strings that is inside the dynamic array SelectedWordList. since CountOfWords is the max amount of the dynamic array, I malloc that with rand(), to get a random value that is in the range of CountOfWords. With this we can get a random Index value. The last step is using that index value and using strcpy to copy over a random string from within selectedWordList to the wordInput, which can only be startWord, or goalWord. This code is used within gameSetup only when a uses types 'r'*/

    int ranIndex = rand() % countOfWords;

    strcpy(wordInput, selectedWordList[ranIndex]);

}

int compareWords(char *wordOne, char *wordTwo, int letterCount){
/*This int function uses 3 parameters to keep track of how many letters were changed between two words. This is done by using letterCount, which is the amount of letters that the user inputed at the start of gameSetup. The function compares wordOne and wordTwo to see how many letters are diffrent. This is kept track by the counter within the function. Once the for loop is done, the code will return counter, which will inform the game how many letters were changed within a single turn.  */

    int counter = 0;

    for(int i = 0; i < letterCount; i++){

        if(wordOne[i] != wordTwo[i]){

            counter++;

        }

    }

    return counter;

}

bool InVocabList(char **selectedWordList, int countOfWords, char *word){
/*This bool function uses 3 parameters to detect whether or not a word is in the selectedWordList, this done through the use of countOfWords, which is the total size of the dynamic array, at any given time. Using countOfWords in a for loop, the function uses strcmp to compare every single string that is in the dynamic array selectedWordList to the parameter word, which is the user input. If the word is found, the bool result will turn true, and will be returned as that value. */

    bool result = false;

    for(int i = 0; i < countOfWords; i++){

        if(strcmp(word, selectedWordList[i]) == 0){

            result = true;

        }

    }

    return result;
}

void playGame(char **selectedWordList, int countOfWords, char *startWord, char *goalWord, int letterCount, bool *playAgain, bool *redoWordCount){
    /*This function is the main game, and it uses 7 parameters to accomplish the main goal of the game, which is to get starWord to goalWord.*/

    bool tracker = false;

    int MenuOption = 0, counter = 1;

    char tempWord[60];

    char originalWord[60];

    displayWords(startWord, goalWord);

    displayInstructions();

    strcpy(originalWord, startWord);

/*This portion of the code above established variables that are going to be used later on in the function. In specfic, bool tracker to indicate whether the game is done or not, int counter to keep track of the turns, and int menuOption to select a menu option. Secondly the portion above display the instructions for the game, and also the startWord and goalWord. Finaly, there is a variable that contains the copy of the original startWord, to be used a the end of the game, and tempWord to get the input of the user.*/

    do{

        printf("%d. Previous word is '%s'. Goal word is '%s'. Next word: ", counter, startWord , goalWord);

        scanf("%s", tempWord);

        if (strcmp(tempWord, "q") == 0){

            break;

        }

        if (strlen(tempWord) == letterCount){

            if(InVocabList(selectedWordList, countOfWords, tempWord) == true){

                if(compareWords(startWord, tempWord, letterCount) == 1){

                    strcpy(startWord, tempWord);

                    counter++;

                }

                else{

                    printf("Your word, '%s', is not exactly 1 character different. Try again.", tempWord);

                    printf("\n");

                    printf("\n");

                }

            }

            else{

                printf("Your word, '%s', is not a valid dictionary word. Try again.", tempWord);

                printf("\n");

                printf("\n");

            }

        }

        else{

            printf("Your word, '%s', is not a %d-letter word. Try again.", tempWord, letterCount);

            printf("\n");

            printf("\n");
        }

        if(compareWords(startWord, goalWord, letterCount) == 0){

            tracker = true;

            printf("Congratulations! You changed '%s' into '%s' in %d moves. \n", originalWord, goalWord, counter - 1);
        }

        else{

            printf("\n");

        }

    } while(tracker == false);
/*This portion of the code above is the game itself. The first thing that this code does is get the user input through tempWord. Once the user types in the tempWord. the follwing is done 1) It checks whether the word is the accurate word length that the game is set to by comparing letterCount to strlen(tempWord), if not the code will display a error. 2) it will check if tempWord is within the vocablist by using InVocabList(), with parameters countOfWords and the dynamic list selectedWordList 3) It will compare tempWord, and startword, to see if how many letters were changed, if the value is not one, then there would be a error. 4) If all checks are done, then temp word will become the new startWord. After this, the counter will go up by one, will check if start word and goal word are the same, if not, then a new line is printed, then the loop goes again.*/
    displayMenu();

    scanf("%d", &MenuOption);

    switch(MenuOption){

        case 1:

            *playAgain = true;

            *redoWordCount = false;

            break;

        case 2:

            *redoWordCount = true;

            *playAgain = false;

            break;

        case 3:

            *playAgain = false;

            *redoWordCount = false;

            break;

    }
}
/*this portion of is the switch menu, once the user wins the game, it ask the user on what they desires to do, based on the options, If they select 1, then they would redo the game over again. The same applies to the other option. This is done through pointer bool variables, which indicate to other functions on whether that specific loop will keep going. */

void gameSetup(char **selectedWordList, int countOfWords, int letterCount, bool *playAgain, bool *redoWordCount){

    bool fail = false;

    bool fail2 = false;

    bool result;

    struct WordSelection selection;

    do {

        printf("Enter starting and ending words, or 'r' for either for a random word: ");

        scanf("%s", selection.startWord);

        scanf("%s", selection.goalWord);

        if(strcmp(selection.startWord, "r") == 0){

            selectRandWord(selectedWordList, countOfWords, selection.startWord);

        }

        if(strcmp(selection.goalWord, "r") == 0){

            selectRandWord(selectedWordList, countOfWords, selection.goalWord);

        }

        if (strlen(selection.startWord) == letterCount){

            result = InVocabList(selectedWordList, countOfWords, selection.startWord);

            if(result == true){

                fail = false;

            }

            else{

                printf("Your word, '%s', is not a valid dictionary word. Try again.\n", selection.startWord);

                fail = true;

            }

        }

        else{

            printf("Your word, '%s', is not a %d-letter word. Try again.\n", selection.startWord, letterCount);

            fail = true;

        }

        if(fail != true){

            if (strlen(selection.goalWord) == letterCount){

                result = InVocabList(selectedWordList, countOfWords, selection.goalWord);

                if(result == true){

                    fail2 = false;

                }

                else{

                    printf("Your word, '%s', is not a valid dictionary word. Try again.\n", selection.goalWord);

                    fail2 = true;

                }
            }


            else {

                printf("Your word, '%s', is not a %d-letter word. Try again.\n", selection.goalWord, letterCount);

                fail2 = true;

            }
        }

    } while(fail == true || fail2 == true);

    playGame(selectedWordList, countOfWords, selection.startWord, selection.goalWord, letterCount, playAgain, redoWordCount );

}

int main() {

    srand(1);

    bool playAgain = false, redoWordCount = false;

    char **wordList = NULL, **selectedWordList = NULL;

    int filesize = 0, letterCount = 0, CountOfWords = 0, index = 0;

    char filename[] = "words.txt";

    char vocabString[81], inputString[81];

    FILE* filePtr = fopen(filename, "r"); // "r" means we open the file for reading

    // Check that the file was able to be opened

    if (filePtr == NULL) {

        printf("Error: could not open %s for reading\n", filename);

        exit(-1);

    }

    while (fscanf(filePtr, "%s", inputString) != EOF) {

        filesize++;

        wordList = (char**) realloc(wordList, filesize * sizeof(char*));

        wordList[filesize - 1] = (char*) malloc((strlen(inputString) + 1) * sizeof(char));

        strcpy(wordList[filesize - 1], inputString);

    }

    // Close the file
    fclose(filePtr);

    displayIntro();

    do{

        printf("How many letters do you want to have in the words? ");

        scanf(" %d", &letterCount);

        for (int i = 0; i < filesize; i++) {

            if(strlen(wordList[i]) == letterCount){

                index++;

                CountOfWords++;

                selectedWordList = (char**) realloc(selectedWordList, index * sizeof(char*));

                selectedWordList[index - 1] = (char*) malloc((strlen(wordList[i]) + 1) * sizeof(char));

                strcpy(selectedWordList[index - 1], wordList[i]);

            }

        }

        printf("Number of %d-letter words found: %d. \n \n", letterCount, CountOfWords);

        do{

            gameSetup(selectedWordList, CountOfWords, letterCount, &playAgain, &redoWordCount);

        }while(playAgain == true);

        for (int i = 0; i < index; i++) {

            free(selectedWordList[i]);

        }

        letterCount = 0;

        CountOfWords = 0;

        index = 0;

    }while(redoWordCount == true);

    free(selectedWordList);

    for (int i = 0; i < filesize; i++) {

        free(wordList[i]);

    }

    free(wordList);

    printf("\n");

    printf("Thanks for playing! \n");

    printf("Exiting... \n");

    return 0;

}