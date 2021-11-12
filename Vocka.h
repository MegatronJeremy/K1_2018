//
// Created by xparh on 11/12/2021.
//

#ifndef K1_2018_VOCKA_H
#define K1_2018_VOCKA_H

#include <string>
#include <iostream>

using namespace std;

class Vocka {
public:
    Vocka(const string &name, double profit, int lTime) : name(name), profit(profit), lTime(lTime) {}

    double getProfit() const {
        return profit;
    }

    int getRemAge() const {
        return lTime - age;
    }

    friend ostream &operator<<(ostream &os, const Vocka &vocka);

    Vocka operator++(int k);

private:
    string name;
    double profit;
    int lTime, age = 0;
};


#endif //K1_2018_VOCKA_H
