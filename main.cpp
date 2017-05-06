#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <queue>

#include "Krawedz.h"
#include "Stos.h"
#include "Graf.h"

using namespace std;

int main() {
    srand(time(NULL));
    int wybor, w, g, b;
    Graf *graf;
    bool naPoczatek = true;
    while (naPoczatek) {
        cout << "Stworz graf" << endl << "1. Wczytaj z pliku" << endl << "2. Wylosuj graf" << endl;
        cin >> wybor;
        system("cls");
        switch (wybor) {
            case 1: {
                naPoczatek = false;
                ElementListy *e1;
                string s, nazwa;
                int a = 0;
                int krawedzie, wierzcholki;
                cout << "Podaj nazwe pliku do wczytania grafu" << endl;
                cin >> nazwa;
                nazwa = nazwa + ".txt";
                ifstream plik(nazwa);
                if (!plik) {
                    cout << "Nie mozna otworzyc pliku" << endl;
                    naPoczatek = true;

                } else {

                    {
                        plik >> krawedzie >> wierzcholki;
                        if (!plik || krawedzie < wierzcholki - 1 || wierzcholki <= 1 ||
                            krawedzie > (wierzcholki * (wierzcholki - 1))) {
                            cout << "Cos nie tak!" << endl << "Liczba wierzcholkow lub krawedzi nie jest prawidlowa."
                                 << endl;

                            naPoczatek = true;
                        } else {
                            graf = new Graf(wierzcholki, krawedzie);
                            while (!plik.eof()) {

                                plik >> graf->K[a].wp >> graf->K[a].wk >> graf->K[a].waga;
                                if (graf->K[a].wp >= wierzcholki || graf->K[a].wk >= wierzcholki ||
                                    graf->K[a].waga < 1) {
                                    cout << "Cos nie tak! Zle podane krawedzie!" << endl;
                                    naPoczatek = true;
                                    break;
                                }
                                if (plik)
                                    a++;

                                else {
                                    cout << "Cos nie tak! Zle podane krawedzie!" << endl;
                                    naPoczatek = true;
                                    break;
                                }
                            }
                            if (a == krawedzie) {
                                for (int i = 0; i < wierzcholki; i++)
                                    graf->macierzIncydencji[i] = new int[krawedzie];
                                for (int i = 0; i < wierzcholki; i++)
                                    for (int j = 0; j < krawedzie; j++) {
                                        graf->macierzIncydencji[i][j] = 0;
                                    }

                                for (int i = 0; i < wierzcholki; i++)
                                    graf->listySasiedztwa[i] = NULL;

                                for (int i = 0; i < krawedzie; i++) {
                                    int wp = graf->K[i].wp;
                                    int wk = graf->K[i].wk;
                                    e1 = new ElementListy;
                                    e1->w = wk;
                                    e1->waga = graf->K[i].waga;
                                    e1->nastepny = graf->listySasiedztwa[wp];
                                    graf->listySasiedztwa[wp] = e1;
                                    graf->macierzIncydencji[wp][i] = 1;
                                    graf->macierzIncydencji[wk][i] = -1;
                                }
                                plik.close();
                                graf->grafNieskierowany();
                                if (!(graf->czySpojny())) {
                                    cout << "Graf, zbudowany z pliku jest niespojny, " << endl
                                         << "nie mozna kontynuowac!" << endl;
                                    naPoczatek = true;
                                    delete graf;
                                } else
                                    system("cls");
                                while (!naPoczatek) {
                                    cout << "Graf " << endl << "Wierzcholki: " << graf->getWierzcholki() << endl
                                         << "Krawedzie: " << graf->getKrawedzie() << endl
                                         << "1. Wyswietl" << endl << "2. DFS - macierz incydencji " << endl
                                         << "3. DFS - listy sasiedztwa" << endl << "4. Dijkstra - macierz incydencji"
                                         << endl << "5. Dijkstra - listy sasiedztwa" << endl
                                         << "6. Prim - macierz incydencji " << endl << "7. Prim - listy sasiedztwa"
                                         << endl << "8. Wroc do tworzenia grafu" << endl;
                                    cin >> wybor;
                                    switch (wybor) {
                                        case 1: {
                                            graf->wyswietl();

                                        }
                                            break;
                                        case 2: {
                                            while (true) {
                                                cout << "Od ktorego wierzcholka chcesz przejsc graf?" << endl;
                                                cin >> b;
                                                if (b < graf->getWierzcholki()) break;
                                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                                            }
                                            cout << endl;
                                            graf->DFSMacierz(b);

                                            cout << endl;
                                        }
                                            break;
                                        case 3: {
                                            while (true) {
                                                cout << "Od ktorego wierzcholka chcesz przejsc graf?" << endl;
                                                cin >> b;
                                                if (b < graf->getWierzcholki()) break;
                                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                                            }
                                            cout << endl;
                                            graf->DFSLista(b);
                                            cout << endl;
                                        }
                                            break;
                                        case 4: {
                                            while (true) {
                                                cout << "Z ktorego wierzcholka szukac najkrotszych sciezek?" << endl;
                                                cin >> b;
                                                if (b < graf->getWierzcholki()) break;
                                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                                            }
                                            cout << endl;
                                            graf->DijkstraMacierz(b);

                                        }
                                            break;
                                        case 5: {
                                            while (true) {
                                                cout << "Z ktorego wierzcholka szukac najkrotszych sciezek?" << endl;
                                                cin >> b;
                                                if (b < graf->getWierzcholki()) break;
                                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                                            }
                                            cout << endl;
                                            graf->DijkstraLista(b);

                                        }
                                            break;
                                        case 6: {
                                            graf->primMacierz();
                                        }
                                            break;
                                        case 7: {
                                            graf->primLista();
                                        }
                                            break;
                                        case 8: {
                                            delete graf;
                                            system("cls");
                                            naPoczatek = true;
                                        }
                                            break;
                                    }
                                }
                            } else if (naPoczatek == false) {
                                naPoczatek = true;
                                cout << "Cos nie tak!  Za malo danych w stosunku do podanych krawedzi!" << endl;
                            }
                        }
                    }
                }
            }
                break;
            case 2: {
                naPoczatek = false;
                while (true) {
                    cout << "Podaj liczbe wierzcholkow" << endl;
                    cin >> w;
                    if (w > 1) break;
                    else cout << "Liczba wierzcholkow musi byc wieksza od 1!" << endl;
                }


                int maxK = w * (w - 1);
                double minG = ceil((((double) w - 1) * 100) / (double) maxK);

                while (true) {

                    cout << "Podaj gestosc - co najmniej " << minG << " %" << endl;
                    cin >> g;
                    if (g < minG || g > 100)
                        cout << "Podaj prawidlowa wartosc w %!"
                             << endl << "Aby graf byl spojny, gestosc musi wynosic przynajmniej " << minG << " %"
                             << endl;
                    else
                        break;
                }
                double krawedzie = ceil((maxK * g) / 100);
                graf = new Graf(w, krawedzie);
                graf->losowyGraf();
                system("cls");

                while (!naPoczatek) {

                    cout << "Graf " << endl << "Wierzcholki: " << graf->getWierzcholki() << endl << "Krawedzie: "
                         << graf->getKrawedzie() << endl << "Gestosc: " << g << endl
                         << "1. Wyswietl" << endl << "2. DFS - macierz incydencji " << endl
                         << "3. DFS - listy sasiedztwa" << endl << "4. Dijkstra - macierz incydencji" << endl
                         << "5. Dijkstra - listy sasiedztwa" << endl << "6. Prim - macierz incydencji" << endl
                         << "7. Prim - listy sasiedztwa" << endl << "8. Wroc do tworzenia grafu" << endl;
                    cin >> wybor;
                    switch (wybor) {
                        case 1: {
                            graf->wyswietl();
                            cout << endl;

                        }
                            break;
                        case 2: {
                            while (true) {
                                cout << "Od ktorego wierzcholka chcesz przejsc graf?" << endl;
                                cin >> b;
                                if (b < graf->getWierzcholki()) break;
                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                            }
                            cout << endl;
                            graf->DFSMacierz(b);
                            cout << endl;
                        }
                            break;
                        case 3: {
                            while (true) {
                                cout << "Od ktorego wierzcholka chcesz przejsc graf?" << endl;
                                cin >> b;
                                if (b < graf->getWierzcholki()) break;
                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                            }
                            cout << endl;
                            graf->DFSLista(b);
                            cout << endl;
                        }
                            break;
                        case 4: {
                            while (true) {
                                cout << "Z ktorego wierzcholka szukac najkrotszych sciezek?" << endl;
                                cin >> b;
                                if (b < graf->getWierzcholki()) break;
                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                            }
                            cout << endl;
                            graf->DijkstraMacierz(b);

                        }
                            break;
                        case 5: {
                            while (true) {
                                cout << "Z ktorego wierzcholka szukac najkrotszych sciezek?" << endl;
                                cin >> b;
                                if (b < graf->getWierzcholki()) break;
                                else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                            }
                            cout << endl;
                            graf->DijkstraLista(b);

                        }
                            break;
                        case 6: {
                            graf->primMacierz();

                        }
                            break;
                        case 7: {
                            graf->primLista();

                        }
                            break;
                        case 8: {
                            delete graf;
                            system("cls");
                            naPoczatek = true;
                        }
                            break;
                    }
                }

            }
                break;
        }
    }
    system("pause");
    return 0;
}