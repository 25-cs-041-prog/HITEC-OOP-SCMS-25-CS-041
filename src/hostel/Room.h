
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "../person/Student.h"
using namespace std;

const int MAX_OCCUPANTS = 3;

class Room {
private:
    int      roomNumber;
    string   type;     
    int      floor;
    Student* occupants[MAX_OCCUPANTS]; 
    int      occupantCount;
    int      maxOccupants;  

public:
    Room();
    Room(int roomNumber, const string& type, int floor);

    bool addOccupant(Student* student);
    bool removeOccupant(const string& rollNo);
    bool hasSpace() const { return occupantCount < maxOccupants; }

    void displayRoom() const;

    int    getRoomNumber()   const { return roomNumber;    }
    string getType()         const { return type;          }
    int    getFloor()        const { return floor;         }
    int    getOccupantCount()const { return occupantCount; }
    int    getMaxOccupants() const { return maxOccupants;  }
    Student* getOccupant(int i) const;

    void setRoomNumber(int n)      { roomNumber = n; }
    void setFloor(int f)           { floor      = f; }
};

#endif 
