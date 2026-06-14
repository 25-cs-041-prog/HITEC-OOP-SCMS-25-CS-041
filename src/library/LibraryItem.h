
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string itemID;
    string title;
    string author;
    int    publicationYear;
    bool   isCheckedOut;

public:
    LibraryItem(const string& itemID, const string& title,
                const string& author, int publicationYear);

    virtual ~LibraryItem() = default;
    virtual void checkout() = 0;
    virtual void displayInfo() const = 0;
    virtual void returnItem();

    string getItemID()          const { return itemID;          }
    string getTitle()           const { return title;           }
    string getAuthor()          const { return author;          }
    int    getPublicationYear() const { return publicationYear; }
    bool   getIsCheckedOut()    const { return isCheckedOut;    }

    void setTitle(const string& t)  { title  = t; }
    void setAuthor(const string& a) { author = a; }
};

#endif 
