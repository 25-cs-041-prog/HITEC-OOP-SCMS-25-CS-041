# Smart Campus Management System (SCMS)

## Project Info
- Student: Aimen | Roll No: 25-cs-041 | Course: OOP (CS-104L) | HITEC University Taxila

## Project Description
The Smart Campus Management System (SCMS) is a console-based C++ application that
simulates the core operations of a university campus. It manages students, faculty,
staff, courses and enrollments, a library catalog with file persistence, student fee
records and invoices, hostel room allocation, and consolidated campus reporting.
The project was built from scratch using C++17, with a strong emphasis on applying
every major Object-Oriented Programming concept in a realistic, interconnected system.

## OOP Concepts Demonstrated

| # | Concept | Where Used |
|---|---------|------------|
| 1 | Classes & Objects | Every module (Person, Course, Library, FeeRecord, Room, etc.) |
| 2 | Encapsulation (getters/setters) | All classes use private/protected members with public accessors |
| 3 | Constructors (default, param, copy) | `Person`, `Course`, `FeeRecord`, `Invoice` |
| 4 | Destructors | `Library::~Library()`, `HostelManager::~HostelManager()`, `Invoice::~Invoice()` |
| 5 | Single Inheritance | `Student : Person`, `Faculty : Person`, `Staff : Person`, `Book : LibraryItem` |
| 6 | Multi-level Inheritance | `GradStudent : Student : Person` |
| 7 | Multiple Inheritance | `HostelManager : Accommodation, Reportable` |
| 8 | Virtual Inheritance | `Accommodation` and `Reportable` both `virtual` inherit `CampusEntity` (diamond resolved) |
| 9 | Abstract Classes & Pure Virtual | `Person`, `LibraryItem`, `Accommodation`, `Reportable` |
| 10 | Runtime Polymorphism | `displayInfo()` called via `Person*`; `generateReport()` via `Reportable*` |
| 11 | Operator Overloading | `Course::operator==`, `operator<<`, `operator+`; `FeeRecord::operator-=` |
| 12 | Friend Functions | `friend ostream& operator<<` in `Course` and `Invoice` |
| 13 | Static Members | `Invoice::invoiceCounter` (auto-incremented per invoice) |
| 14 | Copy Constructor (Deep Copy) | `FeeRecord(const FeeRecord&)` |
| 15 | Copy Constructor and Destructor | `Invoice(const Invoice&)` allocates new `string*` array; `~Invoice()` frees it |
| 16 | Search Functions | `Library::searchByTitle()`, `Library::searchByID()` |
| 17 | Array-based Collections | `Library::catalog[MAX_CATALOG]` (array of `LibraryItem*`) |
| 18 | Arrays of Objects | `Student::enrolledCourses[]`, `Room::occupants[]`, `HostelBlock::rooms[]`, etc. |
| 19 | Exception Handling | `CapacityExceededException`, `OverdueException`, `ItemNotFoundException` |
| 20 | File I/O (fstream) | `Library::saveToFile()` / `loadFromFile()` for catalog persistence |
| 21 | Reporting & Utilities | `Reports.h/.cpp`, `Utils.h/.cpp` (Module 6) |
| 22 | Memory Management | `new`/`delete` in `Library`, `HostelManager`, `Course::operator+`, `Invoice` |
| 23 | Sorting and Searching | `Reports::sortStudentsByGPA()` (`std::sort`), `findStudentByRollNo()` (`std::find_if`) |
| 24 | Composition | `HostelBlock` contains `Room[]` objects; `HostelManager` contains `HostelBlock[]` |
| 25 | Aggregation | `Course::instructor` (`Faculty*`), `Enrollment::student`/`course` |

## Modules

1. **Person Hierarchy (Module 1)** — Abstract `Person` base class with `Student`,
   `Faculty`, `Staff` derived classes, plus `GradStudent` for multi-level inheritance.
   Demonstrates abstract classes, pure virtual functions, and runtime polymorphism.

2. **Course & Enrollment (Module 2)** — `Course` and `Enrollment` classes manage
   course offerings and student registrations, with operator overloading (`==`, `<<`, `+`)
   and a custom `CapacityExceededException`.

3. **Library System (Module 3)** — `LibraryItem` abstract class with `Book` and
   `Journal` subclasses. The `Library` class manages an array-based catalog with
   file persistence (`fstream`) and a custom `OverdueException`.

4. **Fee & Finance Management (Module 4)** — `FeeRecord` (deep-copy semantics,
   `operator-=` for payments) and `Invoice` (static auto-incrementing counter,
   deep-copy constructor, and proper destructor).

5. **Hostel Management (Module 5)** — `Room` and `HostelBlock` (composition),
   and `HostelManager`, which uses **multiple inheritance** from `Accommodation`
   and `Reportable`, both of which **virtually inherit** a common `CampusEntity`
   base to resolve the diamond problem.

6. **Reporting & Utilities (Module 6)** — `Reports` and `Utils` classes provide
   sorting (`std::sort`), searching (`std::find_if`), and consolidated
   text-report generation (screen and file).

## How to Compile & Run
```bash
g++ -std=c++17 -Wall -Wextra src/person/*.cpp src/course/*.cpp src/library/*.cpp src/finance/*.cpp src/hostel/*.cpp src/utils/*.cpp src/main.cpp -o scms
./scms
```

## GitHub Repository
https://github.com/25-cs-041-prog/HITEC-OOP-SCMS-25-CS-041
