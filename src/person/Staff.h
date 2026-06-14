
#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

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

    string getStaffID() const { return staffID; }
    string getRole()    const { return role;    }
    double getSalary()  const { return salary;  }

    void setStaffID(const string& id) { staffID = id;  }
    void setRole(const string& r)     { role    = r;   }
    void setSalary(double s)          { salary  = s;   }
};

#endif 
