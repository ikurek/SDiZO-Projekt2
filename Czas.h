#ifndef SDIZO_PROJEKT2_CZAS_H
#define SDIZO_PROJEKT2_CZAS_H

#include <chrono>

using namespace std;
using namespace std::chrono;

class Czas {
public:
    high_resolution_clock::time_point czasPoczatkowy;
    high_resolution_clock::time_point czasKoncowy;

    void czasStart();

    void czasStop();

    long czasWykonania();
};


#endif //SDIZO_PROJEKT2_CZAS_H
