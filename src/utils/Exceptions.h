
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class SCMSException : public exception {
protected:
    string message;
public:
    explicit SCMSException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

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

class ItemNotFoundException : public SCMSException {
public:
    explicit ItemNotFoundException(const string& itemName)
        : SCMSException("Item not found: '" + itemName + "'") {}
};

class InvalidInputException : public SCMSException {
public:
    explicit InvalidInputException(const string& detail)
        : SCMSException("Invalid input: " + detail) {}
};

#endif 
