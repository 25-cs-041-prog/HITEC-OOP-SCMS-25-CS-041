/**
 * @file FeeRecord.cpp
 * @brief Implementation of FeeRecord — copy semantics and operator-=
 * @author  Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Copy Constructor, Copy Assignment Operator,
 *               Operator Overloading (-=), Encapsulation
 */

#include "FeeRecord.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ── Helper ─────────────────────────────────────────────────────
void FeeRecord::recalculateBalance() {
    balance = (semesterFee + hostelFee + libraryFine) - totalPaid;
}

// ── Default Constructor ────────────────────────────────────────
FeeRecord::FeeRecord()
    : studentRef(nullptr), semesterFee(0.0), hostelFee(0.0),
      libraryFine(0.0), totalPaid(0.0), balance(0.0) {}

// ── Parameterised Constructor ──────────────────────────────────
FeeRecord::FeeRecord(Student* student, double semFee,
                     double hostFee, double libFine)
    : studentRef(student), semesterFee(semFee),
      hostelFee(hostFee), libraryFine(libFine),
      totalPaid(0.0) {
    recalculateBalance();
}

// ── Copy Constructor (Deep Copy) ──────────────────────────────
// Copies all numeric data; keeps the same student pointer (aggregation)
FeeRecord::FeeRecord(const FeeRecord& other)
    : studentRef(other.studentRef),
      semesterFee(other.semesterFee),
      hostelFee(other.hostelFee),
      libraryFine(other.libraryFine),
      totalPaid(other.totalPaid),
      balance(other.balance) {
    cout << "[FeeRecord] Copy constructor called for student: "
         << (studentRef ? studentRef->getRollNo() : "N/A") << "\n";
}

// ── Copy Assignment Operator ──────────────────────────────────
FeeRecord& FeeRecord::operator=(const FeeRecord& other) {
    if (this != &other) { // self-assignment guard
        studentRef  = other.studentRef;
        semesterFee = other.semesterFee;
        hostelFee   = other.hostelFee;
        libraryFine = other.libraryFine;
        totalPaid   = other.totalPaid;
        balance     = other.balance;
        cout << "[FeeRecord] Copy assignment operator called.\n";
    }
    return *this;
}

// ── operator-= ────────────────────────────────────────────────
// Records a payment: reduces balance, increases totalPaid
FeeRecord& FeeRecord::operator-=(double payment) {
    if (payment <= 0) {
        cout << "[FeeRecord] Payment must be positive.\n";
        return *this;
    }
    totalPaid += payment;
    recalculateBalance();
    cout << "[FeeRecord] Payment of Rs. " << fixed << setprecision(2)
         << payment << " recorded. Remaining balance: Rs. "
         << balance << "\n";
    return *this;
}

// ── addLibraryFine() ──────────────────────────────────────────
void FeeRecord::addLibraryFine(double fine) {
    libraryFine += fine;
    recalculateBalance();
    cout << "[FeeRecord] Library fine of Rs. " << fine
         << " added. New balance: Rs. " << balance << "\n";
}

// ── displayFeeRecord() ────────────────────────────────────────
void FeeRecord::displayFeeRecord() const {
    cout << "┌─────────────────────────────────────┐\n";
    cout << "│           FEE RECORD                │\n";
    cout << "├─────────────────────────────────────┤\n";
    if (studentRef) {
        cout << "│ Student   : " << left << setw(25)
             << studentRef->getName()    << "│\n";
        cout << "│ Roll No   : " << left << setw(25)
             << studentRef->getRollNo()  << "│\n";
    }
    cout << "│ Semester Fee : Rs. " << left << setw(18) << fixed
         << setprecision(2) << semesterFee << "│\n";
    cout << "│ Hostel Fee   : Rs. " << left << setw(18)
         << hostelFee   << "│\n";
    cout << "│ Library Fine : Rs. " << left << setw(18)
         << libraryFine << "│\n";
    cout << "│ Total Paid   : Rs. " << left << setw(18)
         << totalPaid   << "│\n";
    cout << "│ Balance      : Rs. " << left << setw(18)
         << balance     << "│\n";
    cout << "└─────────────────────────────────────┘\n";
}
