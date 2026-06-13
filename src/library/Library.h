/**
 * @file Library.h
 * @brief Library class — manages catalog, issues, file persistence
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Arrays of Pointers, File I/O (fstream),
 *               Custom Exceptions, Destructor, Search Functions,
 *               Polymorphism via LibraryItem*
 */

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
const int FINE_PER_DAY   = 10; // Rs. 10 per overdue day

// ─────────────────────────────────────────────────────────────
// Struct to track issued items (roll number + item ID pair)
// ─────────────────────────────────────────────────────────────
struct IssuedRecord {
    string rollNo;
    string itemID;
    string issueDate;
    int    daysIssued; // how many days since issue
};

// ─────────────────────────────────────────────────────────────
// Library — owns its catalog items (created with new)
// ─────────────────────────────────────────────────────────────
class Library {
private:
    LibraryItem* catalog[MAX_CATALOG]; // owns these via new/delete
    int          catalogSize;
    IssuedRecord issuedItems[MAX_ISSUED];
    int          issuedCount;
    string       catalogFile;

public:
    explicit Library(const string& catalogFile = "data/library_catalog.txt");

    // Destructor — frees all dynamically allocated LibraryItem*
    ~Library();

    // Add a new item to the catalog (takes ownership)
    void addItem(LibraryItem* item);

    // Remove item from catalog
    void removeItem(const string& itemID);

    // ── Search ────────────────────────────────────────────────
    // Returns pointer to the first item matching title, or nullptr
    LibraryItem* searchByTitle(const string& title) const;

    // Search by item ID
    LibraryItem* searchByID(const string& itemID) const;

    // ── Issue / Return ────────────────────────────────────────
    void issueItem(const string& rollNo, const string& itemID,
                   const string& date);

    // Returns item; throws OverdueException if overdue
    void returnItem(const string& rollNo, const string& itemID,
                    int daysKept);

    // ── File I/O ──────────────────────────────────────────────
    void saveToFile()   const;
    void loadFromFile();

    // ── Display ───────────────────────────────────────────────
    void displayCatalog() const;
    void displayIssuedItems() const;

    // ── Getters ───────────────────────────────────────────────
    int getCatalogSize() const { return catalogSize; }
    LibraryItem* getCatalogItem(int i) const;
};

#endif // LIBRARY_H
