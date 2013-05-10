#ifndef SAFETY_AUTOMATON_H
#define SAFETY_AUTOMATON_H

#include <map>
#include <ostream>
#include <vector>
#include "safety/formula.h"
#include "safety/world.h"

class Automaton {
public:
    ~Automaton();
    void addTransition(Formula* src, const World& label, Formula* dest);
    void setAccepting(const Formula* f, bool acc);
    void addInitial(const Formula* f);
    void write(std::ostream& out, bool withStateLabels = true);
    void simplifyEdges();
    
protected:
    void freeMemory();
    static void simplifyEdge(std::vector<World>& label);

    std::map<Formula*, std::map<Formula*, std::vector<World> > > edges;
    std::map<Formula*, bool> accepting;
    std::vector<Formula*> initial;
};

#endif
