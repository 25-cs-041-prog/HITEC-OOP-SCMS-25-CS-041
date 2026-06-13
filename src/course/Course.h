/**
 * @file Course.h
 * @brief Course class with operator overloading and encapsulation
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Encapsulation, Operator Overloading (==, <<, +),
 *               Friend Functions, Aggregation (Faculty*),
 *               Custom Exception, Arrays
 */

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "../person/Faculty.h"
#include "../person/Student.h"
#include "../utils/Exceptions.h"
using namespace std;

const int MAX_WAITLIST = 20;

// ─────────────────────────────────────────────────────────────
// Course — manages course data and student enrollment
// Aggregates Faculty* (does NOT own it)
// ─────────────────────────────────────────────────────────────
class Course {
private:
    string   courseCode;
    string   courseName;
    int      creditHours;
    Faculty* instructor;       // aggregation — not owned
    int      maxCapacity;
    int      enrolledCount;
    Student* waitList[MAX_WAITLIST]; // waiting list array
    int      waitListCount;

public:
    // Constructors
    Course();
    Course(const string& courseCode, const string& courseName,
           int creditHours, Faculty* instructor, int maxCapacity);

    // Enrol a student — throws CapacityExceededException if full
    void enrollStudent(Student* student);

    // Add student to waiting list
    void addToWaitList(Student* student);

    // ── Operator Overloading ──────────────────────────────────
    // == compares two courses by courseCode
    bool operator==(const Course& other) const;

    // << stream insertion — declared as friend for ostream access
    friend ostream& operator<<(ostream& os, const Course& course);

    // + merges two waiting lists into a new array (caller must delete[])
    Student** operator+(const Course& other) const;

    // ── Getters ───────────────────────────────────────────────
    string   getCourseCode()    const { return courseCode;    }
    string   getCourseName()    const { return courseName;    }
    int      getCreditHours()   const { return creditHours;   }
    Faculty* getInstructor()    const { return instructor;    }
    int      getMaxCapacity()   const { return maxCapacity;   }
    int      getEnrolledCount() const { return enrolledCount; }
    int      getWaitListCount() const { return waitListCount; }
    Student* getWaitListEntry(int i) const;

    // ── Setters ───────────────────────────────────────────────
    void setCourseCode(const string& c)  { courseCode  = c; }
    void setCourseName(const string& n)  { courseName  = n; }
    void setCreditHours(int h)           { creditHours = h; }
    void setInstructor(Faculty* f)       { instructor  = f; }
    void setMaxCapacity(int m)           { maxCapacity = m; }
};

#endif // COURSE_H
