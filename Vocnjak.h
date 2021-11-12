//
// Created by xparh on 11/12/2021.
//

#ifndef K1_2018_VOCNJAK_H
#define K1_2018_VOCNJAK_H

#include "Vocka.h"

class Vocnjak {
public:
    Vocnjak &operator=(Vocnjak v);

    Vocnjak &operator+=(Vocka &v);

    Vocnjak operator++(int k);

    double getIncome() const;

    bool operator<(const Vocnjak &v) const;

    friend ostream &operator<<(ostream &os, const Vocnjak &v);

    Vocnjak(int i, int j);

    Vocnjak(Vocnjak &v);

    Vocnjak(Vocnjak &&v);

    ~Vocnjak();

    int getId() const {
        return id;
    }

private:
    static int lastId;
    int id = ++lastId;
    int r, c;
    Vocka ***orchard;

    friend void swap(Vocnjak &v1, Vocnjak &v2);
};


#endif //K1_2018_VOCNJAK_H
