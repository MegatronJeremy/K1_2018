#include <iostream>

#include "Plantaza.h"

int main() {
    Vocka v1("Jabuka", 10, 4);
    Vocka v2("Kruska", 22, 3);
    Vocka v3("Visnja", 25, 2);
    Vocnjak voc(2, 2);
    voc += v1;
    Vocnjak vocCpy(voc);
    vocCpy += v3;
    voc += v2;
    cout << voc << endl << vocCpy << endl;
    Plantaza pred;
    (pred += voc) += vocCpy;
    pred(3);
    return 0;
}
