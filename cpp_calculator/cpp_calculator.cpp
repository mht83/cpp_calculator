#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>

using namespace std;

string initializer(const string& inputPhrase) {
    bool isChangeApplied = true;
    string phrase = inputPhrase;

    while (isChangeApplied) {
        isChangeApplied = false;
        size_t i = 0;
        while (i < phrase.length() - 1) {
            if (phrase[i] == '-' && phrase[i + 1] == '-') {
                phrase = phrase.substr(0, i) + "+" + phrase.substr(i + 2);
                isChangeApplied = true;
            }
            else if ((phrase[i] == '-' && phrase[i + 1] == '+') || (phrase[i] == '+' && phrase[i + 1] == '-')) {
                phrase = phrase.substr(0, i) + "-" + phrase.substr(i + 2);
                isChangeApplied = true;
            }
            else if (phrase[i] == '+' && phrase[i + 1] == '+') {
                phrase = phrase.substr(0, i) + "+" + phrase.substr(i + 2);
                isChangeApplied = true;
            }
            ++i;
        }
    }


    if (!phrase.empty() && phrase[0] == '-') {
        phrase = "0" + phrase;
    }

    return phrase;
}


bool is_valid_input(const string& input) {
    const string validCharacters = "1234567890.*-+/^()";
    for (char c : input) {
        if (validCharacters.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}


vector<string> tokenizeString(const string& str, const vector<char>& delimiters) {
    vector<string> tokens;
    string token;
    size_t start = 0, end = 0;

    while ((end = str.find_first_of(delimiters.data(), start)) != string::npos) {
        if (end != start) {
            token = str.substr(start, end - start);
            tokens.push_back(token);
        }
        tokens.push_back(string(1, str[end]));
        start = end + 1;
    }

    if (start < str.size()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

double performOperation(const double& operand1, const double& operand2, const char& op) {
    switch (op) {
    case '^': return pow(operand1, operand2);
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    default: return 0;
    }
}


double calculator(vector<string>& tokens) {

    vector<char> operations = { '^', '*', '/', '+', '-' };

    for (char op : operations) {
        for (size_t i = 1; i < tokens.size(); ++i) {
            if (tokens[i] == string(1, op)) {
                double operand1 = stod(tokens[i - 1]);
                double operand2 = stod(tokens[i + 1]);
                double result = performOperation(operand1, operand2, op);
                tokens[i - 1] = to_string(result);
                tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
                i--;
            }
        }
    }

    return stod(tokens.front());
}



double evaluateAndCalculate(vector<string>& tokens) {
    stack<int> parenthesesIndices;
    while (true) {
        bool found = false;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "(") {
                parenthesesIndices.push(i);
            }
            else if (tokens[i] == ")") {
                found = true;
                int start = parenthesesIndices.top();
                parenthesesIndices.pop();
                vector<string> subExpr(tokens.begin() + start + 1, tokens.begin() + i);
                double result = calculator(subExpr);
                tokens.erase(tokens.begin() + start, tokens.begin() + i + 1);
                tokens.insert(tokens.begin() + start, to_string(result));
                break;
            }
        }
        if (!found) {
            break;
        }
    }


    return calculator(tokens);
}


int main() {
    string user_input;
    cin >> user_input;

    vector<char> delimiters = { '/', '*', '-', '+', '^', '(', ')' };


    if (is_valid_input(user_input)) {
        string initialiedInput = initializer(user_input);
        vector<string> tokenized_string = tokenizeString(initialiedInput, delimiters);
        double finalResult = evaluateAndCalculate(tokenized_string);
        cout << "Final Result: " << finalResult << endl;
    }

    else
        cout << "invalid input";


    int getch();
}
