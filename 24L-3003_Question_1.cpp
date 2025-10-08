#include <iostream>
#include <string>
#include <cctype>   // for isalpha
#include <conio.h>  // for _getch()
using namespace std;

// Function to check if input contains only alphabets(robustness)
bool isAlphaOnly(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isalpha(s[i]))
            return false;
    }
    return true;
}

int main() {
    string str;
    char ch;

    cout << "=== Palindrome Checker ===" << endl;

    while (true) {
        cout << endl << "Enter a word: ";
        cin >> str; //spaces get ignored-another validation check

        // Input validation
        if (!isAlphaOnly(str)) {
            cout << "Invalid input! Please enter alphabets only." << endl;
        }
        else {
            bool isPalindrome = true;
            int len = str.length();

            for (int i = 0; i < len / 2; i++) {
                if (tolower(str[i]) != tolower(str[len - i - 1])) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome)
                cout << "Palindrome" << endl;
            else
                cout << "Not Palindrome" << endl;
        }

        cout << endl << "Press ESC to quit or any other key to check another word";
        ch = _getch();
        if (ch == 27) {  // 27 ASCII = ESC
            cout << endl << "Program ended." << endl;
            break;
        }
    }

    return 0;
}
