#include <iostream>
#include "DrachmaCurrency.h"
#include "SinglyLinkedList.h"
using namespace std;


int main()
{
    SinglyLinkedList list;
    list.addCurrency(new DrachmaCurrency(15.14),0);
    list.addCurrency(new DrachmaCurrency(14.14),1);
    cout << list.stringifyList() << endl;
    /*TODO: FIgure out what the professor wants us to do with this. SInce it returns a new currency
    Are we suppose to convert it into drachma here or somewhere in the linked list class.
    */
    DrachmaCurrency removed= list.removeCurrency(0);

    removed.print();
    cout << endl;
    cout << list.stringifyList();
}
