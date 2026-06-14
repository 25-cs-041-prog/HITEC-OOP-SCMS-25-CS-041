
#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>
#include "../person/Student.h"
#include "Course.h"
using namespace std;

class Enrollment {
private:
    Student* student;          
    Course*  course;    
    string   enrollmentDate;
    string   grade;

public:
    Enrollment();
    Enrollment(Student* student, Course* course,
               const string& enrollmentDate);

    void displayEnrollment() const;

    Student* getStudent()        const { return student;        }
    Course*  getCourse()         const { return course;         }
    string   getEnrollmentDate() const { return enrollmentDate; }
    string   getGrade()          const { return grade;          }

    void setGrade(const string& g)          { grade          = g; }
    void setEnrollmentDate(const string& d) { enrollmentDate = d; }
};

#endif 
