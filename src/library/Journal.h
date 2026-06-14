
#ifndef JOURNAL_H
#define JOURNAL_H

#include "LibraryItem.h"

class Journal : public LibraryItem {
private:
    string issn;
    int    volume;
    int    issueNumber;

public:
    Journal(const string& itemID, const string& title, const string& author,
            int publicationYear, const string& issn,
            int volume, int issueNumber);

    void checkout()    override;
    void displayInfo() const override;
    string toFileString() const;

    string getISSN()       const { return issn;        }
    int    getVolume()     const { return volume;      }
    int    getIssueNumber()const { return issueNumber; }

    void setISSN(const string& i)  { issn        = i; }
    void setVolume(int v)          { volume      = v; }
    void setIssueNumber(int n)     { issueNumber = n; }
};

#endif 
