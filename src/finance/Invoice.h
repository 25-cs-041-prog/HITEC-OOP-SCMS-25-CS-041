
#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <iostream>
using namespace std;

class Invoice {
private:
    static int invoiceCounter;

    int     invoiceID;      
    string  date;
    string* items;           
    int     itemCount;
    int     itemCapacity;
    double  totalAmount;

public:
    Invoice(const string& date, int capacity = 10);
    Invoice(const Invoice& other);
    Invoice& operator=(const Invoice& other);

    ~Invoice();

    void addItem(const string& description, double amount);

    static int getInvoiceCount() { return invoiceCounter; }
    static void resetCounter()   { invoiceCounter = 0;    }
    friend ostream& operator<<(ostream& os, const Invoice& inv);

    int    getInvoiceID()   const { return invoiceID;   }
    string getDate()        const { return date;        }
    double getTotalAmount() const { return totalAmount; }
    int    getItemCount()   const { return itemCount;   }
};

#endif
