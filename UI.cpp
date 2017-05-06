//
// Created by igor on 06.05.17.
//

#include "UI.h"

using namespace std;

void UI::start() {

    while (naPoczatek) {
        cout << "Etap I - Generowanie grafu:" << endl << "1. Wygeneruj losowy graf programowo" << endl
             << "2. Wygeneruj graf z pliku" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1: {
                grafLosowy();
                wyborFunkcji();
            }
                break;
            case 2: {
                grafZPliku();
                wyborFunkcji();
            }
                break;
        }
    }
}

void UI::grafLosowy() {
    naPoczatek = false;
    while (true) {
        cout << "Zdefiniuj ilość wierzchołków grafu: ";
        cin >> w;
        if (w > 1) break;
        else cout << "Liczba wierzchołków nie może być mniejsza lub równa 1." << endl;
    }


    int maxK = w * (w - 1);
    double minG = ceil((((double) w - 1) * 100) / (double) maxK);

    while (true) {

        cout << "Zdefiniuj gęstość grafu (minimum " << minG << "%): ";
        cin >> g;
        if (g < minG || g > 100)
            cout << "Podana gęstość nie pozwala na stworzenie grafu." << endl;
        else
            break;
    }
    double krawedzie = ceil((maxK * g) / 100);
    graf = new Graf(w, krawedzie);
    graf->losowyGraf();
};

void UI::grafZPliku() {
    naPoczatek = false;
    ElementListy *e1;
    string s, nazwa;
    int a = 0;
    int krawedzie, wierzcholki;
    cout << "Nazwa pliku (bez rozszerzenia!): ";
    cin >> nazwa;
    nazwa = nazwa + ".txt";
    ifstream plik(nazwa);
    if (!plik) {
        cout << "Nie udało się otworzyć pliku, spróbuj ponownie." << endl;
        naPoczatek = true;

    } else {

        {
            plik >> krawedzie >> wierzcholki;
            if (!plik || krawedzie < wierzcholki - 1 || wierzcholki <= 1 ||
                krawedzie > (wierzcholki * (wierzcholki - 1))) {
                cout << "Plik jest uszkodzony, lub dane w nim są w złym formacie." << endl;

                naPoczatek = true;
            } else {
                graf = new Graf(wierzcholki, krawedzie);
                while (!plik.eof()) {

                    plik >> graf->K[a].wp >> graf->K[a].wk >> graf->K[a].waga;
                    if (graf->K[a].wp >= wierzcholki || graf->K[a].wk >= wierzcholki ||
                        graf->K[a].waga < 1) {
                        cout << "Krawędzie w pliku są nieprawidłowo określone." << endl;
                        naPoczatek = true;
                        break;
                    }

                    if (plik) {
                        a++;
                    } else {
                        cout << "Krawędzie w pliku są nieprawidłowo określone." << endl;
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
                        cout << "Zawarty w pliku graf jest niespójny, nie można wykonać algorytmów!" << endl;
                        naPoczatek = true;
                        delete graf;
                    } else {
                        wyborFunkcji();
                    }

                } else if (!naPoczatek) {
                    naPoczatek = true;
                    cout << "W pliku brakuje danych dotyczących krawędzi grafu." << endl;
                }
            }
        }
    }
}

void UI::wyborFunkcji() {
    while (!naPoczatek) {

        cout << "Etap II - Analiza grafu przy pomocy algorytmów:" << endl
             << "1. Wyświetl macierz incydencji i reprezentację listową" << endl
             << "2. Algorytm DFS " << endl
             << "3. Algorytm Dijkstry" << endl
             << "4. Algorytm Prima" << endl
             << "5. Powrót do etapu I" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1: {
                graf->wyswietl();
                cout << endl;
            }
                break;
            case 2: {
                while (true) {
                    cout << "Zdefiniuj wierzchołek początkowy: ";
                    cin >> b;
                    if (b < graf->getWierzcholki()) break;
                    else cout << "Graf nie zawiera wierzchołka o tym numerze." << endl;
                }

                while (true) {
                    int wyborReprezentacji;
                    cout << "Jakiej reprezentacji użyć w algorytmie?" << endl << "1. Macierz Incydecji" << endl
                         << "2. Lista poprzedników i następników" << endl;
                    cin >> wyborReprezentacji;
                    if (wyborReprezentacji == 1) {
                        graf->DFSMacierz(b);
                        break;
                    } else if (wyborReprezentacji == 2) {
                        graf->DFSLista(b);
                        break;
                    }
                }
            }
                break;

            case 3: {
                while (true) {
                    cout << "Zdefiniuj wierzchołek początkowy: ";
                    cin >> b;
                    if (b < graf->getWierzcholki()) break;
                    else cout << "Podaj prawidlowy numer wierzcholka!" << endl;
                }

                while (true) {
                    int wyborReprezentacji;
                    cout << "Jakiej reprezentacji użyć w algorytmie?" << endl << "1. Macierz Incydecji" << endl
                         << "2. Lista poprzedników i następników" << endl;
                    cin >> wyborReprezentacji;
                    if (wyborReprezentacji == 1) {
                        graf->DijkstraMacierz(b);
                        break;
                    } else if (wyborReprezentacji == 2) {
                        graf->DijkstraLista(b);
                        break;
                    }
                }
            }
                break;


            case 4: {
                while (true) {
                    int wyborReprezentacji;
                    cout << "Jakiej reprezentacji użyć w algorytmie?" << endl << "1. Macierz Incydecji" << endl
                         << "2. Lista poprzedników i następników" << endl;
                    cin >> wyborReprezentacji;
                    if (wyborReprezentacji == 1) {
                        graf->primMacierz();
                        break;
                    } else if (wyborReprezentacji == 2) {
                        graf->primLista();
                        break;
                    }
                }

            }
                break;

            case 5: {
                delete graf;
                naPoczatek = true;
            }
                break;
        }
    }
}