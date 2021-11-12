//
// Created by xparh on 11/12/2021.
//

#ifndef K1_2018_PLANTAZA_H
#define K1_2018_PLANTAZA_H

#include "Vocnjak.h"

class Plantaza {
public:
    Plantaza() = default;

    Plantaza(const Plantaza &) = delete;

    ~Plantaza();

    Plantaza &operator=(const Plantaza &) = delete;

    Plantaza &operator+=(Vocnjak &v);

    void operator()(int k) const;

private:
    struct Node {
        Vocnjak *orch;
        Node *next;

        Node(Vocnjak &v, Node *p = nullptr) : orch(&v), next(p) {}
    };

    Node *first = nullptr;
};


#endif //K1_2018_PLANTAZA_H
