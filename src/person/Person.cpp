/**
 * @file Person.cpp
 * @brief Implementation of the Person abstract base class
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Abstract Class, Constructor Implementation
 */

#include "Person.h"

// Parameterised constructor — initialises all member fields
Person::Person(const string& name, const string& cnic,
               int age, const string& contact)
    : name(name), cnic(cnic), age(age), contact(contact) {}
