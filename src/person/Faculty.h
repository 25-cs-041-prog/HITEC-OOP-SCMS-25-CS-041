/**
 * @file Faculty.h
 * @brief Faculty class derived from Person
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

const int MAX_FACULTY_COURSES = 10;

// ─────────────────────────────────────────────────────────────
// Faculty — Derived from Person
// ─────────────────────────────────────────────────────────────
class Faculty : public Person {
private:
    string employeeID;
    string department;
    string designation;
    string assignedCourses[MAX_FACULTY_COURSES];
    int    courseCount;

public:
    Faculty();
    Faculty(const string& name, const string& cnic, int age,
            const string& contact, const string& employeeID,
            const string& department, const string& designation);

    void displayInfo() const override;

    // Assign a course to this faculty member
    void assignCourse(const string& courseCode);

    // ── Getters ───────────────────────────────────────────────
    string getEmployeeID()  const { return employeeID;  }
    string getDepartment()  const { return department;  }
    string getDesignation() const { return designation; }
    int    getCourseCount() const { return courseCount; }
    string getAssignedCourse(int i) const;

    // ── Setters ───────────────────────────────────────────────
    void setEmployeeID(const string& id)  { employeeID  = id; }
    void setDepartment(const string& d)   { department  = d;  }
    void setDesignation(const string& d)  { designation = d;  }
};

#endif // FACULTY_H
