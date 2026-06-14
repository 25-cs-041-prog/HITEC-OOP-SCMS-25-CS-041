
#include "HostelManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

HostelManager::HostelManager()
    : CampusEntity("HITEC Hostel"),
      Accommodation("HITEC Hostel"),
      Reportable("HITEC Hostel"),
      blockCount(0) {}

HostelManager::HostelManager(const string& managerName)
    : CampusEntity(managerName),
      Accommodation(managerName),
      Reportable(managerName),
      blockCount(0) {}

HostelManager::~HostelManager() {
    cout << "[HostelManager] Destructor called for '"
         << entityName << "'. All blocks released.\n";
}

void HostelManager::addBlock(const string& blockName) {
    if (blockCount < MAX_BLOCKS) {
        blocks[blockCount++] = HostelBlock(blockName);
        cout << "[Hostel] Block '" << blockName << "' added.\n";
    } else {
        cout << "[Hostel] Maximum blocks reached.\n";
    }
}

void HostelManager::addRoomToBlock(int blockIndex, int roomNumber,
                                   const string& type, int floor) {
    if (blockIndex >= 0 && blockIndex < blockCount) {
        blocks[blockIndex].addRoom(roomNumber, type, floor);
    } else {
        cout << "[Hostel] Invalid block index: " << blockIndex << "\n";
    }
}

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
