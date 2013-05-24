#ifndef SAFETY_AUTOMATON_H
#define SAFETY_AUTOMATON_H

#include <map>
#include <ostream>
#include <set>
#include <vector>
#include "safety/formula.h"
#include "safety/world.h"

class Automaton {
public:
    /** Clears all memory associated with this automaton. */
    ~Automaton();

    /** Adds a transition to this automaton, from the state corresponding
        to Formula src to the state corresponding to Formula dest,
        with the edge corresponding to World label.
        Stores deep copies of both src and dest.
        Only one deep copy will be made of any given Formula,
        where equality is measured according to the string
        representation of the Formula. */
    void addTransition(Formula* src, const World& label, Formula* dest);

    /** Sets the state corresponding to the Formula f to have
        acceptance condition acc. Stores a deep copy of f.
        Only one deep copy will be made of any given Formula,
        where equality is measured according to the string
        representation of the Formula. */
    void setAccepting(Formula* f, bool acc);

    /** Adds the state corresponding to the Formula f as an
        initial state of the automaton. Stores a deep copy of f.
        Only one deep copy will be made of any given Formula,
        where equality is measured according to the string
        representation of the Formula. */
    void addInitial(Formula* f);

    /** Prints this automaton to a given output stream.
        If flag withStateLabels is true, then each automaton state
        is labeled with its corresponding Formula. */
    void write(std::ostream& out, bool withStateLabels = true);

    /** Simplifies the disjunctions along each edge of the automaton. */
    void simplifyEdges();
    
protected:
    /** Clears all memory associated with this automaton. */
    void freeMemory();

    /** Simplifies a given disjunction of Worlds. */
    static void simplifyEdge(std::vector<World>& label);

    std::map<Formula*, std::map<Formula*, std::vector<World> > > edges;
    std::map<Formula*, bool> accepting;
    std::set<Formula*> initial;
};

#endif
