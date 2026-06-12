/**
 * @file Exceptions.h
 * @brief All custom exception classes for the SCMS system
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Exception Handling, Custom Exception Classes, Inheritance
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

// ─────────────────────────────────────────────────────────────
// Base application exception — all SCMS exceptions inherit this
// ─────────────────────────────────────────────────────────────
class SCMSException : public exception {
protected:
    string message;
public:
    explicit SCMSException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// ─────────────────────────────────────────────────────────────
// Thrown when a course enrollment exceeds maxCapacity
// ─────────────────────────────────────────────────────────────
class CapacityExceededException : public SCMSException {
private:
    int maxCapacity;
public:
    CapacityExceededException(const string& courseCode, int maxCap)
        : SCMSException("Enrollment failed: Course '" + courseCode +
                        "' has reached maximum capacity of " +
                        to_string(maxCap) + " students."),
          maxCapacity(maxCap) {}

    int getMaxCapacity() const { return maxCapacity; }
};

// ─────────────────────────────────────────────────────────────
// Thrown when a library item is returned overdue
// ─────────────────────────────────────────────────────────────
class OverdueException : public SCMSException {
private:
    double fineAmount;
public:
    OverdueException(const string& itemTitle, double fine)
        : SCMSException("Overdue item: '" + itemTitle +
                        "'. Fine amount: Rs. " + to_string(fine)),
          fineAmount(fine) {}

    double getFineAmount() const { return fineAmount; }
};

// ─────────────────────────────────────────────────────────────
// Thrown when a requested item is not found
// ─────────────────────────────────────────────────────────────
class ItemNotFoundException : public SCMSException {
public:
    explicit ItemNotFoundException(const string& itemName)
        : SCMSException("Item not found: '" + itemName + "'") {}
};

// ─────────────────────────────────────────────────────────────
// Thrown when invalid input is provided
// ─────────────────────────────────────────────────────────────
class InvalidInputException : public SCMSException {
public:
    explicit InvalidInputException(const string& detail)
        : SCMSException("Invalid input: " + detail) {}
};

#endif // EXCEPTIONS_H
