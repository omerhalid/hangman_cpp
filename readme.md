# Hangman Game in C++

This project is a simple implementation of the classic Hangman game using C++. The game is designed using Object-Oriented Programming (OOP) principles, which helps in organizing the code and making it more maintainable and scalable.

## Architecture

The game is encapsulated in a class named `HangmanGame`. This class contains both the data members and member functions that define the behavior of the game.

### Data Members

- `game_over`: A boolean that indicates whether the game is over.
- `choice`: An integer that stores the user's menu choice.
- `random_line`: An integer that stores the line number of the randomly selected word.
- `word`, `line`, `count`, `guess`, `word_length`: Various private members used in the game logic.

### Member Functions

- `menu()`: Displays the game menu to the user.
- `add_word()`: Allows the user to add a new word to the game.
- `exit_game()`: Exits the game.
- `dashes_for_word(string word)`: Replaces the letters in the word with dashes.
- `random_line_selector()`: Selects a random line number from the words file.
- `print_the_word(int random_line)`: Prints the word at the given line number.
- `guess_letter_in_dashed_word(string word)`: Allows the user to guess a letter in the word.

## Object-Oriented Approach

The game is designed using the principles of OOP. The `HangmanGame` class encapsulates the data and functions related to the game, providing a clear interface and hiding the implementation details. This makes the code easier to understand, maintain, and modify.

## Known Issues and Future Improvements

- There is a known bug where if a letter appears more than once in the word, the game only counts it once. This will be addressed in a future update.
- A future enhancement will be to limit the user to 6 guesses.

## How to Play

The game starts by displaying a menu with three options: Play Game, Add Word, and Exit. The user can choose to start a new game, add a new word to the game, or exit the game. During the game, the user is asked to guess a letter in the hidden word. The game continues until the user guesses the whole word or chooses to exit the game.