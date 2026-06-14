
#include "Room.h"
#include <iostream>
#include <iomanip>
using namespace std;

Room::Room()
    : roomNumber(0), type("single"), floor(1),
      occupantCount(0), maxOccupants(1) {
    for (int i = 0; i < MAX_OCCUPANTS; i++) occupants[i] = nullptr;
}

Room::Room(int roomNumber, const string& type, int floor)
    : roomNumber(roomNumber), type(type), floor(floor),
      occupantCount(0) {
    for (int i = 0; i < MAX_OCCUPANTS; i++) occupants[i] = nullptr;
    if      (type == "single") maxOccupants = 1;
    else if (type == "double") maxOccupants = 2;
    else if (type == "triple") maxOccupants = 3;
    else                       maxOccupants = 1;
}

bool Room::addOccupant(Student* student) {
    if (!hasSpace()) {
        cout << "[Room " << roomNumber << "] Room is full.\n";
        return false;
    }
    occupants[occupantCount++] = student;
    cout << "[Room " << roomNumber << "] "
         << student->getName() << " allocated.\n";
    return true;
}

bool Room::removeOccupant(const string& rollNo) {
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i] && occupants[i]->getRollNo() == rollNo) {
            cout << "[Room " << roomNumber << "] "
                 << occupants[i]->getName() << " vacated.\n";
            
            for (int j = i; j < occupantCount - 1; j++)
                occupants[j] = occupants[j + 1];
            occupants[--occupantCount] = nullptr;
            return true;
        }
    }
    return false;
}

void Room::displayRoom() const {
    cout << "  Room " << roomNumber << " [" << type << ", Floor "
         << floor << "] " << occupantCount << "/" << maxOccupants << " occupied\n";
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i])
            cout << "    -> " << occupants[i]->getName()
                 << " (" << occupants[i]->getRollNo() << ")\n";
    }
}

Student* Room::getOccupant(int i) const {
    if (i >= 0 && i < occupantCount) return occupants[i];
    return nullptr;
}
