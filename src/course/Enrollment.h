/**
 * @file Enrollment.h
 * @brief Enrollment class — links Student and Course
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Encapsulation, Aggregation (Student*, Course*)
 */

#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>
#include "../person/Student.h"
#include "Course.h"
using namespace std;

// ─────────────────────────────────────────────────────────────
// Enrollment — records a student's enrolment in a course
// Aggregates both Student* and Course* (does NOT own them)
// ─────────────────────────────────────────────────────────────
class Enrollment {
private:
    Student* student;          // aggregation
    Course*  course;           // aggregation
    string   enrollmentDate;
    string   grade;

public:
    Enrollment();
    Enrollment(Student* student, Course* course,
               const string& enrollmentDate);

    void displayEnrollment() const;

    // ── Getters ───────────────────────────────────────────────
    Student* getStudent()        const { return student;        }
    Course*  getCourse()         const { return course;         }
    string   getEnrollmentDate() const { return enrollmentDate; }
    string   getGrade()          const { return grade;          }

    // ── Setters ───────────────────────────────────────────────
    void setGrade(const string& g)          { grade          = g; }
    void setEnrollmentDate(const string& d) { enrollmentDate = d; }
};

#endif // ENROLLMENT_H
