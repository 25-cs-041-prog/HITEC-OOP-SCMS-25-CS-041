/**
 * @file Student.h
 * @brief Student class derived from Person (Single Inheritance)
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism,
 *               Arrays of Objects, Override of Pure Virtual Function
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

// Maximum number of courses a student can be enrolled in
const int MAX_STUDENT_COURSES = 10;

// ─────────────────────────────────────────────────────────────
// Student — Derived from Person (Single Inheritance)
// ─────────────────────────────────────────────────────────────
class Student : public Person {
private:
    string rollNo;
    int    semester;
    double gpa;
    string enrolledCourses[MAX_STUDENT_COURSES]; // array of course codes
    int    courseCount;

public:
    // Default constructor
    Student();

    // Parameterised constructor
    Student(const string& name, const string& cnic, int age,
            const string& contact, const string& rollNo,
            int semester, double gpa);

    // Override of pure virtual — enables runtime polymorphism
    void displayInfo() const override;

    // Calculates letter grade based on GPA
    string calculateGrade() const;

    // Enrol in a course (stores course code)
    void enrollCourse(const string& courseCode);

    // ── Getters ───────────────────────────────────────────────
    string getRollNo()     const { return rollNo;     }
    int    getSemester()   const { return semester;   }
    double getGPA()        const { return gpa;        }
    int    getCourseCount()const { return courseCount;}
    string getEnrolledCourse(int i) const;

    // ── Setters ───────────────────────────────────────────────
    void setRollNo(const string& r)  { rollNo   = r; }
    void setSemester(int s)          { semester = s; }
    void setGPA(double g)            { gpa      = g; }
};

#endif // STUDENT_H
