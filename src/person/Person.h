/**
 * @file Person.h
 * @brief Abstract base class for all persons in the SCMS
 * @author Aimen Fatima | Roll No: 25-s-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function, Encapsulation,
 *               Access Specifiers (public/protected/private)
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

// ─────────────────────────────────────────────────────────────
// Person — Abstract Base Class
// Cannot be instantiated directly; forces derived classes to
// implement displayInfo() via pure virtual function.
// ─────────────────────────────────────────────────────────────
class Person {
protected:
    // Protected so derived classes can access directly
    string name;
    string cnic;
    int    age;
    string contact;

public:
    // Parameterised constructor
    Person(const string& name, const string& cnic,
           int age, const string& contact);

    // Virtual destructor ensures correct cleanup through base pointer
    virtual ~Person() = default;

    // ── Pure Virtual ──────────────────────────────────────────
    // Every derived class MUST override this (runtime polymorphism)
    virtual void displayInfo() const = 0;

    // ── Getters (Encapsulation) ───────────────────────────────
    string getName()    const { return name;    }
    string getCNIC()    const { return cnic;    }
    int    getAge()     const { return age;     }
    string getContact() const { return contact; }

    // ── Setters ───────────────────────────────────────────────
    void setName(const string& n)    { name    = n; }
    void setCNIC(const string& c)    { cnic    = c; }
    void setAge(int a)               { age     = a; }
    void setContact(const string& c) { contact = c; }
};

#endif // PERSON_H
