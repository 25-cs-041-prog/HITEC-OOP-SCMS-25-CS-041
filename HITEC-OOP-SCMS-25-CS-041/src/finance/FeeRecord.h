/**
 * @file FeeRecord.h
 * @brief FeeRecord class — tracks student fees with copy semantics
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Encapsulation, Copy Constructor (Deep Copy),
 *               Copy Assignment Operator, Operator Overloading (-=)
 */

#ifndef FEERECORD_H
#define FEERECORD_H

#include <string>
#include <iostream>
#include "../person/Student.h"
using namespace std;

// ─────────────────────────────────────────────────────────────
// FeeRecord — tracks all fees and payments for a student
// Demonstrates copy constructor and copy assignment operator
// ─────────────────────────────────────────────────────────────
class FeeRecord {
private:
    Student* studentRef;   // aggregation (not owned)
    double   semesterFee;
    double   hostelFee;
    double   libraryFine;
    double   totalPaid;
    double   balance;

    // Helper to recompute balance
    void recalculateBalance();

public:
    // Default constructor
    FeeRecord();

    // Parameterised constructor
    FeeRecord(Student* student, double semesterFee,
              double hostelFee = 0.0, double libraryFine = 0.0);

    // ── Copy Constructor (Deep Copy) ──────────────────────────
    FeeRecord(const FeeRecord& other);

    // ── Copy Assignment Operator ──────────────────────────────
    FeeRecord& operator=(const FeeRecord& other);

    // ── Destructor ────────────────────────────────────────────
    ~FeeRecord() = default; // student* not owned, so no delete

    // ── operator-= ────────────────────────────────────────────
    // Records a payment; updates totalPaid and balance
    FeeRecord& operator-=(double payment);

    void displayFeeRecord() const;
    void addLibraryFine(double fine);

    // ── Getters ───────────────────────────────────────────────
    Student* getStudent()     const { return studentRef; }
    double getSemesterFee()   const { return semesterFee;  }
    double getHostelFee()     const { return hostelFee;    }
    double getLibraryFine()   const { return libraryFine;  }
    double getTotalPaid()     const { return totalPaid;    }
    double getBalance()       const { return balance;      }

    // ── Setters ───────────────────────────────────────────────
    void setSemesterFee(double f) { semesterFee = f; recalculateBalance(); }
    void setHostelFee(double f)   { hostelFee   = f; recalculateBalance(); }
};

#endif // FEERECORD_H
