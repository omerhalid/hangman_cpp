// use dynamic memory allocation 
// to be refactored 

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int random_line_selector()
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

void dashes_for_word(string &word)
{
    for (int i = 0; i < word.length(); ++i)
    {
        word[i] = '-';
    }

    cout << word << endl;
}

string print_the_word(int &random_line)
{
    ifstream file("C:\\Users\\halen\\source\\cpp\\io stream\\words.txt");
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

    return line;
}


bool guess_letter_in_dashed_word(string &word)
{
    int word_length = word.length();
    int count {0};
    char guess;
    cout << "Guess a letter: ";
    cin >> guess;
    
    for (int i = 0; i < word.length(); ++i)
    {
        if (word[i] == guess)
        {
            ++count;
        }

        if (count == word_length)
        {
            return true;
        }

    }
    return false;
}

void menu()
{
    cout << "1. Play Game" << endl;
    cout << "2. Add Word" << endl;
    cout << "3. Exit" << endl;
}

int main(){
    int choice {};
    int random_line {};
    
    menu();
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            random_line = random_line_selector();
            string word = print_the_word(random_line);
            dashes_for_word(word);
            guess_letter_in_dashed_word(word);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
    }
}