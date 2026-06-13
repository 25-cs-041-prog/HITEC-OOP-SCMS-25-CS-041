/**
 * @file LibraryItem.cpp
 * @brief Implementation of the LibraryItem abstract base class
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 */

#include "LibraryItem.h"
#include <iostream>
using namespace std;

LibraryItem::LibraryItem(const string& itemID, const string& title,
                         const string& author, int publicationYear)
    : itemID(itemID), title(title), author(author),
      publicationYear(publicationYear), isCheckedOut(false) {}

void LibraryItem::returnItem() {
    isCheckedOut = false;
    cout << "[Library] '" << title << "' has been returned.\n";
}
