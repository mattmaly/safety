#ifndef SAFETY_TRANSLATOR_H
#define SAFETY_TRANSLATOR_H

#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/world.h"
#include <vector>

class Translator {
public:
    static Automaton translate(const Formula* f);

protected:
    class WorldIterator {
    public:
        WorldIterator();
        bool hasNext();
        World next();

    protected:
        unsigned int numProps;
        unsigned int size;
        unsigned int index;
    };

    static std::vector<Formula*> splitDisjunctions(const Formula* f);
};

#endif
