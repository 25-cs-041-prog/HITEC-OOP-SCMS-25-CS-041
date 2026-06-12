/**
 * @file Course.cpp
 * @brief Implementation of the Course class
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Operator Overloading (==, <<, +), Friend Function,
 *               Custom Exception Handling, Array Management
 */

#include "Course.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ── Default Constructor ────────────────────────────────────────
Course::Course()
    : courseCode("CS000"), courseName("Unknown"), creditHours(3),
      instructor(nullptr), maxCapacity(30),
      enrolledCount(0), waitListCount(0) {
    for (int i = 0; i < MAX_WAITLIST; i++) waitList[i] = nullptr;
}

// ── Parameterised Constructor ──────────────────────────────────
Course::Course(const string& courseCode, const string& courseName,
               int creditHours, Faculty* instructor, int maxCapacity)
    : courseCode(courseCode), courseName(courseName),
      creditHours(creditHours), instructor(instructor),
      maxCapacity(maxCapacity), enrolledCount(0), waitListCount(0) {
    for (int i = 0; i < MAX_WAITLIST; i++) waitList[i] = nullptr;
}

// ── enrollStudent() ────────────────────────────────────────────
// Throws CapacityExceededException when course is full
void Course::enrollStudent(Student* student) {
    if (enrolledCount >= maxCapacity) {
        throw CapacityExceededException(courseCode, maxCapacity);
    }
    student->enrollCourse(courseCode);
    enrolledCount++;
}

// ── addToWaitList() ────────────────────────────────────────────
void Course::addToWaitList(Student* student) {
    if (waitListCount < MAX_WAITLIST) {
        waitList[waitListCount++] = student;
        cout << "[Info] " << student->getName()
             << " added to waitlist for " << courseCode << "\n";
    } else {
        cout << "[Warning] Waitlist for " << courseCode << " is also full.\n";
    }
}

// ── operator== ────────────────────────────────────────────────
// Two courses are equal if their course codes match
bool Course::operator==(const Course& other) const {
    return courseCode == other.courseCode;
}

// ── operator<< (friend) ───────────────────────────────────────
// Prints course details to any ostream (cout, file, etc.)
ostream& operator<<(ostream& os, const Course& course) {
    os << "┌─────────────────────────────────┐\n";
    os << "│          COURSE DETAILS         │\n";
    os << "├─────────────────────────────────┤\n";
    os << "│ Code     : " << left << setw(22) << course.courseCode  << "│\n";
    os << "│ Name     : " << left << setw(22) << course.courseName  << "│\n";
    os << "│ Credits  : " << left << setw(22) << course.creditHours << "│\n";
    os << "│ Capacity : " << left << setw(22) << course.maxCapacity << "│\n";
    os << "│ Enrolled : " << left << setw(22) << course.enrolledCount << "│\n";
    if (course.instructor != nullptr) {
        os << "│ Instructor: " << left << setw(21)
           << course.instructor->getName() << "│\n";
    }
    os << "└─────────────────────────────────┘\n";
    return os;
}

// ── operator+ ─────────────────────────────────────────────────
// Merges two waiting lists into a new dynamically allocated array.
// IMPORTANT: The caller is responsible for calling delete[] on the result.
Student** Course::operator+(const Course& other) const {
    int totalSize = waitListCount + other.waitListCount;
    if (totalSize == 0) return nullptr;

    // Dynamically allocate merged array
    Student** merged = new Student*[totalSize];
    for (int i = 0; i < waitListCount; i++)
        merged[i] = waitList[i];
    for (int i = 0; i < other.waitListCount; i++)
        merged[waitListCount + i] = other.waitList[i];

    return merged;
}

// ── getWaitListEntry() ────────────────────────────────────────
Student* Course::getWaitListEntry(int i) const {
    if (i >= 0 && i < waitListCount)
        return waitList[i];
    return nullptr;
}
