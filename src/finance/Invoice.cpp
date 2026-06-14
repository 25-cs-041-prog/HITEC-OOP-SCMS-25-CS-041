
#include "Invoice.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Invoice::invoiceCounter = 0;

Invoice::Invoice(const string& date, int capacity)
    : invoiceID(++invoiceCounter),  
      date(date), itemCount(0),
      itemCapacity(capacity > 0 ? capacity : 10),
      totalAmount(0.0) {
    items = new string[itemCapacity];
}

Invoice::Invoice(const Invoice& other)
    : invoiceID(++invoiceCounter),  
      date(other.date),
      itemCount(other.itemCount),
      itemCapacity(other.itemCapacity),
      totalAmount(other.totalAmount) {
    items = new string[itemCapacity];     
    for (int i = 0; i < itemCount; i++)
        items[i] = other.items[i];      
    cout << "[Invoice] Deep copy constructor called. New Invoice ID: "
         << invoiceID << "\n";
}

Invoice& Invoice::operator=(const Invoice& other) {
    if (this != &other) {
        delete[] items;      
        date         = other.date;
        itemCount    = other.itemCount;
        itemCapacity = other.itemCapacity;
        totalAmount  = other.totalAmount;
        items        = new string[itemCapacity];
        for (int i = 0; i < itemCount; i++)
            items[i] = other.items[i];
        cout << "[Invoice] Copy assignment called.\n";
    }
    return *this;
}

Invoice::~Invoice() {
    delete[] items;
    items = nullptr;
}

void Invoice::addItem(const string& description, double amount) {
    if (itemCount < itemCapacity) {
        items[itemCount++] = description + " - Rs. " +
                             to_string(static_cast<int>(amount));
        totalAmount += amount;
    } else {
        cout << "[Invoice] Item capacity reached. Cannot add more items.\n";
    }
}

ostream& operator<<(ostream& os, const Invoice& inv) {
    os << "╔══════════════════════════════════════╗\n";
    os << "║              INVOICE                 ║\n";
    os << "╠══════════════════════════════════════╣\n";
    os << "║ Invoice ID : " << left << setw(25) << inv.invoiceID << "║\n";
    os << "║ Date       : " << left << setw(25) << inv.date      << "║\n";
    os << "╠══════════════════════════════════════╣\n";
    os << "║ Items:                               ║\n";
    for (int i = 0; i < inv.itemCount; i++) {
        os << "║  " << left << setw(37) << inv.items[i] << "║\n";
    }
    os << "╠══════════════════════════════════════╣\n";
    os << "║ TOTAL : Rs. " << left << setw(26) << fixed
       << setprecision(2) << inv.totalAmount << "║\n";
    os << "╚══════════════════════════════════════╝\n";
    return os;
}
