#ifndef SDIZO_PROJEKT2_DRZEWOSPINAJACE_H
#define SDIZO_PROJEKT2_DRZEWOSPINAJACE_H


#include "Krawedz.h"
#include "ElementListy.h"
#include <iostream>
#include <cstdio>

class DrzewoSpinajace {
private:

    ElementListy **T;

    Krawedz *kk;

    int rozmiarT;

    int waga, krawedzie;

    int a;

public:

    DrzewoSpinajace(int wierzcholki, int kr);

    ~DrzewoSpinajace();

    void dodajKrawedz(Krawedz k);

    void wyswietl();
};


#endif //SDIZO_PROJEKT2_DRZEWOSPINAJACE_H
