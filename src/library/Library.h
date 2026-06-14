
#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <fstream>
#include "Book.h"
#include "Journal.h"
#include "../utils/Exceptions.h"
using namespace std;

const int MAX_CATALOG    = 100;
const int MAX_ISSUED     = 50;
const int FINE_PER_DAY   = 10;

struct IssuedRecord {
    string rollNo;
    string itemID;
    string issueDate;
    int    daysIssued; 
};

class Library {
private:
    LibraryItem* catalog[MAX_CATALOG];
    int          catalogSize;
    IssuedRecord issuedItems[MAX_ISSUED];
    int          issuedCount;
    string       catalogFile;

public:
    explicit Library(const string& catalogFile = "data/library_catalog.txt");

    ~Library();
    void addItem(LibraryItem* item);
    void removeItem(const string& itemID);

    LibraryItem* searchByTitle(const string& title) const;
    LibraryItem* searchByID(const string& itemID) const;
    void issueItem(const string& rollNo, const string& itemID,
                   const string& date);

    void returnItem(const string& rollNo, const string& itemID,
                    int daysKept);

    void saveToFile()   const;
    void loadFromFile();
    void displayCatalog() const;
    void displayIssuedItems() const;

    int getCatalogSize() const { return catalogSize; }
    LibraryItem* getCatalogItem(int i) const;
};

#endif 
