#include <map>
#include <ostream>
#include <vector>
#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/world.h"

Automaton::~Automaton() {
    freeMemory();
}

void Automaton::addTransition(Formula* src, const World& label, Formula* dest) {
    typedef std::map<Formula*, std::map<Formula*, std::vector<World> > >::iterator SourceIter;
    SourceIter s = edges.find(src);
    src = (s == edges.end() ? src->copy() : s->first);
    typedef std::map<Formula*, std::vector<World> >::iterator DestIter;
    DestIter d = edges[src].find(dest);
    dest = (d == edges[src].end() ? dest->copy() : d->first);
    edges[src][dest].push_back(label);
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
    typedef std::map<Formula*, std::map<Formula*, std::vector<World> > >::const_iterator SourceIter;
    typedef std::map<Formula*, std::vector<World> >::const_iterator DestIter;

    for (SourceIter s = edges.begin(); s != edges.end(); ++s) {
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
        const std::map<Formula*, std::vector<World> >& outEdges = s->second;
        for (DestIter d = outEdges.begin(); d != outEdges.end(); ++d) {
            const std::vector<World>& label = d->second;
            Formula* dest = d->first;
            out << "\"";
            src->write(out);
            out << "\" -> \"";
            dest->write(out);
            out << "\" [label=\"";
            typedef std::vector<World>::const_iterator WorldIter;
            WorldIter w = label.begin();
            if (label.size() > 1)
                out << "(";
            w->write(out);
            if (label.size() > 1)
                out << ")";
            ++w;
            for (; w != label.end(); ++w) {
                out << " | (";
                w->write(out);
                out << ")";
            }
            out << "\"]" << std::endl;
        }
    }
    out << "}";
}

void Automaton::freeMemory() {
    typedef std::map<Formula*, std::map<Formula*, std::vector<World> > >::iterator SourceIter;
    typedef std::map<Formula*, std::vector<World> >::iterator DestIter;
    for (SourceIter s = edges.begin(); s != edges.end(); ++s) {
        delete s->first;
        std::map<Formula*, std::vector<World> >& outEdges = s->second;
        for (DestIter d = outEdges.begin(); d != outEdges.end(); ++d)
            delete d->first;
    }

    typedef std::map<Formula*, bool>::iterator AcceptingIter;
    for (AcceptingIter a = accepting.begin(); a != accepting.end(); ++a)
        delete a->first;

    typedef std::vector<Formula*>::iterator FormulaIter;
    for (FormulaIter f = initial.begin(); f != initial.end(); ++f)
        delete *f;
}
