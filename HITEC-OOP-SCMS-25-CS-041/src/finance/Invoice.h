/**
 * @file Invoice.h
 * @brief Invoice class with static counter, deep copy, and destructor
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Static Data Member, Static Member Function,
 *               Deep Copy Constructor, Destructor,
 *               Friend Function (operator<<)
 */

#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <iostream>
using namespace std;

// ─────────────────────────────────────────────────────────────
// Invoice — auto-numbered; owns a dynamic array of item strings
// ─────────────────────────────────────────────────────────────
class Invoice {
private:
    // ── Static member shared across ALL Invoice instances ─────
    static int invoiceCounter;

    int     invoiceID;        // assigned from invoiceCounter
    string  date;
    string* items;            // dynamically allocated array of item strings
    int     itemCount;
    int     itemCapacity;
    double  totalAmount;

public:
    // Constructor — allocates items array dynamically
    Invoice(const string& date, int capacity = 10);

    // ── Deep Copy Constructor ─────────────────────────────────
    Invoice(const Invoice& other);

    // ── Copy Assignment Operator ──────────────────────────────
    Invoice& operator=(const Invoice& other);

    // ── Destructor ────────────────────────────────────────────
    // MUST delete[] items to avoid memory leak
    ~Invoice();

    // Add a line item and its cost
    void addItem(const string& description, double amount);

    // ── Static Member Function ────────────────────────────────
    // Access the counter without an Invoice instance
    static int getInvoiceCount() { return invoiceCounter; }
    static void resetCounter()   { invoiceCounter = 0;    }

    // ── Friend operator<< ─────────────────────────────────────
    friend ostream& operator<<(ostream& os, const Invoice& inv);

    // ── Getters ───────────────────────────────────────────────
    int    getInvoiceID()   const { return invoiceID;   }
    string getDate()        const { return date;        }
    double getTotalAmount() const { return totalAmount; }
    int    getItemCount()   const { return itemCount;   }
};

#endif // INVOICE_H
