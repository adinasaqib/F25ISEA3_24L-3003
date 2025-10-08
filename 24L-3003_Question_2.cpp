#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib> //srand
#include <cctype>
using namespace std;

// to read words from file
void loadWords(vector<string>& words) {
    ifstream file("hangman_24L-3003.txt");
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
}

// to check if letter already guessed
bool alreadyGuessed(char letter, string guessedLetters) {
    for (int i = 0; i < guessedLetters.length(); i++) {
        if (guessedLetters[i] == letter)
            return true;
    }
    return false;
}

// Function to display the current word state
void showWord(string word, string guessedLetters) {
    for (int i = 0; i < word.length(); i++) {
        if (alreadyGuessed(tolower(word[i]), guessedLetters) || alreadyGuessed(toupper(word[i]), guessedLetters))
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

// Function to check if player has guessed all letters
bool wordCompleted(string word, string guessedLetters) {
    for (int i = 0; i < word.length(); i++) {
        char c = tolower(word[i]);
        if (!alreadyGuessed(c, guessedLetters))
            return false;
    }
    return true;
}

int main() {
    vector<string> words;
    loadWords(words);

    if (words.empty()) {
        cout << "No words found in file!" << endl;
        return 0;
    }

    srand(time(0));
    string word = words[rand() % words.size()];
    string guessedLetters = "";
    int remainingMistakes = 7;
    char guess;

    cout << "=== HANGMAN GAME ===" << endl;
    cout << "You have 7 chances to guess the word." << endl;

    while (true) {
        cout << endl << "Word: ";
        showWord(word, guessedLetters);

        cout << "Guessed letters: " << guessedLetters << endl;
        cout << "Remaining mistakes: " << remainingMistakes << endl;

        cout << "Enter a letter: ";
        cin >> guess;
        guess = tolower(guess);

        if (!isalpha(guess)) {
            cout << "Invalid input! Please enter a letter." << endl;
            continue;
        }

        if (alreadyGuessed(guess, guessedLetters)) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        guessedLetters += guess;

        bool found = false;
        for (int i = 0; i < word.length(); i++) {
            if (tolower(word[i]) == guess) {
                found = true;
                break;
            }
        }

        if (!found) {
            remainingMistakes--;
            cout << "Wrong guess!" << endl;
        }
        else {
            cout << "Good guess!" << endl;
        }

        if (wordCompleted(word, guessedLetters)) {
            cout << endl << "You guessed the word: " << word << endl;
            cout << "Congratulations! You win!" << endl;
            break;
        }

        if (remainingMistakes == 0) {
            cout << endl << "You are out of guesses!" << endl;
            cout << "The word was: " << word << endl;
            cout << "You lose!" << endl;
            break;
        }
    }

    return 0;
}

