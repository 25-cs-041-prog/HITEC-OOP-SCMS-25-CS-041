
#ifndef REPORTS_H
#define REPORTS_H

#include <string>
#include <algorithm>
#include "../person/Student.h"
#include "../person/Faculty.h"
#include "../library/Library.h"
#include "../finance/FeeRecord.h"
#include "../hostel/HostelManager.h"
using namespace std;

class Reports {
public:
    static void sortStudentsByGPA(Student* students[], int count);
    static void displayAllStudents(Student* students[], int count);
    static Student* findStudentByRollNo(Student* students[], int count,
                                        const string& rollNo);
    static void reportOverdueItems(Library& library);
    static void displayLibrarySummary(Library& library);
    static void displayAllFeeRecords(FeeRecord records[], int count);
    static void reportOutstandingBalances(FeeRecord records[], int count);

    static void displayHostelReport(HostelManager& hostelMgr);

    static void generateCampusReport(
        Student* students[], int studentCount,
        Faculty* faculty[],  int facultyCount,
        Library& library,
        FeeRecord feeRecords[], int feeCount,
        HostelManager& hostelMgr
    );

    static void saveCampusReportToFile(
        const string& filename,
        Student* students[], int studentCount,
        Faculty* faculty[],  int facultyCount,
        Library& library
    );
};

#endif 
