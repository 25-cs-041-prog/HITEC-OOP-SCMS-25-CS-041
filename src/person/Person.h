
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string cnic;
    int    age;
    string contact;

public:
    Person(const string& name, const string& cnic,
           int age, const string& contact);

    virtual ~Person() = default;
    virtual void displayInfo() const = 0;

    string getName()    const { return name;    }
    string getCNIC()    const { return cnic;    }
    int    getAge()     const { return age;     }
    string getContact() const { return contact; }

    void setName(const string& n)    { name    = n; }
    void setCNIC(const string& c)    { cnic    = c; }
    void setAge(int a)               { age     = a; }
    void setContact(const string& c) { contact = c; }
};

#endif 
