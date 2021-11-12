//
// Created by xparh on 11/12/2021.
//

#include "Vocnjak.h"

int Vocnjak::lastId = 0;

Vocnjak::Vocnjak(int i, int j) : r(i), c(j) {
    orchard = new Vocka **[i];
    for (int m = 0; m < i; m++) {
        orchard[m] = new Vocka *[j];
        for (int n = 0; n < j; n++) {
            orchard[m][n] = nullptr;
        }
    }
}

Vocnjak::Vocnjak(Vocnjak &v) {
    r = v.r;
    c = v.c;
    orchard = new Vocka **[r];
    for (int m = 0; m < r; m++) {
        orchard[m] = new Vocka *[c];
        for (int n = 0; n < c; n++) {
            orchard[m][n] = v.orchard[m][n] ? new Vocka(*v.orchard[m][n]) : nullptr;
        }
    }
}

Vocnjak::Vocnjak(Vocnjak &&v) {
    r = v.r;
    c = v.c;
    orchard = v.orchard;
    v.orchard = nullptr;
    v.r = 0;
    v.c = 0;
}

Vocnjak::~Vocnjak() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            delete orchard[i][j];
        }
        delete[] orchard[i];
    }
    delete[] orchard;
    orchard = nullptr;
}

void swap(Vocnjak &v1, Vocnjak &v2) {
    swap(v1.orchard, v2.orchard);
    swap(v1.r, v2.r);
    swap(v1.c, v2.c);
    swap(v1.id, v2.id);
}

Vocnjak &Vocnjak::operator=(Vocnjak v) {
    swap(v, *this);
    return *this;
}

Vocnjak &Vocnjak::operator+=(Vocka &v) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!orchard[i][j]) {
                orchard[i][j] = new Vocka(v);
                return *this;
            }
        }
    }
    return *this;
}

Vocnjak Vocnjak::operator++(int k) {
    Vocnjak v = *this;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (orchard[i][j]) {
                (*orchard[i][j])++;
                if (!orchard[i][j]->getRemAge()) {
                    orchard[i][j] = nullptr;
                }
            }
        }
    }
    return v;
}

double Vocnjak::getIncome() const {
    double inc = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (orchard[i][j])
                inc += orchard[i][j]->getProfit();
        }
    }
    return inc;
}

bool Vocnjak::operator<(const Vocnjak &v) const {
    return getIncome() < v.getIncome();
}

ostream &operator<<(ostream &os, const Vocnjak &v) {
    os << "V_" << v.getId() << ":" << v.getIncome() << endl;
    for (int i = 0; i < v.r; i++) {
        for (int j = 0; j < v.c; j++) {
            if (v.orchard[i][j])
                os << *v.orchard[i][j] << "\t";
            else
                os << "prazno_mesto\t";
        }
        os << endl;
    }
    return os;
}
