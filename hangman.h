#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <vector>
#include <set>

using namespace std;

const int START_HEART {6}; 

class HangmanGame
{
    public:
        bool game_over {false};
        int choice {};
        int random_line {0};
        int left_chances; // by default every user will start with 6 chanses.
        // HangmanGame();
        // ~HangmanGame();
        void menu();
        void play_game();
        void add_word();
        void exit_game();
        void dashes_for_word(string word);
        int random_line_selector();
        string print_the_word(int random_line);
        bool guess_letter_in_dashed_word(string word, int &left_chances);
    private:
        string word {};
        string line {};
        int count {0};
        char guess {};
        int word_length {};
};

#endif // HANGMANGAME_H