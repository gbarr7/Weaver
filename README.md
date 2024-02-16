#Weaver Game
Description
"Weaver" is a word puzzle game where players transform a starting word into a goal word by changing one letter at a time. Each intermediate word must be a valid word in the dictionary. The game provides an engaging way to explore language and challenge one's vocabulary.

Features
Random word selection for starting and ending words.
Customizable word length for varied difficulty.
Dictionary check to ensure valid words.
Option to play again or change word length after each game.
Input validation for word length and dictionary existence.
How to Play
Start the Game: Run the program and read the introductory message explaining the game.
Choose Word Length: Input the desired length of words for your game session.
Select Words: Enter a starting and ending word of the chosen length, or type 'r' for random words.
Transform the Word: Enter words that change only one letter from the previous, aiming to reach the goal word. Each word must be valid and of the correct length.
Winning: The game ends when you successfully transform the starting word into the ending word.
Menu Options: After a game, choose to play again, change word length, or exit the program.
Functions
displayInstructions(): Displays game instructions.
displayMenu(): Shows options after completing a game.
displayIntro(): Prints the introductory message.
displayWords(char *startWord, char *goalWord): Displays the current start and goal words.
selectRandWord(char **selectedWordList, int countOfWords, char *wordInput): Selects a random word from a list.
compareWords(char *wordOne, char *wordTwo, int letterCount): Compares two words and counts different letters.
InVocabList(char **selectedWordList, int countOfWords, char *word): Checks if a word is in the dictionary.
playGame(char **selectedWordList, int countOfWords, char *startWord, char *goalWord, int letterCount, bool *playAgain, bool *redoWordCount): Main game loop.
gameSetup(char **selectedWordList, int countOfWords, int letterCount, bool *playAgain, bool *redoWordCount): Sets up the game with selected words.
main(): Initializes the game, handles file reading, and manages game sessions.
Requirements
C standard library
A text file named words.txt containing valid words, one per line.
Compilation
Compile with a standard C compiler (e.g., gcc):

bash
Copy code
gcc weaver_game.c -o weaver_game
Execution
Run the compiled program:

bash
Copy code
./weaver_game
Enjoy challenging your vocabulary and strategic thinking skills with Weaver! 🧠📚
