#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkBrackets(const string& str) {
    vector<char> stack;
    const string openBrackets = "([{";
    const string closeBrackets = ")]}";
    bool foundBracket = false;

    for (char c : str) {
        if (openBrackets.find(c) != string::npos) {
            stack.push_back(c);
            foundBracket = true;
        }
        else if (closeBrackets.find(c) != string::npos) {
            if (stack.empty()) {
                return false;
            }
            else if (openBrackets.find(stack.back()) != closeBrackets.find(c)) {
                return false;
            }
            stack.pop_back();
        }
    }

    if (stack.empty() && foundBracket) {
        return true;
    }
    else if (stack.empty() && !foundBracket) {
        cout << "Скобок нет" << endl;
        return false;
    }
    else {
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    string inputString;
    cout << "Введите символьную строку: ";
    getline(cin, inputString);

    if (checkBrackets(inputString)) {
        cout << "Скобки расставлены верно" << endl;
    }
    else {
        cout << "Скобки расставлены неверно" << endl;
    }

    return 0;
}