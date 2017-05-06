//
// Created by igor on 06.05.17.
//

#ifndef SDIZO_PROJEKT2_UI_H
#define SDIZO_PROJEKT2_UI_H

#include <fstream>
#include <math.h>
#include <iomanip>
#include <queue>

#include "Krawedz.h"
#include "Stos.h"
#include "Graf.h"


class UI {
public:
    void start();

    bool naPoczatek = true;
    int wybor, w, g, b;
    Graf *graf;

    void grafLosowy();

    void wyborFunkcji();

    void grafZPliku();
};


#endif //SDIZO_PROJEKT2_UI_H
