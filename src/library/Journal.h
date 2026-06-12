/**
 * @file Journal.h
 * @brief Journal class derived from LibraryItem
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Override, Encapsulation
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include "LibraryItem.h"

// ─────────────────────────────────────────────────────────────
// Journal — Derived from LibraryItem
// ─────────────────────────────────────────────────────────────
class Journal : public LibraryItem {
private:
    string issn;
    int    volume;
    int    issueNumber;

public:
    Journal(const string& itemID, const string& title, const string& author,
            int publicationYear, const string& issn,
            int volume, int issueNumber);

    void checkout()    override;
    void displayInfo() const override;

    // Serialise to string for file I/O
    string toFileString() const;

    // ── Getters ───────────────────────────────────────────────
    string getISSN()       const { return issn;        }
    int    getVolume()     const { return volume;      }
    int    getIssueNumber()const { return issueNumber; }

    // ── Setters ───────────────────────────────────────────────
    void setISSN(const string& i)  { issn        = i; }
    void setVolume(int v)          { volume      = v; }
    void setIssueNumber(int n)     { issueNumber = n; }
};

#endif // JOURNAL_H
