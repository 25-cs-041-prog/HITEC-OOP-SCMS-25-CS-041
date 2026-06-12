/**
 * @file HostelBlock.cpp
 * @brief Implementation of HostelBlock (composition with Room)
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 */

#include "HostelBlock.h"
#include <iostream>
using namespace std;

HostelBlock::HostelBlock()
    : blockName("Block-A"), roomCount(0) {}

HostelBlock::HostelBlock(const string& blockName)
    : blockName(blockName), roomCount(0) {}

void HostelBlock::addRoom(int roomNumber, const string& type, int floor) {
    if (roomCount < MAX_ROOMS_PER_BLOCK) {
        rooms[roomCount++] = Room(roomNumber, type, floor);
    } else {
        cout << "[HostelBlock] " << blockName << " is full.\n";
    }
}

Room* HostelBlock::findAvailableRoom() {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].hasSpace())
            return &rooms[i];
    }
    return nullptr;
}

Room* HostelBlock::findRoom(int roomNumber) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getRoomNumber() == roomNumber)
            return &rooms[i];
    }
    return nullptr;
}

void HostelBlock::displayBlock() const {
    cout << "\n  ── Block: " << blockName
         << " (" << roomCount << " rooms) ──\n";
    for (int i = 0; i < roomCount; i++)
        rooms[i].displayRoom();
}
