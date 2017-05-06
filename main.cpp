#include <iostream>
#include <ctime>
#include "Interfejs.h"

using namespace std;

int main() {
    srand(time(NULL));

    UI ui;
    ui.wyborMetodyGenerowaniaGrafu();
}