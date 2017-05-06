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

    void macierz_Prim();

    void wyswietl();

    void lista_Prim();

    void macierz_Dijkstra(int w);

    void lista_Dijkstra(int w);

    void lista_DFS(int w);

    void macierz_DFS(int w);

    bool sprawdzSpojnosc();

    void losujGraf();

    void losujKrawedzie();

    void zamienGrafNaNieskierowany();
};

#endif //SDIZO_PROJEKT2_GRAF_H