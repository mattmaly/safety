#include "safety/translator.h"
#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/formulas/disjunction.h"
#include "safety/world.h"
#include <vector>
#include <queue>
#include <set>

Automaton Translator::translate(const Formula* f) {
    Automaton aut;
    std::vector<Formula*> initialStates(1, f->copy());
    std::queue<Formula*> upcoming;
    std::set<Formula*> processed;
    typedef std::vector<Formula*>::iterator FormulaIter;

    for (FormulaIter fi = initialStates.begin(); fi != initialStates.end(); ++fi) {
        aut.addInitial(*fi);
        upcoming.push(*fi);
        processed.insert(*fi);
    }

    while (!upcoming.empty()) {
        Formula* next = upcoming.front();
        upcoming.pop();
        if (next->isTrue())
            aut.setAccepting(next, true);
        WorldIterator witer;
        while (witer.hasNext()) {
            World w = witer.next();
            Formula* neighbor = next->evaluate(w);
            Formula* simpNeighbor = neighbor->simplify();
            std::vector<Formula*> dests(1, simpNeighbor->copy());
            delete neighbor;
            delete simpNeighbor;

            for (FormulaIter d = dests.begin(); d != dests.end(); ++d) {
                aut.addTransition(next, w, *d);
                if (processed.count(*d) > 0)
                    delete *d;
                else {
                    upcoming.push(*d);
                    processed.insert(*d);
                }
            }
        }
    }

    typedef std::set<Formula*>::iterator FormulaSetIter;
    for (FormulaSetIter i = processed.begin(); i != processed.end(); ++i)
        delete *i;

    return aut;
}

Translator::WorldIterator::WorldIterator() :
    numProps(World::numProps()),
    size(1<<numProps),
    index(0) {

}

bool Translator::WorldIterator::hasNext() {
    return index < size;
}

World Translator::WorldIterator::next() {
    World w;
    for (unsigned int pid = 0; pid < numProps; ++pid)
        w[pid] = (index & (1 << pid)) != 0;
    ++index;
    return w;
}
