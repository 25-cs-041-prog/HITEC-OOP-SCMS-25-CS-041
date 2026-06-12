/**
 * @file Reports.h
 * @brief Report generation functions for campus-wide reporting
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Reporting Functions, std::sort, std::find_if,
 *               Custom Comparators, Memory Management,
 *               File Output, Sorting and Searching
 */

#ifndef REPORTS_H
#define REPORTS_H

#include <string>
#include <algorithm>
#include "../person/Student.h"
#include "../person/Faculty.h"
#include "../library/Library.h"
#include "../finance/FeeRecord.h"
#include "../hostel/HostelManager.h"
using namespace std;

// ─────────────────────────────────────────────────────────────
// Reports — static class providing all reporting functions
// ─────────────────────────────────────────────────────────────
class Reports {
public:
    // ── Student Reports ───────────────────────────────────────

    // Sort and display students by GPA (descending) using std::sort
    static void sortStudentsByGPA(Student* students[], int count);

    // Display all students using polymorphism (Person base ptr)
    static void displayAllStudents(Student* students[], int count);

    // Find a student by roll number using std::find_if
    static Student* findStudentByRollNo(Student* students[], int count,
                                        const string& rollNo);

    // ── Library Reports ───────────────────────────────────────

    // Find overdue books (daysKept > 14) and report fines
    static void reportOverdueItems(Library& library);

    // Display full library catalog summary
    static void displayLibrarySummary(Library& library);

    // ── Finance Reports ───────────────────────────────────────

    // Display all fee records
    static void displayAllFeeRecords(FeeRecord records[], int count);

    // Find students with outstanding balance
    static void reportOutstandingBalances(FeeRecord records[], int count);

    // ── Hostel Reports ────────────────────────────────────────

    // Calls HostelManager's generateReport() via Reportable pointer
    static void displayHostelReport(HostelManager& hostelMgr);

    // ── Consolidated Campus Report ────────────────────────────

    // Prints a full campus state report to cout
    static void generateCampusReport(
        Student* students[], int studentCount,
        Faculty* faculty[],  int facultyCount,
        Library& library,
        FeeRecord feeRecords[], int feeCount,
        HostelManager& hostelMgr
    );

    // Saves the same report to a text file
    static void saveCampusReportToFile(
        const string& filename,
        Student* students[], int studentCount,
        Faculty* faculty[],  int facultyCount,
        Library& library
    );
};

#endif // REPORTS_H
