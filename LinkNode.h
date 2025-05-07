//
// Created by jesus on 5/5/2025.
//

#ifndef LINKNODE_H
#define LINKNODE_H
#include "Currency.h"

struct LinkNode {
    LinkNode() {
        data = nullptr;
        next = nullptr;
    }
    LinkNode(Currency* newData) {
        data = newData;
        next = nullptr;
    }
    ~LinkNode() {}
    Currency *data;
    LinkNode *next;
};

#endif //LINKNODE_H
