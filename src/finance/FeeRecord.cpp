
#include "FeeRecord.h"
#include <iostream>
#include <iomanip>
using namespace std;

void FeeRecord::recalculateBalance() {
    balance = (semesterFee + hostelFee + libraryFine) - totalPaid;
}

FeeRecord::FeeRecord()
    : studentRef(nullptr), semesterFee(0.0), hostelFee(0.0),
      libraryFine(0.0), totalPaid(0.0), balance(0.0) {}

FeeRecord::FeeRecord(Student* student, double semFee,
                     double hostFee, double libFine)
    : studentRef(student), semesterFee(semFee),
      hostelFee(hostFee), libraryFine(libFine),
      totalPaid(0.0) {
    recalculateBalance();
}

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

FeeRecord& FeeRecord::operator=(const FeeRecord& other) {
    if (this != &other) { 
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

void FeeRecord::addLibraryFine(double fine) {
    libraryFine += fine;
    recalculateBalance();
    cout << "[FeeRecord] Library fine of Rs. " << fine
         << " added. New balance: Rs. " << balance << "\n";
}

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
