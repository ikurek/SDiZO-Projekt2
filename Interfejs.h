#include <fstream>
#include <math.h>
#include <iomanip>
#include <queue>

#include "Krawedz.h"
#include "Stos.h"
#include "Graf.h"

class UI {
public:
    void wyborMetodyGenerowaniaGrafu();

    bool naPoczatek = true;
    int wybor, w, g, b;
    Graf *graf;

    void grafLosowy();

    void wyborFunkcji();

    void grafZPliku();
};
