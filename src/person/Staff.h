/**
 * @file Staff.h
 * @brief Staff class derived from Person
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

// ─────────────────────────────────────────────────────────────
// Staff — Derived from Person
// ─────────────────────────────────────────────────────────────
class Staff : public Person {
private:
    string staffID;
    string role;
    double salary;

public:
    Staff();
    Staff(const string& name, const string& cnic, int age,
          const string& contact, const string& staffID,
          const string& role, double salary);

    void displayInfo() const override;

    // ── Getters ───────────────────────────────────────────────
    string getStaffID() const { return staffID; }
    string getRole()    const { return role;    }
    double getSalary()  const { return salary;  }

    // ── Setters ───────────────────────────────────────────────
    void setStaffID(const string& id) { staffID = id;  }
    void setRole(const string& r)     { role    = r;   }
    void setSalary(double s)          { salary  = s;   }
};

#endif // STAFF_H
