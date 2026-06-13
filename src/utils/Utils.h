/**
 * @file Utils.h
 * @brief Utility helper functions — string formatting, validation, date
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Utility Functions, Input Validation
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
using namespace std;

// ─────────────────────────────────────────────────────────────
// Utils — static utility class (all methods are static helpers)
// ─────────────────────────────────────────────────────────────
class Utils {
public:
    // Print a section header banner
    static void printHeader(const string& title);

    // Print a divider line (default: a row of '-')
    static void printDivider(char ch = '-', int width = 40);

    // Get today's date as a simple string (YYYY-MM-DD format placeholder)
    static string getCurrentDate();

    // Validate that a string is not empty
    static bool isNotEmpty(const string& s);

    // Validate GPA is between 0.0 and 4.0
    static bool isValidGPA(double gpa);

    // Validate semester is between 1 and 8
    static bool isValidSemester(int sem);

    // Convert string to uppercase
    static string toUpperCase(const string& s);

    // Trim leading/trailing whitespace
    static string trim(const string& s);

    // Pause and wait for Enter key
    static void pressEnterToContinue();

    // Clear screen (cross-platform)
    static void clearScreen();

    // Safe integer input with prompt
    static int getIntInput(const string& prompt);

    // Safe double input with prompt
    static double getDoubleInput(const string& prompt);

    // Safe string input with prompt
    static string getStringInput(const string& prompt);
};

#endif // UTILS_H
