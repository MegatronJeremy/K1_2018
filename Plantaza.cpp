//
// Created by xparh on 11/12/2021.
//

#include "Plantaza.h"

Plantaza &Plantaza::operator+=(Vocnjak &v) {
    first = new Node(v, first);
    return *this;
}

void Plantaza::operator()(int k) const{
    for (int i = 0; i < k; i++) {
        int maxId = 0;
        double maxI = 0;
        for (Node *curr = first; curr; curr = curr->next) {
            Vocnjak v = *curr->orch;
            for (int j = 0; j < i; j++, v++);
            if (v.getIncome() > maxI)
                maxI = v.getIncome(), maxId = curr->orch->getId();
        }
        cout << (i + 1) << ". " << maxId << ":" << maxI << endl;
    }
}

Plantaza::~Plantaza() {
    while (first) {
        Node *old = first;
        first = first->next;
        delete old;
    }
}
