//
// Created by jesus on 5/5/2025.
//

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "LinkNode.h"

const int LIST_STARTING_INDEX=0;
const int INDEX_OUT_OF_BOUNDS=-1;

using std::string;

class SinglyLinkedList {
public:
    SinglyLinkedList():count(0), start(nullptr), end(nullptr){};
    ~SinglyLinkedList(){emptyList();};
    void addCurrency(Currency* newCurrency, int index);
    Currency* removeCurrency(Currency* currency);
    Currency* removeCurrency(int index);
    int findCurrency(Currency* currency) const;
    Currency* getCurrency(int index) const;
    string stringifyList() const;
    int countCurrency() const{return count;};
    bool isListEmpty() const{return start==nullptr;};
    void emptyList();

private:
    int count;
    LinkNode *start ;
    LinkNode *end ;
};

//TODO: Ask the teacher if we are dealing with duplicate two nodes that point to same currency instance.


inline void SinglyLinkedList::addCurrency(Currency* newCurrency, int index) {
    LinkNode* newNode = new LinkNode(newCurrency);
    count++;
    //This if statement was made to check if the list is Empty
    if(isListEmpty()) {
        start = end = newNode;
        return;
    }

    //This if statement is if the index is at the start of the list.
    if(index == LIST_STARTING_INDEX) {
        newNode->next = start;
        start = newNode;
        return;
    }

    //TODO: WHat do i do if the index is greater than the list
    //This was my solution. Just adding it to the end of the list.
    if(index >= count) {
        end->next = newNode;
        end = end->next;
        return;
    }

    LinkNode* current = start;
    for(int i = 0; i < index-1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
//TODO: Is the input currency the same as the data within the nodes?
inline Currency* SinglyLinkedList::removeCurrency(Currency* currency) {
    LinkNode* prev = nullptr;
    LinkNode* current = start;
    if(start->data->isEqual(*currency)) {
        Currency* removed = new DrachmaCurrency(current->data);
        removed->print();
        start = start->next;
        delete current;
        return removed;
    }
    while(current != nullptr) {
        prev = current;
        current = current->next;
        if(current->data->isEqual(*currency)) {
            Currency* removed = new DrachmaCurrency(current->data);
            removed->print();
            std::cout <<"its here dufus" << std::endl;
            prev->next = current->next;
            if(end == current) {
                end = prev;
            }
            delete current;
            count--;
            return removed;
        }
    }
    std::cout << "It never touched the loop smh";
    return nullptr;
}
//TODO: Ask professor if he wants us to throw an exception if the index is out of bounds or return nullptr
//The message was already sent, just waiting on response.
inline Currency* SinglyLinkedList::removeCurrency(int index) {
    LinkNode* current = start;
    LinkNode* prev = nullptr;
    if(index == LIST_STARTING_INDEX) {
        Currency* removed = new DrachmaCurrency(current->data);
        removed->print();
        start = start->next;
        delete current;
        return removed;
    }
    for(int i = 1; i < index; i++) {
        prev=current;
        current = current->next;
    }
    Currency* removed = current->data;
    prev->next = current->next;
    if(current == end) {
        end = prev;
    }
    delete current;
    count--;
    return removed;
}
inline int SinglyLinkedList::findCurrency(Currency *currency) const {
    int index = LIST_STARTING_INDEX;
    if(start->data->isEqual(*currency)) {
        return index;
    }
    LinkNode* current = start;
    while(current != nullptr) {
        current = current->next;
        index++;
        if(current->data->isEqual(*currency)) {
            return index;
        }
    }
        return INDEX_OUT_OF_BOUNDS;
}

inline Currency *SinglyLinkedList::getCurrency(int index) const {
    if(index == LIST_STARTING_INDEX) {
        return start->data;
    }
    LinkNode* current = start;
    for(int i = 1; i < index; i++) {
        current = current->next;
    }
    return current->data;
}


inline string SinglyLinkedList::stringifyList() const {
    if(isListEmpty()) {
        return "";
    }
    std::stringstream ss;
    LinkNode* current = start;
    while(current->next != nullptr) {
        ss << current->data->toString() << "\t" ;
        current = current->next;
    }
    ss << current->data->toString();
    return ss.str();
}
inline void SinglyLinkedList::emptyList() {
    count = 0;
    LinkNode* current = start;
    while (current != nullptr) {
        LinkNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    start = end = nullptr;
}





#endif //SINGLYLINKEDLIST_H
