#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Check punctuation
bool isPunctuation(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
           ch == ';' || ch == ',';
}

// Check operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '=';
}

// Check keyword
bool isKeyword(const string& str) {
    string keywords[] = {"int", "char", "return", "float", "double"};
    for (string k : keywords)
        if (str == k)
            return true;
    return false;
}

// Check identifier
bool isIdentifier(const string& str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return false;

    for (char ch : str)
        if (!isalnum(ch) && ch != '_')
            return false;

    return true;
}

// Lexical Analyzer
void lexicalAnalyzer(const string& input) {
    int i = 0;
    int n = input.length();

    cout << "TOKENS\n";

    while (i < n) {

        // Ignore spaces
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isalpha(input[i])) {
            string word = "";
            while (i < n && isalnum(input[i])) {
                word += input[i++];
            }

            if (isKeyword(word))
                cout << "Keyword: " << word << endl;
            else
                cout << "Identifier: " << word << endl;
        }

        // Integer Constant
        else if (isdigit(input[i])) {
            string num = "";
            while (i < n && isdigit(input[i])) {
                num += input[i++];
            }
            cout << "Constant: " << num << endl;
        }

        // Character Constant
        else if (input[i] == '\'') {
            cout << "Constant: '" << input[i + 1] << "'" << endl;
            i += 3;
        }

        // Operator
        else if (isOperator(input[i])) {
            cout << "Operator: " << input[i] << endl;
            i++;
        }

        // Punctuation
        else if (isPunctuation(input[i])) {
            cout << "Punctuation: " << input[i] << endl;
            i++;
        }

        else {
            i++;
        }
    }
}

// Main function
int main() {
    string input;
    getline(cin, input);   // read full line including spaces
    lexicalAnalyzer(input);
    return 0;
}


