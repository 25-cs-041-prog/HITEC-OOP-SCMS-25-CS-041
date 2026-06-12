/**
 * @file Student.cpp
 * @brief Implementation of the Student class
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Constructor Chaining,
 *               Runtime Polymorphism, Array Management
 */

#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ── Default Constructor ────────────────────────────────────────
Student::Student()
    : Person("Unknown", "00000-0000000-0", 0, "N/A"),
      rollNo("XXXX"), semester(1), gpa(0.0), courseCount(0) {}

// ── Parameterised Constructor ──────────────────────────────────
Student::Student(const string& name, const string& cnic, int age,
                 const string& contact, const string& rollNo,
                 int semester, double gpa)
    : Person(name, cnic, age, contact),
      rollNo(rollNo), semester(semester), gpa(gpa), courseCount(0) {}

// ── displayInfo() — overrides Person's pure virtual ───────────
void Student::displayInfo() const {
    cout << "┌─────────────────────────────────┐\n";
    cout << "│         STUDENT RECORD          │\n";
    cout << "├─────────────────────────────────┤\n";
    cout << "│ Name     : " << left << setw(22) << name     << "│\n";
    cout << "│ Roll No  : " << left << setw(22) << rollNo   << "│\n";
    cout << "│ Semester : " << left << setw(22) << semester << "│\n";
    cout << "│ GPA      : " << left << setw(22) << fixed << setprecision(2) << gpa << "│\n";
    cout << "│ Grade    : " << left << setw(22) << calculateGrade() << "│\n";
    cout << "│ CNIC     : " << left << setw(22) << cnic     << "│\n";
    cout << "│ Contact  : " << left << setw(22) << contact  << "│\n";
    cout << "└─────────────────────────────────┘\n";
}

// ── calculateGrade() — returns letter grade based on GPA ──────
string Student::calculateGrade() const {
    if      (gpa >= 3.7) return "A  (Distinction)";
    else if (gpa >= 3.3) return "A- (Excellent)";
    else if (gpa >= 3.0) return "B+ (Very Good)";
    else if (gpa >= 2.7) return "B  (Good)";
    else if (gpa >= 2.3) return "B- (Above Average)";
    else if (gpa >= 2.0) return "C  (Average)";
    else if (gpa >= 1.0) return "D  (Below Average)";
    else                 return "F  (Fail)";
}

// ── enrollCourse() — adds a course code to the array ──────────
void Student::enrollCourse(const string& courseCode) {
    if (courseCount < MAX_STUDENT_COURSES) {
        enrolledCourses[courseCount++] = courseCode;
    } else {
        cout << "[Warning] Student " << rollNo
             << " cannot enroll in more than "
             << MAX_STUDENT_COURSES << " courses.\n";
    }
}

// ── getEnrolledCourse() — safe indexed access ─────────────────
string Student::getEnrolledCourse(int i) const {
    if (i >= 0 && i < courseCount)
        return enrolledCourses[i];
    return "";
}
