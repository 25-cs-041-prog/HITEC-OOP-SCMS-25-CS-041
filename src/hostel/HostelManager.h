
#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H

#include <string>
#include "HostelBlock.h"
using namespace std;

const int MAX_BLOCKS = 5;

class CampusEntity {
protected:
    string entityName;
public:
    explicit CampusEntity(const string& name = "HITEC Campus")
        : entityName(name) {}
    virtual ~CampusEntity() = default;
    string getEntityName() const { return entityName; }
};

class Accommodation : public virtual CampusEntity {
public:
    explicit Accommodation(const string& name = "Hostel")
        : CampusEntity(name) {}
    virtual ~Accommodation() = default;
    virtual void allocateRoom(Student* student) = 0;
    virtual void vacateRoom(const string& rollNo, int roomNumber) = 0;
};

class Reportable : public virtual CampusEntity {
public:
    explicit Reportable(const string& name = "Entity")
        : CampusEntity(name) {}
    virtual ~Reportable() = default;
    virtual void generateReport() const = 0;
};

class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock blocks[MAX_BLOCKS]; 
    int         blockCount;

public:
    HostelManager();
    explicit HostelManager(const string& managerName);

    ~HostelManager() override;
    void addBlock(const string& blockName);
    void addRoomToBlock(int blockIndex, int roomNumber,
                        const string& type, int floor);

    void allocateRoom(Student* student) override;
    void vacateRoom(const string& rollNo, int roomNumber) override;
    void generateReport() const override;

    int getBlockCount() const { return blockCount; }
    HostelBlock& getBlock(int i) { return blocks[i]; }
};

#endif 
