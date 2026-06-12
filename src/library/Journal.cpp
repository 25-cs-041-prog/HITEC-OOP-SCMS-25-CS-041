/**
 * @file Journal.cpp
 * @brief Implementation of the Journal class
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 */

#include "Journal.h"
#include <iostream>
#include <iomanip>
using namespace std;

Journal::Journal(const string& itemID, const string& title, const string& author,
                 int publicationYear, const string& issn,
                 int volume, int issueNumber)
    : LibraryItem(itemID, title, author, publicationYear),
      issn(issn), volume(volume), issueNumber(issueNumber) {}

void Journal::checkout() {
    if (!isCheckedOut) {
        isCheckedOut = true;
        cout << "[Library] Journal '" << title << "' checked out.\n";
    } else {
        cout << "[Library] Journal '" << title << "' is already checked out.\n";
    }
}

void Journal::displayInfo() const {
    cout << "┌─────────────────────────────────┐\n";
    cout << "│          JOURNAL INFO           │\n";
    cout << "├─────────────────────────────────┤\n";
    cout << "│ ID     : " << left << setw(24) << itemID          << "│\n";
    cout << "│ Title  : " << left << setw(24) << title           << "│\n";
    cout << "│ Author : " << left << setw(24) << author          << "│\n";
    cout << "│ Year   : " << left << setw(24) << publicationYear << "│\n";
    cout << "│ ISSN   : " << left << setw(24) << issn            << "│\n";
    cout << "│ Volume : " << left << setw(24) << volume          << "│\n";
    cout << "│ Issue  : " << left << setw(24) << issueNumber     << "│\n";
    cout << "│ Status : " << left << setw(24)
         << (isCheckedOut ? "Checked Out" : "Available")         << "│\n";
    cout << "└─────────────────────────────────┘\n";
}

// Format: JOURNAL|itemID|title|author|year|issn|volume|issueNumber
string Journal::toFileString() const {
    return "JOURNAL|" + itemID + "|" + title + "|" + author + "|" +
           to_string(publicationYear) + "|" + issn + "|" +
           to_string(volume) + "|" + to_string(issueNumber);
}
