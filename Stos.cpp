#include <cstdio>
#include "Stos.h"

Stos::Stos() {
    s = NULL;
}

Stos::~Stos() {
    while (s) pop();
}

bool Stos::empty() {
    return !s;
}

int Stos::top() {
    return s->w;
}

void Stos::pop() {
    if (s) {
        ElementListy *e = s;
        s = s->nastepny;
        delete e;
    }
}

void Stos::push(int w) {
    ElementListy *e = new ElementListy;
    e->w = w;
    e->nastepny = s;
    s = e;
}