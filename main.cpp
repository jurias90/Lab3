#include "Queue.h"
#include "DrachmaCurrency.h"
using namespace std;

#define CURRENCY_ARRAY_SIZE 20

int main()
{
    Currency* currencyArray[CURRENCY_ARRAY_SIZE];
    SinglyLinkedList list;
    Stack myStack;
    Queue myQueue;
    Currency* inputCur;
    int retIndex;
    Currency* res;

    cout << "Welcome to our demostrations of Linked List, Stack, and Queue" << endl << endl;

    currencyArray[0] = new DrachmaCurrency(57.12);
    currencyArray[1] = new DrachmaCurrency(25.44);
    currencyArray[2] = new DrachmaCurrency(87.43);
    currencyArray[3] = new DrachmaCurrency(68.99);
    currencyArray[4] = new DrachmaCurrency(111.22);
    currencyArray[5] = new DrachmaCurrency(44.55);
    currencyArray[6] = new DrachmaCurrency(77.77);
    currencyArray[7] = new DrachmaCurrency(18.36);
    currencyArray[8] = new DrachmaCurrency(543.21);
    currencyArray[9] = new DrachmaCurrency(20.21);
    currencyArray[10] = new DrachmaCurrency(345.67);
    currencyArray[11] = new DrachmaCurrency(36.18);
    currencyArray[12] = new DrachmaCurrency(48.48);
    currencyArray[13] = new DrachmaCurrency(101.00);
    currencyArray[14] = new DrachmaCurrency(11.00);
    currencyArray[15] = new DrachmaCurrency(21.00);
    currencyArray[16] = new DrachmaCurrency(51.00);
    currencyArray[17] = new DrachmaCurrency(1.00);
    currencyArray[18] = new DrachmaCurrency(251.00);
    currencyArray[19] = new DrachmaCurrency(151.00);

    // Start Linked List tasks
    // A: insert the first 7 elements into the list in reverse order
    for (int i = 0; i < 7; i++) {
        list.addCurrency(currencyArray[i], 0);
    }

    try
    {
        // B: search for Dr 87.43
        inputCur = new DrachmaCurrency(87.43);
        retIndex = list.findCurrency(inputCur);
        delete inputCur;
        if (retIndex >= 0) {
            cout << "Found Dr 87.43 at index " << retIndex << endl;
            res = list.getCurrency(retIndex);
            if (res) {
                res->print();
                cout << endl;
            }
            else {
                cout << "ERR: The result currency is empty" << endl;
            }
        }
        else {
            cout << "Could not find Dr 87.43 from the list " << endl;
        }
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        // B: search for Dr 44.56
        inputCur = new DrachmaCurrency(44.56);
        retIndex = list.findCurrency(inputCur);
        delete inputCur;
        if (retIndex >= 0) {
            cout << "Found Dr 44.56 at index " << retIndex << endl;
            res = list.getCurrency(retIndex);
            if (res) {
                res->print();
                cout << endl;
            }
            else {
                cout << "ERR: The result currency is empty" << endl;
            }
        }
        else {
            cout << "Could not find Dr 44.56 from the list " << endl;
        }
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    cout << endl;

    // C: Remove the node containing Dr 111.22 followed by the node at index 2
    inputCur = new DrachmaCurrency(111.22);
    res = list.removeCurrency(inputCur);
    delete inputCur;
    if (res) {
        cout << "Successfully remove Dr 111.22 from the list" << endl;
    }
    else {
        cout << "Dr 111.22 isn't in the list" << endl;
    }
    res = list.removeCurrency(2);
    if (res) {
        cout << "Successfully remove node at index 2 of the list" << endl;
        res->print();
        cout << endl;
    }
    else {
        cout << "Failed to delete node at index 2 of the list" << endl;
        cout << "List count is " << list.countCurrency() << endl;
    }
    cout << endl;

    // D: Print the contents of the list
    cout << "Printing current data in the list..." << endl;
    cout << list.stringifyList() << endl << endl;

    // E: add the next four (4) objects (#9 thru 12)
    for (int i = 9; i <= 12; i++) {
        list.addCurrency(currencyArray[i], (i % 5));
    }

    // F: Remove two (2) objects at indexes (countCurrency % 6) and (countCurrency / 7)
    res = list.removeCurrency(list.countCurrency() % 6);
    if (res) {
        cout << "Successfully remove node at index " << list.countCurrency() % 6 << " of the list" << endl;
        res->print();
        cout << endl;
    }
    else {
        cout << "Failed to delete node at index " << list.countCurrency() % 6 << " of the list" << endl;
        cout << "List count is " << list.countCurrency() << endl;
    }
    cout << endl;

    res = list.removeCurrency(list.countCurrency() / 7);
    if (res) {
        cout << "Successfully remove node at index " << list.countCurrency() / 7 << " of the list" << endl;
        res->print();
        cout << endl;
    }
    else {
        cout << "Failed to delete node at index " << list.countCurrency() / 7 << " of the list" << endl;
        cout << "List count is " << list.countCurrency() << endl;
    }
    cout << endl;

    // G: Print the contents of the list.
    cout << "Printing current data in the list..." << endl;
    cout << list.stringifyList() << endl << endl;

    // Stack testing
    // A
    for (int i = 13; i < CURRENCY_ARRAY_SIZE; i++) {
        myStack.push(currencyArray[i]);
    }

    // B peek and print
    res = myStack.peek();
    if (res) {
        cout << "Data at top of the stack is: " << res->toString() << endl;
    }
    else {
        cout << "Failed to peek the stack" << endl;
    }
    cout << endl;

    // C: 3 pops
    for (int i = 0; i < 3; i++) {
        res = myStack.pop();
        if (res) {
            cout << "Poping: " << res->toString() << endl;
        }
        else {
            cout << "Failed to pop the stack" << endl;
        }
    }
    cout << endl;

    // D: print
    cout << "Printing current data in the stack (top at the end)..." << endl;
    cout << myStack.stringifyStack() << endl << endl;

    // E: push 5 more
    for (int i = 0; i < 5; i++) {
        myStack.push(currencyArray[i]);
    }

    // F: pop twice
    for (int i = 0; i < 2; i++) {
        res = myStack.pop();
        if (res) {
            cout << "Poping: " << res->toString() << endl;
        }
        else {
            cout << "Failed to pop the stack" << endl;
        }
    }
    cout << endl;

    // G: print
    cout << "Printing current data in the stack (top at the end)..." << endl;
    cout << myStack.stringifyStack() << endl << endl;

    // Queue test
    // A: Add 7 odd from index 5
    for (int i = 0; i < 7; i++) {
        myQueue.enqueue(currencyArray[5 + i * 2]);
    }

    // B: peek front and end
    res = myQueue.peekFront();
    if (res) {
        cout << "Data at front of the queue is: " << res->toString() << endl;
    }
    else {
        cout << "Failed to peek front of the queue" << endl;
    }
    cout << endl;

    res = myQueue.peekRear();
    if (res) {
        cout << "Data at end of the queue is: " << res->toString() << endl;
    }
    else {
        cout << "Failed to peek end of the queue" << endl;
    }
    cout << endl;

    // C: 2 dequeue
    for (int i = 0; i < 2; i++) {
        res = myQueue.dequeue();
        if (res) {
            cout << "Dequeue: " << res->toString() << endl;
        }
        else {
            cout << "Failed to dequeue" << endl;
        }
    }
    cout << endl;

    // D: print
    cout << "Printing current data in the queue..." << endl;
    cout << myQueue.stringifyQueue() << endl << endl;

    // E: 5 more from index 10
    for (int i = 0; i < 5; i++) {
        myQueue.enqueue(currencyArray[10 + i]);
    }

    // F: 3 dequeue
    for (int i = 0; i < 3; i++) {
        res = myQueue.dequeue();
        if (res) {
            cout << "Dequeue: " << res->toString() << endl;
        }
        else {
            cout << "Failed to dequeue" << endl;
        }
    }
    cout << endl;

    // G: print
    cout << "Printing current data in the queue..." << endl;
    cout << myQueue.stringifyQueue() << endl << endl;

    list.emptyList();
    myStack.emptyStack();
    myQueue.emptyQueue();

    for (int i = 0; i < CURRENCY_ARRAY_SIZE; i++) {
        delete currencyArray[i];
    }
    cout << "Thank you for trying our demo!" << endl;
    return 0;
}
