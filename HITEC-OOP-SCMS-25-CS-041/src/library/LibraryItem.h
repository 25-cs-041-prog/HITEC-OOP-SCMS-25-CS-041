/**
 * @file LibraryItem.h
 * @brief Abstract base class for all library items
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function,
 *               Encapsulation, Polymorphism
 */

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>
using namespace std;

// ─────────────────────────────────────────────────────────────
// LibraryItem — Abstract Base Class (interface-like design)
// Book and Journal inherit from this
// ─────────────────────────────────────────────────────────────
class LibraryItem {
protected:
    string itemID;
    string title;
    string author;
    int    publicationYear;
    bool   isCheckedOut;

public:
    LibraryItem(const string& itemID, const string& title,
                const string& author, int publicationYear);

    virtual ~LibraryItem() = default;

    // Pure virtual — each item type handles checkout differently
    virtual void checkout() = 0;

    // Pure virtual — display item-specific info
    virtual void displayInfo() const = 0;

    // Return item
    virtual void returnItem();

    // ── Getters ───────────────────────────────────────────────
    string getItemID()          const { return itemID;          }
    string getTitle()           const { return title;           }
    string getAuthor()          const { return author;          }
    int    getPublicationYear() const { return publicationYear; }
    bool   getIsCheckedOut()    const { return isCheckedOut;    }

    // ── Setters ───────────────────────────────────────────────
    void setTitle(const string& t)  { title  = t; }
    void setAuthor(const string& a) { author = a; }
};

#endif // LIBRARYITEM_H
