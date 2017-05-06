//
// Created by igor on 06.05.17.
//

#ifndef SDIZO_PROJEKT2_STOS_H
#define SDIZO_PROJEKT2_STOS_H


#include "ElementListy.h"

class Stos {

private:
    ElementListy *s;

public:

    Stos();

    ~Stos();

    bool empty();

    int top();

    void pop();

    void push(int w);
};


#endif //SDIZO_PROJEKT2_STOS_H
