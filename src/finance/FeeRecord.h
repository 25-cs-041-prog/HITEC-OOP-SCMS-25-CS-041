
#ifndef FEERECORD_H
#define FEERECORD_H

#include <string>
#include <iostream>
#include "../person/Student.h"
using namespace std;

class FeeRecord {
private:
    Student* studentRef;  
    double   semesterFee;
    double   hostelFee;
    double   libraryFine;
    double   totalPaid;
    double   balance;

    void recalculateBalance();

public:
    FeeRecord();

    FeeRecord(Student* student, double semesterFee,
              double hostelFee = 0.0, double libraryFine = 0.0);

    FeeRecord(const FeeRecord& other);
    FeeRecord& operator=(const FeeRecord& other);

    ~FeeRecord() = default; 

    FeeRecord& operator-=(double payment);

    void displayFeeRecord() const;
    void addLibraryFine(double fine);

    Student* getStudent()     const { return studentRef; }
    double getSemesterFee()   const { return semesterFee;  }
    double getHostelFee()     const { return hostelFee;    }
    double getLibraryFine()   const { return libraryFine;  }
    double getTotalPaid()     const { return totalPaid;    }
    double getBalance()       const { return balance;      }

    void setSemesterFee(double f) { semesterFee = f; recalculateBalance(); }
    void setHostelFee(double f)   { hostelFee   = f; recalculateBalance(); }
};

#endif
