/**
 * @file HostelManager.cpp
 * @brief Implementation of HostelManager (multiple + virtual inheritance)
 * @author [Your Name] | Roll No: [XXXX]
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Multiple Inheritance, Virtual Inheritance, Composition,
 *               Override, Destructor
 */

#include "HostelManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ── Default Constructor ────────────────────────────────────────
HostelManager::HostelManager()
    : CampusEntity("HITEC Hostel"),
      Accommodation("HITEC Hostel"),
      Reportable("HITEC Hostel"),
      blockCount(0) {}

// ── Parameterised Constructor ──────────────────────────────────
HostelManager::HostelManager(const string& managerName)
    : CampusEntity(managerName),
      Accommodation(managerName),
      Reportable(managerName),
      blockCount(0) {}

// ── Destructor ─────────────────────────────────────────────────
// HostelBlocks are by value (composition), so they are automatically
// destroyed. We print a message to demonstrate destructor invocation.
HostelManager::~HostelManager() {
    cout << "[HostelManager] Destructor called for '"
         << entityName << "'. All blocks released.\n";
}

// ── addBlock() ────────────────────────────────────────────────
void HostelManager::addBlock(const string& blockName) {
    if (blockCount < MAX_BLOCKS) {
        blocks[blockCount++] = HostelBlock(blockName);
        cout << "[Hostel] Block '" << blockName << "' added.\n";
    } else {
        cout << "[Hostel] Maximum blocks reached.\n";
    }
}

// ── addRoomToBlock() ──────────────────────────────────────────
void HostelManager::addRoomToBlock(int blockIndex, int roomNumber,
                                   const string& type, int floor) {
    if (blockIndex >= 0 && blockIndex < blockCount) {
        blocks[blockIndex].addRoom(roomNumber, type, floor);
    } else {
        cout << "[Hostel] Invalid block index: " << blockIndex << "\n";
    }
}

// ── allocateRoom() — override from Accommodation ──────────────
void HostelManager::allocateRoom(Student* student) {
    for (int i = 0; i < blockCount; i++) {
        Room* room = blocks[i].findAvailableRoom();
        if (room) {
            room->addOccupant(student);
            cout << "[Hostel] " << student->getName()
                 << " allocated to Block " << blocks[i].getBlockName()
                 << ", Room " << room->getRoomNumber() << "\n";
            return;
        }
    }
    cout << "[Hostel] No available rooms for " << student->getName() << "\n";
}

// ── vacateRoom() — override from Accommodation ────────────────
void HostelManager::vacateRoom(const string& rollNo, int roomNumber) {
    for (int i = 0; i < blockCount; i++) {
        Room* room = blocks[i].findRoom(roomNumber);
        if (room) {
            if (room->removeOccupant(rollNo)) {
                cout << "[Hostel] Student " << rollNo
                     << " vacated Room " << roomNumber << "\n";
                return;
            }
        }
    }
    cout << "[Hostel] Student " << rollNo
         << " not found in Room " << roomNumber << "\n";
}

// ── generateReport() — override from Reportable ──────────────
void HostelManager::generateReport() const {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║       HOSTEL OCCUPANCY REPORT        ║\n";
    cout << "║  " << left << setw(36) << entityName << "║\n";
    cout << "╠══════════════════════════════════════╣\n";

    int totalRooms     = 0;
    int occupiedRooms  = 0;
    int totalStudents  = 0;

    for (int i = 0; i < blockCount; i++) {
        blocks[i].displayBlock();
        for (int j = 0; j < blocks[i].getRoomCount(); j++) {
            const Room& room = blocks[i].getRoom(j);
            totalRooms++;
            if (room.getOccupantCount() > 0) {
                occupiedRooms++;
                totalStudents += room.getOccupantCount();
            }
        }
    }

    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ Total Blocks   : " << left << setw(20) << blockCount   << "║\n";
    cout << "║ Total Rooms    : " << left << setw(20) << totalRooms   << "║\n";
    cout << "║ Occupied Rooms : " << left << setw(20) << occupiedRooms<< "║\n";
    cout << "║ Total Students : " << left << setw(20) << totalStudents<< "║\n";
    cout << "╚══════════════════════════════════════╝\n";
}
