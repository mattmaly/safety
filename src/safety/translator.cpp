#include "safety/translator.h"
#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/formulas/disjunction.h"
#include "safety/world.h"
#include <vector>
#include <queue>
#include <set>
#include <iostream>

Automaton Translator::translate(const Formula* f) {
    Automaton aut;
    std::vector<Formula*> initialStates(1, f->copy());
    std::queue<Formula*> upcoming;
    std::set<Formula*> processed;

    for (Formula* f : initialStates) {
        aut.addInitial(f);
        upcoming.push(f);
        processed.insert(f);
    }

    while (!upcoming.empty()) {
        Formula* next = upcoming.front();
        upcoming.pop();
        if (next->isTrue())
            aut.setAccepting(next, true);
        WorldIterator witer(next);
        while (witer.hasNext()) {
            World w = witer.next();
            Formula* neighbor = next->evaluate(w);
            Formula* simpNeighbor = neighbor->simplify();
            std::vector<Formula*> dests(1, simpNeighbor->copy());
            delete neighbor;
            delete simpNeighbor;

            for (Formula* dest : dests) {
                aut.addTransition(next, w, dest);
                if (processed.count(dest) > 0)
                    delete dest;
                else {
                    upcoming.push(dest);
                    processed.insert(dest);
                }
            }
        }
    }

    for (Formula* f : processed)
        delete f;

    return aut;
}

Translator::WorldIterator::WorldIterator(const Formula* f) :
    props(f->getProps()),
    size(props.empty() ? 0 : 1<<props.size()),
    index(0) {
}

bool Translator::WorldIterator::hasNext() {
    return index < size;
}

World Translator::WorldIterator::next() {
    World w;
    unsigned int setIndex = 0;
    for (int p : props) {
        w[p] = (index & (1 << setIndex)) != 0;
        ++setIndex;
    }
    ++index;
    return w;
}
