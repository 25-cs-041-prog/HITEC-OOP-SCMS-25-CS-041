
#include "Reports.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Reports::sortStudentsByGPA(Student* students[], int count) {
    if (count == 0) {
        cout << "No students to sort.\n";
        return;
    }

    sort(students, students + count,
         [](const Student* a, const Student* b) {
             return a->getGPA() > b->getGPA(); 
         });

    Utils::printHeader("STUDENTS SORTED BY GPA");
    cout << left << setw(5)  << "#"
         << setw(20) << "Name"
         << setw(12) << "Roll No"
         << setw(8)  << "GPA"
         << setw(20) << "Grade" << "\n";
    Utils::printDivider('-', 65);

    for (int i = 0; i < count; i++) {
        cout << left << setw(5)  << (i + 1)
             << setw(20) << students[i]->getName()
             << setw(12) << students[i]->getRollNo()
             << setw(8)  << fixed << setprecision(2) << students[i]->getGPA()
             << setw(20) << students[i]->calculateGrade() << "\n";
    }
}

void Reports::displayAllStudents(Student* students[], int count) {
    Utils::printHeader("ALL STUDENTS");
    if (count == 0) {
        cout << "  No students registered.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        Person* p = students[i]; 
        p->displayInfo();  
    }
}

Student* Reports::findStudentByRollNo(Student* students[], int count,
                                       const string& rollNo) {
    Student** result = find_if(students, students + count,
        [&rollNo](const Student* s) {
            return s->getRollNo() == rollNo;
        });

    if (result != students + count) {
        return *result;
    }
    return nullptr;
}
void Reports::reportOverdueItems(Library& library) {
    Utils::printHeader("LIBRARY OVERDUE REPORT");
    cout << "  (Items checked out > 14 days are flagged)\n";
    library.displayIssuedItems();
}

void Reports::displayLibrarySummary(Library& library) {
    Utils::printHeader("LIBRARY SUMMARY");
    cout << "  Total items in catalog: " << library.getCatalogSize() << "\n";
    library.displayCatalog();
}

void Reports::displayAllFeeRecords(FeeRecord records[], int count) {
    Utils::printHeader("ALL FEE RECORDS");
    if (count == 0) {
        cout << "  No fee records.\n";
        return;
    }
    for (int i = 0; i < count; i++)
        records[i].displayFeeRecord();
}

void Reports::reportOutstandingBalances(FeeRecord records[], int count) {
    Utils::printHeader("OUTSTANDING BALANCES");
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (records[i].getBalance() > 0) {
            found = true;
            Student* s = records[i].getStudent();
            cout << "  " << (s ? s->getName() : "Unknown")
                 << " | Balance: Rs. " << fixed << setprecision(2)
                 << records[i].getBalance() << "\n";
        }
    }
    if (!found) cout << "  No outstanding balances.\n";
}

void Reports::displayHostelReport(HostelManager& hostelMgr) {
    Reportable* rep = &hostelMgr; 
    rep->generateReport();   
}

void Reports::generateCampusReport(
    Student* students[], int studentCount,
    Faculty* faculty[],  int facultyCount,
    Library& library,
    FeeRecord feeRecords[], int feeCount,
    HostelManager& hostelMgr)
{
    (void)faculty;
    Utils::printHeader("CONSOLIDATED CAMPUS REPORT");
    cout << "  Campus: HITEC University Taxila\n";
    cout << "  Course: CS-104L Object-Oriented Programming\n\n";

    cout << "  Students Registered : " << studentCount << "\n";
    cout << "  Faculty Registered  : " << facultyCount << "\n";
    cout << "  Library Items       : " << library.getCatalogSize() << "\n\n";

    if (studentCount > 0)
        sortStudentsByGPA(students, studentCount);

    double totalOutstanding = 0.0;
    for (int i = 0; i < feeCount; i++)
        totalOutstanding += feeRecords[i].getBalance();
    cout << "\n  Total Outstanding Fees: Rs. " << fixed
         << setprecision(2) << totalOutstanding << "\n";

    hostelMgr.generateReport();
}
void Reports::saveCampusReportToFile(
    const string& filename,
    Student* students[], int studentCount,
    Faculty* faculty[],  int facultyCount,
    Library& library)
{
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "[Reports] Could not open file: " << filename << "\n";
        return;
    }

    outFile << "============================================\n";
    outFile << "   HITEC UNIVERSITY TAXILA — CAMPUS REPORT\n";
    outFile << "============================================\n\n";

    outFile << "STUDENTS (" << studentCount << ")\n";
    outFile << string(40, '-') << "\n";
    for (int i = 0; i < studentCount; i++) {
        outFile << left << setw(5)  << (i + 1)
                << setw(20) << students[i]->getName()
                << setw(12) << students[i]->getRollNo()
                << "GPA: " << fixed << setprecision(2)
                << students[i]->getGPA() << "\n";
    }

    outFile << "\nFACULTY (" << facultyCount << ")\n";
    outFile << string(40, '-') << "\n";
    for (int i = 0; i < facultyCount; i++) {
        outFile << left << setw(5)  << (i + 1)
                << setw(20) << faculty[i]->getName()
                << setw(15) << faculty[i]->getDepartment()
                << faculty[i]->getDesignation() << "\n";
    }

    outFile << "\nLIBRARY CATALOG (" << library.getCatalogSize() << " items)\n";
    outFile << string(40, '-') << "\n";
    for (int i = 0; i < library.getCatalogSize(); i++) {
        LibraryItem* item = library.getCatalogItem(i);
        if (item) {
            outFile << left << setw(5)  << (i + 1)
                    << setw(30) << item->getTitle()
                    << item->getAuthor() << "\n";
        }
    }

    outFile.close();
    cout << "[Reports] Campus report saved to '" << filename << "'\n";
}
