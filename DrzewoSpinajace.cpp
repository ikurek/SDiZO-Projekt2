#include "DrzewoSpinajace.h"

using namespace std;

DrzewoSpinajace::DrzewoSpinajace(int wierzcholki, int kr) {
    T = new ElementListy *[wierzcholki];
    for (int i = 0; i < wierzcholki; i++) {
        T[i] = NULL;
    }
    rozmiarT = wierzcholki - 1;
    waga = 0;
    krawedzie = kr;
    kk = new Krawedz[krawedzie];
    a = 0;
}

DrzewoSpinajace::~DrzewoSpinajace() {
    ElementListy *e1, *e2;
    for (int i = 0; i <= rozmiarT; i++) {
        e1 = T[i];
        while (e1) {
            e2 = e1;
            e1 = e1->nastepny;
            delete e2;
        }
    }

    delete[]T;
}

void DrzewoSpinajace::dodajKrawedz(Krawedz k) {
    ElementListy *e;

    waga += k.waga;
    e = new ElementListy;
    e->w = k.wk;
    e->waga = k.waga;
    e->nastepny = T[k.wp];
    T[k.wp] = e;

    e = new ElementListy;
    e->w = k.wp;
    e->waga = k.waga;
    e->nastepny = T[k.wk];
    T[k.wk] = e;

    kk[a] = k;
    a++;
}

void DrzewoSpinajace::wyswietl() {
    cout << endl;
    for (int i = 0; i < a; i++) {

        cout << "Krawedz " << i + 1 << ": ";

        cout << kk[i].wp << "<-->" << kk[i].wk << " [" << kk[i].waga << "] ";

        cout << endl;
    }
    cout << endl << endl << "Waga minimalnego drzewa rozpinajacego = " << waga << endl << endl;
}