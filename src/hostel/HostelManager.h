/**
 * @file HostelManager.h
 * @brief HostelManager — multiple inheritance from Accommodation and Reportable
 * @author Aimen Fatima | Roll No: 25-cs-041
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date 2025
 *
 * OOP Concepts: Multiple Inheritance, Virtual Inheritance (diamond problem),
 *               Abstract Classes as Interfaces, Composition (HostelBlock),
 *               Destructor, Polymorphism
 *
 * Diamond Problem Explanation:
 *   If both Accommodation and Reportable inherited a common Base,
 *   HostelManager would have two copies of Base. Using 'virtual' inheritance
 *   ensures only ONE shared copy exists.
 *   Here we demonstrate this by having both abstract classes virtually
 *   inherit from a common 'CampusEntity' base.
 */

#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H

#include <string>
#include "HostelBlock.h"
using namespace std;

const int MAX_BLOCKS = 5;

// ─────────────────────────────────────────────────────────────
// CampusEntity — common base to create the diamond problem
// Both Accommodation and Reportable virtually inherit from it
// ─────────────────────────────────────────────────────────────
class CampusEntity {
protected:
    string entityName;
public:
    explicit CampusEntity(const string& name = "HITEC Campus")
        : entityName(name) {}
    virtual ~CampusEntity() = default;
    string getEntityName() const { return entityName; }
};

// ─────────────────────────────────────────────────────────────
// Accommodation — abstract interface (virtually inherits CampusEntity)
// ─────────────────────────────────────────────────────────────
class Accommodation : public virtual CampusEntity {
public:
    explicit Accommodation(const string& name = "Hostel")
        : CampusEntity(name) {}
    virtual ~Accommodation() = default;
    virtual void allocateRoom(Student* student) = 0;
    virtual void vacateRoom(const string& rollNo, int roomNumber) = 0;
};

// ─────────────────────────────────────────────────────────────
// Reportable — abstract interface (virtually inherits CampusEntity)
// ─────────────────────────────────────────────────────────────
class Reportable : public virtual CampusEntity {
public:
    explicit Reportable(const string& name = "Entity")
        : CampusEntity(name) {}
    virtual ~Reportable() = default;
    virtual void generateReport() const = 0;
};

// ─────────────────────────────────────────────────────────────
// HostelManager — Multiple Inheritance
//   Inherits from BOTH Accommodation and Reportable.
//   Because both use 'virtual' inheritance from CampusEntity,
//   there is only ONE CampusEntity sub-object (diamond resolved).
// ─────────────────────────────────────────────────────────────
class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock blocks[MAX_BLOCKS]; // composition — owns HostelBlock objects
    int         blockCount;

public:
    HostelManager();
    explicit HostelManager(const string& managerName);

    // ── Destructor ────────────────────────────────────────────
    ~HostelManager() override;

    // Add a new block
    void addBlock(const string& blockName);

    // Add room to a specific block
    void addRoomToBlock(int blockIndex, int roomNumber,
                        const string& type, int floor);

    // ── Overrides from Accommodation ─────────────────────────
    void allocateRoom(Student* student) override;
    void vacateRoom(const string& rollNo, int roomNumber) override;

    // ── Override from Reportable ──────────────────────────────
    void generateReport() const override;

    // ── Getters ───────────────────────────────────────────────
    int getBlockCount() const { return blockCount; }
    HostelBlock& getBlock(int i) { return blocks[i]; }
};

#endif // HOSTELMANAGER_H
