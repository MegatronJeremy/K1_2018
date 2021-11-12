//
// Created by xparh on 11/12/2021.
//

#include "Vocka.h"

ostream &operator<<(ostream &os, const Vocka &vocka) {
    return os << vocka.name << "(" << vocka.age << "/" << vocka.lTime << ")" << ":" << vocka.profit;
}

Vocka Vocka::operator++(int k) {
    Vocka v = *this;
    age++;
    return v;
}
