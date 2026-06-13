/**
 * @file Book.h
 * @brief Book class derived from LibraryItem
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Override, Encapsulation
 */

#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

// ─────────────────────────────────────────────────────────────
// Book — Derived from LibraryItem
// ─────────────────────────────────────────────────────────────
class Book : public LibraryItem {
private:
    string isbn;
    string genre;
    int    copiesAvailable;

public:
    Book(const string& itemID, const string& title, const string& author,
         int publicationYear, const string& isbn,
         const string& genre, int copiesAvailable);

    void checkout()     override;
    void displayInfo()  const override;
    void returnItem()   override;

    // Serialise to string for file I/O
    string toFileString() const;

    // ── Getters ───────────────────────────────────────────────
    string getISBN()           const { return isbn;             }
    string getGenre()          const { return genre;            }
    int    getCopiesAvailable()const { return copiesAvailable;  }

    // ── Setters ───────────────────────────────────────────────
    void setISBN(const string& i)  { isbn  = i; }
    void setGenre(const string& g) { genre = g; }
    void setCopiesAvailable(int c) { copiesAvailable = c; }
};

#endif // BOOK_H
