// BUG: if there is a letter in the word that appears more than once, the game will only count it once

// TODO: User will have 6 guesses

#include "hangman.h"

void HangmanGame :: exit_game()
{
    cout << "Exiting game..." << endl;
    exit(0);
}

void HangmanGame :: add_word()
{
    cout << "Enter a word to add to the game: ";
    cin >> word;

    ofstream file("C:\\Users\\halen\\source\\hangman_cpp\\words.txt", ios::app);

    if (!file.is_open())
    {
        cout << "File not found" << endl;
    }
    else
    {
        file<< word << endl;
    }

    file.close();
}

int HangmanGame :: random_line_selector()
{
    ifstream file("C:\\Users\\halen\\source\\hangman_cpp\\words.txt");
    string line;
    int count {0};

    if (!file.is_open())
    {
        cout << "File not found" << endl;
    }
    else
    {
        while(getline(file, line)){
            ++count;
        }
    }

    file.close();

    

    // return a random number between 1 and count
    srand(time(0)); // seed the random number generator
    return rand() % count + 1; // generate a random number between 1 and count

}

void HangmanGame :: dashes_for_word(string word)
{
    for (int i = 0; i < word.length(); ++i)
    {
        word[i] = '-';
    }

    cout << word << endl;
}

string HangmanGame :: print_the_word(int random_line)
{
    ifstream file("C:\\Users\\halen\\source\\hangman_cpp\\words.txt");
    string line;
    int count {0};

    if (!file.is_open())
    {
        cout << "File not found" << endl;
    }
    else
    {
        while(getline(file, line)){
            ++count;
            if (count == random_line)
            {
                return line;
            }
        }
    }

    file.close();
    return "";
}


bool HangmanGame :: guess_letter_in_dashed_word(string word)
{
    int word_length = word.length();
    int count {0};
    char guess;

    vector<bool> guessed(word_length, false); // track which letters have been guessed

    while (true)
    {
        cout << "Guess a letter: ";
        cin >> guess;

        bool correct_guess = false;
        for (int i = 0; i < word_length; ++i)
        {
            if (tolower(word[i]) == tolower(guess) && !guessed[i])
            {
                guessed[i] = true;
                ++count;
                cout << "You guessed a letter" << endl;
                correct_guess = true;
            }
        }

        if (!correct_guess)
        {
            cout << "Incorrect guess, try again." << endl;
        }

        if (count == word_length)
        {
            cout << "You won!" << endl;
            return true;
        }
    }
    return false;
}

void HangmanGame :: menu()
{
    cout << "1. Play Game" << endl;
    cout << "2. Add Word" << endl;
    cout << "3. Exit" << endl;
}

int main(){
    HangmanGame game; // create an instance of HangmanGame

    while (game.game_over == false){

        game.menu();
        cin >> game.choice;

        switch (game.choice)
    {
        case 1:
        {
            game.random_line = game.random_line_selector();
            cout << "random line: " << game.random_line << endl; // for debugging
            string word = game.print_the_word(game.random_line);
            cout << "word: " << word << endl; // for debugging
            game.dashes_for_word(word);
            game.guess_letter_in_dashed_word(word);
            break;
        }
        case 2:
        {
            game.add_word();
            break;
        }
        case 3:
        {
            game.exit_game();
            game.game_over = true;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
    }
    }

    
}