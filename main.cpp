#include <iostream>
#include "DrachmaCurrency.h"
#include "SinglyLinkedList.h"
using namespace std;


int main()
{
    SinglyLinkedList list;
    list.addCurrency(new DrachmaCurrency(15.14),0);
    list.addCurrency(new DrachmaCurrency(14.14),1);
    cout << list.stringifyList();
    DrachmaCurrency *removed = list.removeCurrency(0);
    removed.print();
    cout << list.stringifyList();
}
