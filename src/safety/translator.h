#ifndef SAFETY_TRANSLATOR_H
#define SAFETY_TRANSLATOR_H

#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/world.h"
#include <vector>

class Translator {
public:
    /** Returns an Automaton that accepts precisely the set of
        traces of Worlds that satisfy the Formula f. */
    static Automaton translate(const Formula* f);

protected:
    /** A class that iterates over all possible truth assignments
        over all propositions contained in a given formula. */
    class WorldIterator {
    public:
        /** Constructs and initializes a WorldIterator
            over the propositions of a given formula. */
        WorldIterator(const Formula* f);

        /** Returns whether this WorldIterator contains remaining Worlds. */
        bool hasNext();

        /** Returns the next World. Behavior is undefined if this WorldIterator
            is already finished (i.e., if hasNext() returns false). */
        World next();

    protected:
        std::set<int> props;
        unsigned int size;
        unsigned int index;
    };
};

#endif
