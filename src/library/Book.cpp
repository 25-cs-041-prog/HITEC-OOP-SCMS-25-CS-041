/**
 * @file Book.cpp
 * @brief Implementation of the Book class
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Override, File I/O serialisation
 */

#include "Book.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Book::Book(const string& itemID, const string& title, const string& author,
           int publicationYear, const string& isbn,
           const string& genre, int copiesAvailable)
    : LibraryItem(itemID, title, author, publicationYear),
      isbn(isbn), genre(genre), copiesAvailable(copiesAvailable) {}

void Book::checkout() {
    if (copiesAvailable > 0) {
        copiesAvailable--;
        isCheckedOut = (copiesAvailable == 0);
        cout << "[Library] Book '" << title
             << "' checked out. Copies left: " << copiesAvailable << "\n";
    } else {
        cout << "[Library] No copies of '" << title << "' available.\n";
    }
}

void Book::returnItem() {
    copiesAvailable++;
    isCheckedOut = false;
    cout << "[Library] Book '" << title << "' returned. Copies now: "
         << copiesAvailable << "\n";
}

void Book::displayInfo() const {
    cout << "┌─────────────────────────────────┐\n";
    cout << "│            BOOK INFO            │\n";
    cout << "├─────────────────────────────────┤\n";
    cout << "│ ID     : " << left << setw(24) << itemID          << "│\n";
    cout << "│ Title  : " << left << setw(24) << title           << "│\n";
    cout << "│ Author : " << left << setw(24) << author          << "│\n";
    cout << "│ Year   : " << left << setw(24) << publicationYear << "│\n";
    cout << "│ ISBN   : " << left << setw(24) << isbn            << "│\n";
    cout << "│ Genre  : " << left << setw(24) << genre           << "│\n";
    cout << "│ Copies : " << left << setw(24) << copiesAvailable << "│\n";
    cout << "│ Status : " << left << setw(24)
         << (isCheckedOut ? "Checked Out" : "Available")         << "│\n";
    cout << "└─────────────────────────────────┘\n";
}

// Format: BOOK|itemID|title|author|year|isbn|genre|copies
string Book::toFileString() const {
    return "BOOK|" + itemID + "|" + title + "|" + author + "|" +
           to_string(publicationYear) + "|" + isbn + "|" + genre + "|" +
           to_string(copiesAvailable);
}
