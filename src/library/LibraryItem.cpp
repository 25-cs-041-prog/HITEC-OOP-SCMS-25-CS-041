
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
