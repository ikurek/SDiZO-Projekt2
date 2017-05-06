#include <iostream>
#include <ctime>
#include "UI.h"


using namespace std;

int main() {
    srand(time(NULL));

    UI ui;
    ui.start();
}