/**
 * @file Room.h
 * @brief Room class — holds student occupants (array of Student*)
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Encapsulation, Arrays of Objects,
 *               Aggregation (Student* not owned)
 */

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "../person/Student.h"
using namespace std;

// Maximum occupants depends on room type (triple = 3)
const int MAX_OCCUPANTS = 3;

// ─────────────────────────────────────────────────────────────
// Room — part of HostelBlock (composition)
// ─────────────────────────────────────────────────────────────
class Room {
private:
    int      roomNumber;
    string   type;           // "single", "double", "triple"
    int      floor;
    Student* occupants[MAX_OCCUPANTS]; // aggregation
    int      occupantCount;
    int      maxOccupants;   // derived from type

public:
    Room();
    Room(int roomNumber, const string& type, int floor);

    // Add a student to this room
    bool addOccupant(Student* student);

    // Remove a student from this room
    bool removeOccupant(const string& rollNo);

    // Check if room has space
    bool hasSpace() const { return occupantCount < maxOccupants; }

    void displayRoom() const;

    // ── Getters ───────────────────────────────────────────────
    int    getRoomNumber()   const { return roomNumber;    }
    string getType()         const { return type;          }
    int    getFloor()        const { return floor;         }
    int    getOccupantCount()const { return occupantCount; }
    int    getMaxOccupants() const { return maxOccupants;  }
    Student* getOccupant(int i) const;

    // ── Setters ───────────────────────────────────────────────
    void setRoomNumber(int n)      { roomNumber = n; }
    void setFloor(int f)           { floor      = f; }
};

#endif // ROOM_H
