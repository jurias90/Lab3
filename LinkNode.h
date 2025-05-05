//
// Created by jesus on 5/5/2025.
//

#ifndef LINKNODE_H
#define LINKNODE_H
#include "Currency.h"

struct LinkNode {
    ~LinkNode() {
        delete data;
    };
    Currency *data;
    LinkNode *next;
};

#endif //LINKNODE_H
