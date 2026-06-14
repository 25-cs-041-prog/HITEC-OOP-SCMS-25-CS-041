
#include "Staff.h"
#include <iostream>
#include <iomanip>
using namespace std;

Staff::Staff()
    : Person("Unknown", "00000-0000000-0", 0, "N/A"),
      staffID("S000"), role("Support"), salary(0.0) {}

Staff::Staff(const string& name, const string& cnic, int age,
             const string& contact, const string& staffID,
             const string& role, double salary)
    : Person(name, cnic, age, contact),
      staffID(staffID), role(role), salary(salary) {}

void Staff::displayInfo() const {
    cout << "┌─────────────────────────────────┐\n";
    cout << "│          STAFF RECORD           │\n";
    cout << "├─────────────────────────────────┤\n";
    cout << "│ Name     : " << left << setw(22) << name    << "│\n";
    cout << "│ Staff ID : " << left << setw(22) << staffID << "│\n";
    cout << "│ Role     : " << left << setw(22) << role    << "│\n";
    cout << "│ Salary   : Rs. " << left << setw(18) << fixed
         << setprecision(2) << salary                      << "│\n";
    cout << "│ Contact  : " << left << setw(22) << contact << "│\n";
    cout << "└─────────────────────────────────┘\n";
}
