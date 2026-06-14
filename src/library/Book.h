
#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    string isbn;
    string genre;
    int    copiesAvailable;

public:
    Book(const string& itemID, const string& title, const string& author,
         int publicationYear, const string& isbn,
         const string& genre, int copiesAvailable);

    void checkout()     override;
    void displayInfo()  const override;
    void returnItem()   override;

    string toFileString() const;

    string getISBN()           const { return isbn;             }
    string getGenre()          const { return genre;            }
    int    getCopiesAvailable()const { return copiesAvailable;  }

    void setISBN(const string& i)  { isbn  = i; }
    void setGenre(const string& g) { genre = g; }
    void setCopiesAvailable(int c) { copiesAvailable = c; }
};

#endif 
