/**
 * @file HostelBlock.h
 * @brief HostelBlock — composed of Room objects (composition)
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Composition (owns Room objects), Arrays of Objects,
 *               Encapsulation
 */

#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H

#include <string>
#include "Room.h"
using namespace std;

const int MAX_ROOMS_PER_BLOCK = 20;

// ─────────────────────────────────────────────────────────────
// HostelBlock — composes an array of Room objects
// Rooms live and die with the HostelBlock (composition)
// ─────────────────────────────────────────────────────────────
class HostelBlock {
private:
    string blockName;
    Room   rooms[MAX_ROOMS_PER_BLOCK]; // composition — Room objects (not pointers)
    int    roomCount;

public:
    HostelBlock();
    explicit HostelBlock(const string& blockName);

    // Add a new room to this block
    void addRoom(int roomNumber, const string& type, int floor);

    // Find a room with available space
    Room* findAvailableRoom();

    // Find room by number
    Room* findRoom(int roomNumber);

    void displayBlock() const;

    // ── Getters ───────────────────────────────────────────────
    string getBlockName() const { return blockName; }
    int    getRoomCount() const { return roomCount; }
    Room&  getRoom(int i)       { return rooms[i];  }
    const Room& getRoom(int i) const { return rooms[i]; }
};

#endif // HOSTELBLOCK_H
