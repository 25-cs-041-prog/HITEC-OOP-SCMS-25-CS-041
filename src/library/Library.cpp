
#include "Library.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Library::Library(const string& catalogFile)
    : catalogSize(0), issuedCount(0), catalogFile(catalogFile) {
    for (int i = 0; i < MAX_CATALOG; i++) catalog[i] = nullptr;
}

Library::~Library() {
    for (int i = 0; i < catalogSize; i++) {
        delete catalog[i];  
        catalog[i] = nullptr;
    }
}

void Library::addItem(LibraryItem* item) {
    if (catalogSize < MAX_CATALOG) {
        catalog[catalogSize++] = item;
    } else {
        cout << "[Library] Catalog is full. Cannot add more items.\n";
    }
}

void Library::removeItem(const string& itemID) {
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i]->getItemID() == itemID) {
            delete catalog[i];
            
            for (int j = i; j < catalogSize - 1; j++)
                catalog[j] = catalog[j + 1];
            catalog[--catalogSize] = nullptr;
            cout << "[Library] Item '" << itemID << "' removed.\n";
            return;
        }
    }
    throw ItemNotFoundException(itemID);
}

LibraryItem* Library::searchByTitle(const string& title) const {
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i]->getTitle() == title)
            return catalog[i];
    }
    return nullptr;
}

LibraryItem* Library::searchByID(const string& itemID) const {
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i]->getItemID() == itemID)
            return catalog[i];
    }
    return nullptr;
}

void Library::issueItem(const string& rollNo, const string& itemID,
                        const string& date) {
    LibraryItem* item = searchByID(itemID);
    if (!item) throw ItemNotFoundException(itemID);

    item->checkout();

    if (issuedCount < MAX_ISSUED) {
        issuedItems[issuedCount++] = {rollNo, itemID, date, 0};
        cout << "[Library] Item '" << itemID
             << "' issued to " << rollNo << "\n";
    }
}

void Library::returnItem(const string& rollNo, const string& itemID,
                         int daysKept) {
    const int LOAN_PERIOD = 14;

    LibraryItem* item = searchByID(itemID);
    if (!item) throw ItemNotFoundException(itemID);

    for (int i = 0; i < issuedCount; i++) {
        if (issuedItems[i].rollNo == rollNo &&
            issuedItems[i].itemID == itemID) {
            
            for (int j = i; j < issuedCount - 1; j++)
                issuedItems[j] = issuedItems[j + 1];
            issuedCount--;
            break;
        }
    }

    item->returnItem(); 
    
    if (daysKept > LOAN_PERIOD) {
        int    overdueDays = daysKept - LOAN_PERIOD;
        double fine        = overdueDays * FINE_PER_DAY;
        throw OverdueException(item->getTitle(), fine);
    }
}

void Library::saveToFile() const {
    ofstream outFile(catalogFile);
    if (!outFile.is_open()) {
        cout << "[Library] Error: Could not open file for writing: "
             << catalogFile << "\n";
        return;
    }

    for (int i = 0; i < catalogSize; i++) {
        Book*    b = dynamic_cast<Book*>(catalog[i]);
        Journal* j = dynamic_cast<Journal*>(catalog[i]);
        if (b) outFile << b->toFileString() << "\n";
        else if (j) outFile << j->toFileString() << "\n";
    }

    outFile.close();
    cout << "[Library] Catalog saved to '" << catalogFile << "'\n";
}

void Library::loadFromFile() {
    ifstream inFile(catalogFile);
    if (!inFile.is_open()) {
        cout << "[Library] No existing catalog found at '"
             << catalogFile << "'. Starting fresh.\n";
        return;
    }

    for (int i = 0; i < catalogSize; i++) {
        delete catalog[i];
        catalog[i] = nullptr;
    }
    catalogSize = 0;

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        // Tokenise by '|'
        string tokens[10];
        int    tokenCount = 0;
        stringstream ss(line);
        string token;
        while (getline(ss, token, '|') && tokenCount < 10)
            tokens[tokenCount++] = token;

        if (tokenCount < 1) continue;

        if (tokens[0] == "BOOK" && tokenCount >= 8) {
            Book* b = new Book(
                tokens[1], tokens[2], tokens[3],
                stoi(tokens[4]), tokens[5], tokens[6], stoi(tokens[7])
            );
            addItem(b);
        } else if (tokens[0] == "JOURNAL" && tokenCount >= 8) {
            Journal* j = new Journal(
                tokens[1], tokens[2], tokens[3],
                stoi(tokens[4]), tokens[5], stoi(tokens[6]), stoi(tokens[7])
            );
            addItem(j);
        }
    }

    inFile.close();
    cout << "[Library] Loaded " << catalogSize
         << " items from '" << catalogFile << "'\n";
}

void Library::displayCatalog() const {
    cout << "\n════════ LIBRARY CATALOG (" << catalogSize << " items) ════════\n";
    if (catalogSize == 0) {
        cout << "  (empty)\n";
        return;
    }
    for (int i = 0; i < catalogSize; i++) {
        catalog[i]->displayInfo(); 
    }
}

void Library::displayIssuedItems() const {
    cout << "\n════════ ISSUED ITEMS (" << issuedCount << ") ════════\n";
    if (issuedCount == 0) {
        cout << "  (none currently issued)\n";
        return;
    }
    cout << left << setw(12) << "Roll No"
         << setw(12) << "Item ID"
         << setw(15) << "Issue Date" << "\n";
    cout << string(39, '-') << "\n";
    for (int i = 0; i < issuedCount; i++) {
        cout << left << setw(12) << issuedItems[i].rollNo
             << setw(12) << issuedItems[i].itemID
             << setw(15) << issuedItems[i].issueDate << "\n";
    }
}

LibraryItem* Library::getCatalogItem(int i) const {
    if (i >= 0 && i < catalogSize) return catalog[i];
    return nullptr;
}
