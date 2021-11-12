//
// Created by xparh on 11/12/2021.
//

#include "Plantaza.h"

Plantaza &Plantaza::operator+=(Vocnjak &v) {
    plantation = new Node(v, plantation);
    return *this;
}

void Plantaza::operator()(int k) const{
    for (int i = 0; i <= 2; i++) {
        Vocnjak *max = plantation->orch;
        for (Node *curr = plantation; curr; curr = curr->next) {
            if (*max < *curr->orch)
                max = curr->orch;
        }
        cout << (i + 1) << ". " << max->getId() << ":" << max->getIncome() << endl;
        for (Node *curr = plantation; curr; curr = curr->next) (*curr->orch)++;
    }
}
