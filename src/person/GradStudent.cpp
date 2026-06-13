/**
 * @file GradStudent.cpp
 * @brief Implementation of GradStudent (multi-level inheritance)
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Multi-level Inheritance, Constructor Chaining, Override
 */

#include "GradStudent.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ── Default Constructor ────────────────────────────────────────
GradStudent::GradStudent()
    : Student(),
      thesisTitle("TBD"), supervisorName("TBD"), researchArea("TBD") {}

// ── Parameterised Constructor ──────────────────────────────────
// Chains all the way up: GradStudent → Student → Person
GradStudent::GradStudent(const string& name, const string& cnic, int age,
                         const string& contact, const string& rollNo,
                         int semester, double gpa,
                         const string& thesisTitle,
                         const string& supervisorName,
                         const string& researchArea)
    : Student(name, cnic, age, contact, rollNo, semester, gpa),
      thesisTitle(thesisTitle),
      supervisorName(supervisorName),
      researchArea(researchArea) {}

// ── displayInfo() ──────────────────────────────────────────────
void GradStudent::displayInfo() const {
    cout << "┌─────────────────────────────────┐\n";
    cout << "│      GRADUATE STUDENT RECORD    │\n";
    cout << "├─────────────────────────────────┤\n";
    cout << "│ Name       : " << left << setw(20) << name           << "│\n";
    cout << "│ Roll No    : " << left << setw(20) << getRollNo()    << "│\n";
    cout << "│ Semester   : " << left << setw(20) << getSemester()  << "│\n";
    cout << "│ GPA        : " << left << setw(20) << fixed << setprecision(2) << getGPA() << "│\n";
    cout << "│ Grade      : " << left << setw(20) << calculateGrade()<< "│\n";
    cout << "│ Thesis     : " << left << setw(20) << thesisTitle    << "│\n";
    cout << "│ Supervisor : " << left << setw(20) << supervisorName << "│\n";
    cout << "│ Research   : " << left << setw(20) << researchArea   << "│\n";
    cout << "│ Contact    : " << left << setw(20) << contact        << "│\n";
    cout << "└─────────────────────────────────┘\n";
}
