
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
using namespace std;

class Utils {
public:
    static void printHeader(const string& title);
    static void printDivider(char ch = '-', int width = 40);
    static string getCurrentDate();
    static bool isNotEmpty(const string& s);
    static bool isValidGPA(double gpa);
    static bool isValidSemester(int sem);
    static string toUpperCase(const string& s);
    static string trim(const string& s);
    static void pressEnterToContinue();
    static void clearScreen();
    static int getIntInput(const string& prompt);
    static double getDoubleInput(const string& prompt);
    static string getStringInput(const string& prompt);
};

#endif 
