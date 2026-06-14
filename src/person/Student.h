
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

const int MAX_STUDENT_COURSES = 10;

class Student : public Person {
private:
    string rollNo;
    int    semester;
    double gpa;
    string enrolledCourses[MAX_STUDENT_COURSES]; 
    int    courseCount;

public:
    Student();

    Student(const string& name, const string& cnic, int age,
            const string& contact, const string& rollNo,
            int semester, double gpa);

    void displayInfo() const override;
    string calculateGrade() const;
    void enrollCourse(const string& courseCode);

    string getRollNo()     const { return rollNo;     }
    int    getSemester()   const { return semester;   }
    double getGPA()        const { return gpa;        }
    int    getCourseCount()const { return courseCount;}
    string getEnrolledCourse(int i) const;

    void setRollNo(const string& r)  { rollNo   = r; }
    void setSemester(int s)          { semester = s; }
    void setGPA(double g)            { gpa      = g; }
};

#endif 
