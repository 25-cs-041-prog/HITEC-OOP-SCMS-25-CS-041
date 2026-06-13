/**
 * @file GradStudent.h
 * @brief GradStudent class — multi-level inheritance (GradStudent:Student:Person)
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Multi-level Inheritance, Override, Encapsulation
 */

#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include "Student.h"

// ─────────────────────────────────────────────────────────────
// GradStudent — Level 3 of inheritance chain
// GradStudent → Student → Person  (multi-level inheritance)
// ─────────────────────────────────────────────────────────────
class GradStudent : public Student {
private:
    string thesisTitle;
    string supervisorName;
    string researchArea;

public:
    // Default constructor
    GradStudent();

    // Parameterised constructor
    GradStudent(const string& name, const string& cnic, int age,
                const string& contact, const string& rollNo,
                int semester, double gpa,
                const string& thesisTitle,
                const string& supervisorName,
                const string& researchArea);

    // Override displayInfo() — adds thesis/supervisor info
    void displayInfo() const override;

    // ── Getters ───────────────────────────────────────────────
    string getThesisTitle()    const { return thesisTitle;    }
    string getSupervisorName() const { return supervisorName; }
    string getResearchArea()   const { return researchArea;   }

    // ── Setters ───────────────────────────────────────────────
    void setThesisTitle(const string& t)    { thesisTitle    = t; }
    void setSupervisorName(const string& s) { supervisorName = s; }
    void setResearchArea(const string& r)   { researchArea   = r; }
};

#endif // GRADSTUDENT_H
