/**
 * @file Reports.cpp
 * @brief Implementation of all campus reporting functions
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: std::sort with custom comparator, std::find_if,
 *               Polymorphism via base pointer (Person*),
 *               File I/O for report output, Sorting & Searching
 */

#include "Reports.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

// ── sortStudentsByGPA() ───────────────────────────────────────
// Uses std::sort with a lambda comparator (descending GPA)
void Reports::sortStudentsByGPA(Student* students[], int count) {
    if (count == 0) {
        cout << "No students to sort.\n";
        return;
    }

    // std::sort with custom lambda comparator
    sort(students, students + count,
         [](const Student* a, const Student* b) {
             return a->getGPA() > b->getGPA(); // descending
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

// ── displayAllStudents() ──────────────────────────────────────
// Demonstrates runtime polymorphism: calls displayInfo() via Person*
void Reports::displayAllStudents(Student* students[], int count) {
    Utils::printHeader("ALL STUDENTS");
    if (count == 0) {
        cout << "  No students registered.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        Person* p = students[i]; // upcast to base pointer
        p->displayInfo();        // runtime polymorphic dispatch
    }
}

// ── findStudentByRollNo() ─────────────────────────────────────
// Uses std::find_if with a lambda predicate
Student* Reports::findStudentByRollNo(Student* students[], int count,
                                       const string& rollNo) {
    // Wrap raw array in a pointer range for std::find_if
    Student** result = find_if(students, students + count,
        [&rollNo](const Student* s) {
            return s->getRollNo() == rollNo;
        });

    if (result != students + count) {
        return *result;
    }
    return nullptr;
}

// ── reportOverdueItems() ──────────────────────────────────────
void Reports::reportOverdueItems(Library& library) {
    Utils::printHeader("LIBRARY OVERDUE REPORT");
    cout << "  (Items checked out > 14 days are flagged)\n";
    library.displayIssuedItems();
}

// ── displayLibrarySummary() ───────────────────────────────────
void Reports::displayLibrarySummary(Library& library) {
    Utils::printHeader("LIBRARY SUMMARY");
    cout << "  Total items in catalog: " << library.getCatalogSize() << "\n";
    library.displayCatalog();
}

// ── displayAllFeeRecords() ────────────────────────────────────
void Reports::displayAllFeeRecords(FeeRecord records[], int count) {
    Utils::printHeader("ALL FEE RECORDS");
    if (count == 0) {
        cout << "  No fee records.\n";
        return;
    }
    for (int i = 0; i < count; i++)
        records[i].displayFeeRecord();
}

// ── reportOutstandingBalances() ───────────────────────────────
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

// ── displayHostelReport() ─────────────────────────────────────
// Uses Reportable* pointer to demonstrate polymorphism
void Reports::displayHostelReport(HostelManager& hostelMgr) {
    Reportable* rep = &hostelMgr; // upcast to Reportable*
    rep->generateReport();        // polymorphic dispatch
}

// ── generateCampusReport() ────────────────────────────────────
void Reports::generateCampusReport(
    Student* students[], int studentCount,
    Faculty* faculty[],  int facultyCount,
    Library& library,
    FeeRecord feeRecords[], int feeCount,
    HostelManager& hostelMgr)
{
    (void)faculty; // reserved for future use
    Utils::printHeader("CONSOLIDATED CAMPUS REPORT");
    cout << "  Campus: HITEC University Taxila\n";
    cout << "  Course: CS-104L Object-Oriented Programming\n\n";

    // ── Students ───────────────────────────────────────────
    cout << "  Students Registered : " << studentCount << "\n";
    cout << "  Faculty Registered  : " << facultyCount << "\n";
    cout << "  Library Items       : " << library.getCatalogSize() << "\n\n";

    // Sort students by GPA for the report
    if (studentCount > 0)
        sortStudentsByGPA(students, studentCount);

    // Fee summary
    double totalOutstanding = 0.0;
    for (int i = 0; i < feeCount; i++)
        totalOutstanding += feeRecords[i].getBalance();
    cout << "\n  Total Outstanding Fees: Rs. " << fixed
         << setprecision(2) << totalOutstanding << "\n";

    // Hostel report
    hostelMgr.generateReport();
}

// ── saveCampusReportToFile() ──────────────────────────────────
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
