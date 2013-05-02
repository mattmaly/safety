#include <map>
#include <ostream>
#include <vector>
#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/world.h"

Automaton::~Automaton() {
    freeMemory();
}

void Automaton::addTransition(Formula* src, const World& label, const Formula* dest) {
    Edge edgeToAdd(label, dest->copy());
    std::map<Formula*, std::vector<Edge> >::iterator s = edges.find(src);
    if (s == edges.end())
        edges[src->copy()].push_back(edgeToAdd);
    else
        (s->second).push_back(edgeToAdd);
}

void Automaton::setAccepting(const Formula* f, bool acc) {
    accepting[f->copy()] = acc;
}

void Automaton::addInitial(const Formula* f) {
    initial.push_back(f->copy());
}

void Automaton::write(std::ostream& out, bool withStateLabels) {
    out << "digraph automaton {" << std::endl;
    out << "rankdir=LR" << std::endl;
    std::map<const Formula*, int> formulaIndex;

    typedef std::map<Formula*, std::vector<Edge> >::const_iterator StateIter;
    typedef std::vector<Edge>::const_iterator EdgeIter;
    for (StateIter s = edges.begin(); s != edges.end(); ++s) {
        Formula* src = s->first;
        if (formulaIndex.find(src) == formulaIndex.end())
            formulaIndex[src] = formulaIndex.size();
        out << "\"";
        src->write(out);
        bool acc = (accepting.find(src) != accepting.end()) && accepting.find(src)->second;
        out << "\" [shape=" << (acc ? "doublecircle" : "circle");
        if (!withStateLabels)
            out << ",label=\"\"";
        out << "]" << std::endl;
        const std::vector<Edge>& eVect = s->second;
        for (EdgeIter e = eVect.begin(); e != eVect.end(); ++e) {
            const World& label = e->world;
            Formula* dest = e->dest;
            out << "\"";
            src->write(out);
            out << "\" -> \"";
            dest->write(out);
            out << "\" [label=\"";
            label.write(out);
            out << "\"]" << std::endl;
        }
    }
    out << "}";
}

Automaton::Edge::Edge(const World& w, Formula* f) : world(w), dest(f) {
}

void Automaton::freeMemory() {
    typedef std::map<Formula*, std::vector<Edge> >::iterator StateIter;
    typedef std::vector<Edge>::iterator EdgeIter;
    for (StateIter s = edges.begin(); s != edges.end(); ++s) {
        delete s->first;
        std::vector<Edge>& edgeVect = s->second;
        for (EdgeIter e = edgeVect.begin(); e != edgeVect.end(); ++e)
            delete e->dest;
    }

    typedef std::map<Formula*, bool>::iterator AcceptingIter;
    for (AcceptingIter a = accepting.begin(); a != accepting.end(); ++a)
        delete a->first;

    typedef std::vector<Formula*>::iterator FormulaIter;
    for (FormulaIter f = initial.begin(); f != initial.end(); ++f)
        delete *f;
}
