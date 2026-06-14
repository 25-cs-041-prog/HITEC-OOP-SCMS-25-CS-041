
#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include "Student.h"

class GradStudent : public Student {
private:
    string thesisTitle;
    string supervisorName;
    string researchArea;

public:
    GradStudent();

    GradStudent(const string& name, const string& cnic, int age,
                const string& contact, const string& rollNo,
                int semester, double gpa,
                const string& thesisTitle,
                const string& supervisorName,
                const string& researchArea);

    void displayInfo() const override;

    string getThesisTitle()    const { return thesisTitle;    }
    string getSupervisorName() const { return supervisorName; }
    string getResearchArea()   const { return researchArea;   }

    void setThesisTitle(const string& t)    { thesisTitle    = t; }
    void setSupervisorName(const string& s) { supervisorName = s; }
    void setResearchArea(const string& r)   { researchArea   = r; }
};

#endif 
