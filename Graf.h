//
// Created by igor on 06.05.17.
//

#ifndef SDIZO_PROJEKT2_GRAF_H
#define SDIZO_PROJEKT2_GRAF_H


#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <queue>
#include <values.h>
#include "Krawedz.h"
#include "ElementListy.h"
#include "Stos.h"
#include "DrzewoSpinajace.h"

class Graf {
public:
    Graf(int w, int m);

    ~Graf();

    Krawedz *K, *KO;
    int **macierzIncydencji, **grafNieskierowanyM;
    ElementListy **listySasiedztwa, **grafNieskierowanyL;
    int wierzcholki, krawedzie, gestosc, krawedzieOdwrotne;
    ElementListy *e1, *e2;
    bool *odwiedzone;

public:

    void primMacierz();

    void wyswietl();

    void primLista();

    void DijkstraMacierz(int w);

    void DijkstraLista(int w);

    void DFSLista(int w);

    void DFSMacierz(int w);

    bool czySpojny();

    int getKrawedzie();

    int getWierzcholki();

    void losowyGraf();

    void losujKrawedzie();

    void grafNieskierowany();
};


#endif //SDIZO_PROJEKT2_GRAF_H
