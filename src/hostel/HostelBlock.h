
#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H

#include <string>
#include "Room.h"
using namespace std;

const int MAX_ROOMS_PER_BLOCK = 20;

class HostelBlock {
private:
    string blockName;
    Room   rooms[MAX_ROOMS_PER_BLOCK]; 
    int    roomCount;

public:
    HostelBlock();
    explicit HostelBlock(const string& blockName);

    void addRoom(int roomNumber, const string& type, int floor);
    Room* findAvailableRoom();
    Room* findRoom(int roomNumber);

    void displayBlock() const;

    string getBlockName() const { return blockName; }
    int    getRoomCount() const { return roomCount; }
    Room&  getRoom(int i)       { return rooms[i];  }
    const Room& getRoom(int i) const { return rooms[i]; }
};

#endif 
