
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "../person/Faculty.h"
#include "../person/Student.h"
#include "../utils/Exceptions.h"
using namespace std;

const int MAX_WAITLIST = 20;

class Course {
private:
    string   courseCode;
    string   courseName;
    int      creditHours;
    Faculty* instructor;  
    int      maxCapacity;
    int      enrolledCount;
    Student* waitList[MAX_WAITLIST];
    int      waitListCount;

public:
    Course();
    Course(const string& courseCode, const string& courseName,
           int creditHours, Faculty* instructor, int maxCapacity);

    void enrollStudent(Student* student);
    void addToWaitList(Student* student);

    bool operator==(const Course& other) const;
    friend ostream& operator<<(ostream& os, const Course& course);
    Student** operator+(const Course& other) const;

    string   getCourseCode()    const { return courseCode;    }
    string   getCourseName()    const { return courseName;    }
    int      getCreditHours()   const { return creditHours;   }
    Faculty* getInstructor()    const { return instructor;    }
    int      getMaxCapacity()   const { return maxCapacity;   }
    int      getEnrolledCount() const { return enrolledCount; }
    int      getWaitListCount() const { return waitListCount; }
    Student* getWaitListEntry(int i) const;

    void setCourseCode(const string& c)  { courseCode  = c; }
    void setCourseName(const string& n)  { courseName  = n; }
    void setCreditHours(int h)           { creditHours = h; }
    void setInstructor(Faculty* f)       { instructor  = f; }
    void setMaxCapacity(int m)           { maxCapacity = m; }
};

#endif
