//
// Created by jesus on 5/5/2025.
//

#pragma once
#include "LinkNode.h"

const int LIST_STARTING_INDEX = 0;
const int INDEX_OUT_OF_BOUNDS = -1;

using std::string;

class SinglyLinkedList {
public:
    SinglyLinkedList() :count(0), start(nullptr), end(nullptr) {};
    ~SinglyLinkedList() { emptyList(); };
    void addCurrency(Currency* newCurrency, int index);
    Currency* removeCurrency(Currency* currency);
    Currency* removeCurrency(int index);
    int findCurrency(Currency* currency) const;
    Currency* getCurrency(int index) const;
    string stringifyList() const;
    int countCurrency() const { return count; };
    bool isListEmpty() const { return start == nullptr; };
    void emptyList();

private:
    int count;
    LinkNode* start;
    LinkNode* end;
};

//TODO: Ask the teacher if we are dealing with duplicate two nodes that point to same currency instance.


inline void SinglyLinkedList::addCurrency(Currency* newCurrency, int index) {
    // throw out of bound error if the new index is > count
    if (index > count) {
        throw std::invalid_argument("Out of bound index");
    }
    LinkNode* newNode = new LinkNode(newCurrency);
    count++;
    //This if statement was made to check if the list is Empty
    if (isListEmpty()) {
        start = end = newNode;
        return;
    }

    //This if statement is if the index is at the start of the list.
    if (index == LIST_STARTING_INDEX) {
        newNode->next = start;
        start = newNode;
        return;
    }

    if (index == count) {
        end->next = newNode;
        end = end->next;
        return;
    }

    LinkNode* current = start;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
//TODO: Is the input currency the same as the data within the nodes?
inline Currency* SinglyLinkedList::removeCurrency(Currency* currency) {
    LinkNode* prev = nullptr;
    LinkNode* current = start;
    Currency* res = nullptr;
    // simply return if the list is empty
    if (!count || !start)
        return nullptr;
    if (start->data && start->data->isEqual(*currency)) {
        res = current->data;
        // list become empty
        if (end == start)
            end = nullptr;
        start = start->next;
        delete current;
        count--;
        return res;
    }
    prev = current;
    current = current->next;
    while (current != nullptr) {
        if (current->data && current->data->isEqual(*currency)) {
            res = current->data;
            prev->next = current->next;
            if (end == current) {
                end = prev;
            }
            delete current;
            count--;
            return res;
        }
        prev = current;
        current = current->next;
    }
    // doesn't find the item in the list
    return res;
}

inline Currency* SinglyLinkedList::removeCurrency(int index) {
    LinkNode* current = start;
    LinkNode* prev = nullptr;
    Currency* res = nullptr;
    if (index >= count) {
        return res;
    }
    if (index == LIST_STARTING_INDEX) {
        res = current->data;
        // list become empty
        if (end == start)
            end = nullptr;
        start = start->next;
        delete current;
        count--;
        return res;
    }
    for (int i = 1; i <= index && current; i++) {
        prev = current;
        current = current->next;
    }

    if (current) {
        res = current->data;
        if (prev)
            prev->next = current->next;
        if (current == end) {
            end = prev;
        }
        delete current;
        count--;
    }

    return res;
}

inline int SinglyLinkedList::findCurrency(Currency* currency) const {
    int index = LIST_STARTING_INDEX;

    if (!currency)
        throw std::invalid_argument("NULL currency");
    if (!start || !count)
        return INDEX_OUT_OF_BOUNDS;
    if (start->data->isEqual(*currency)) {
        return index;
    }
    LinkNode* current = start->next;
    while (current) {
        index++;
        if (current->data->isEqual(*currency)) {
            return index;
        }
        current = current->next;
    }
    return INDEX_OUT_OF_BOUNDS;
}

inline Currency* SinglyLinkedList::getCurrency(int index) const {
    if (index == LIST_STARTING_INDEX) {
        return start->data;
    }

    if (index >= count) {
        throw std::invalid_argument("Out of bound index");
    }
    LinkNode* current = start;
    for (int i = 1; i <= index && current; i++) {
        current = current->next;
    }
    return current ? current->data : nullptr;
}


inline string SinglyLinkedList::stringifyList() const {
    if (isListEmpty()) {
        return "";
    }
    std::stringstream ss;
    LinkNode* current = start;
    while (current->next != nullptr) {
        ss << current->data->toString() << "\t";
        current = current->next;
    }
    ss << current->data->toString();
    return ss.str();
}

inline void SinglyLinkedList::emptyList() {
    LinkNode* current = start;
    LinkNode* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    count = 0;
    start = end = nullptr;
}

