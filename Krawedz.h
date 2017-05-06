#ifndef SDIZO_PROJEKT2_KRAWEDZ_H
#define SDIZO_PROJEKT2_KRAWEDZ_H

class Krawedz {
public:
    int wp, wk, waga;

    bool operator()(const Krawedz &k1, const Krawedz &k2) {
        if (k1.waga > k2.waga) return true;
        if (k1.waga < k2.waga) return false;
        return false;
    }
};


#endif //SDIZO_PROJEKT2_KRAWEDZ_H
