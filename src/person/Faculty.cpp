/**
 * @file Faculty.cpp
 * @brief Implementation of the Faculty class
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Constructor Chaining, Override
 */

#include "Faculty.h"
#include <iostream>
#include <iomanip>
using namespace std;

Faculty::Faculty()
    : Person("Unknown", "00000-0000000-0", 0, "N/A"),
      employeeID("F000"), department("CS"), designation("Lecturer"),
      courseCount(0) {}

Faculty::Faculty(const string& name, const string& cnic, int age,
                 const string& contact, const string& employeeID,
                 const string& department, const string& designation)
    : Person(name, cnic, age, contact),
      employeeID(employeeID), department(department),
      designation(designation), courseCount(0) {}

void Faculty::displayInfo() const {
    cout << "┌─────────────────────────────────┐\n";
    cout << "│         FACULTY RECORD          │\n";
    cout << "├─────────────────────────────────┤\n";
    cout << "│ Name        : " << left << setw(19) << name        << "│\n";
    cout << "│ Employee ID : " << left << setw(19) << employeeID  << "│\n";
    cout << "│ Department  : " << left << setw(19) << department  << "│\n";
    cout << "│ Designation : " << left << setw(19) << designation << "│\n";
    cout << "│ Contact     : " << left << setw(19) << contact     << "│\n";
    cout << "│ Courses     : " << left << setw(19) << courseCount << "│\n";
    cout << "└─────────────────────────────────┘\n";
}

void Faculty::assignCourse(const string& courseCode) {
    if (courseCount < MAX_FACULTY_COURSES) {
        assignedCourses[courseCount++] = courseCode;
    } else {
        cout << "[Warning] Faculty " << employeeID
             << " is already assigned maximum courses.\n";
    }
}

string Faculty::getAssignedCourse(int i) const {
    if (i >= 0 && i < courseCount)
        return assignedCourses[i];
    return "";
}
