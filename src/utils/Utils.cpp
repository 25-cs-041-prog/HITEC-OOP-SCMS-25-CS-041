
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
using namespace std;

void Utils::printHeader(const string& title) {
    int width = 42;
    string line;
    for (int i = 0; i < width; i++) line += "\xE2\x95\x90"; 
    cout << "\n" << line << "\n";
    int pad = (width - static_cast<int>(title.length())) / 2;
    cout << string(pad, ' ') << title << "\n";
    cout << line << "\n";
}

void Utils::printDivider(char ch, int width) {
    cout << string(width, ch) << "\n";
}

string Utils::getCurrentDate() {
    return "2025-01-01"; 
}

bool Utils::isNotEmpty(const string& s) {
    return !s.empty() && s.find_first_not_of(' ') != string::npos;
}

bool Utils::isValidGPA(double gpa) {
    return gpa >= 0.0 && gpa <= 4.0;
}

bool Utils::isValidSemester(int sem) {
    return sem >= 1 && sem <= 8;
}
string Utils::toUpperCase(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string Utils::trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

void Utils::pressEnterToContinue() {
    cout << "\n  [Press Enter to continue...]";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Utils::clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int Utils::getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [Invalid] Please enter a valid integer.\n";
    }
}

double Utils::getDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [Invalid] Please enter a valid number.\n";
    }
}

string Utils::getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return trim(value);
}
