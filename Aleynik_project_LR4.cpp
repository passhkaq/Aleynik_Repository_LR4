#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// entr check
bool userInput(string input, const int& min, const int& max) {
    if (input.empty()) return false;

    try {
        int number = stoi(input);
        if (number < min) {
            cout << "Minimum valid number is " << min << endl;
            return false;
        } else if (number > max) {
            cout << "Maximum valid number is " << max << endl;
            return false;
        }
    } catch (const exception& e) {return false;};
    return true;
}

void enterNumber(int& variable, const string& prompt, const int& min, const int& max) {
    string input;
    cout << prompt;
    getline(cin, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(cin, input);
    }
    variable = stoi(input);
}

void enterA() {
    enterNumber(a, "Enter A: ", -99999, 99999);
}

void enterB() {

}

void addition() {

}

void subtraction() {

}



int main() {
    struct menuItem {
        string title;
        function<void()> action;
    };

    map <int, menuItem> menu = {
        {1, {"Enter A", enterA}},
        {2, {"Enter B", enterB}},
        {3, {"Add A and B together", addition}},
        {4, {"Subtract A from B", subtraction}},
    };

    int choice = 0;

    while(true) {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << "Task: " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;

        enterNumber(choice, "Enter preferred option: ", 0, 4);

        if (choice == 0) {
            cout << "Poka Poka" << endl;
            break;
        } else if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Incorrect option" << endl;
        }

        cout << endl << endl;
    }

    return 0;
}
