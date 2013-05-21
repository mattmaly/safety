#include <map>
#include <ostream>
#include <vector>
#include <algorithm>
#include "safety/automaton.h"
#include "safety/formula.h"
#include "safety/world.h"
#include "safety/util/hashmap.h"

Automaton::~Automaton() {
    freeMemory();
}

void Automaton::addTransition(Formula* src, const World& label, Formula* dest) {
    src = (edges.contains(src) ? edges.getKey(src) : src->copy());
    dest = (edges[src].contains(dest) ? edges[src].getKey(dest) : dest->copy());
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
    typedef HashMap<HashMap<std::vector<World> > >::iterator SourceIter;
    for (SourceIter s = edges.begin(); s != edges.end(); ++s) {
        Formula* src = s->first;
        if (formulaIndex.find(src) == formulaIndex.end())
            formulaIndex[src] = formulaIndex.size();
        out << "\"" << src << "\"";
        bool acc = accepting.contains(src) && accepting[src];
        out << " [shape=" << (acc ? "doublecircle" : "circle");
        if (!withStateLabels)
            out << ",label=\"\"";
        out << "]" << std::endl;
        HashMap<std::vector<World> >& outEdges = s->second;
        typedef HashMap<std::vector<World> >::iterator DestIter;
        for (DestIter d = outEdges.begin(); d != outEdges.end(); ++d) {
            const std::vector<World>& label = d->second;
            Formula* dest = d->first;
            out << "\"" << src << "\" -> \"" << dest << "\"";
            out << " [label=\"";
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

void Automaton::simplifyEdges() {
    typedef HashMap<HashMap<std::vector<World> > >::iterator SourceIter;
    typedef HashMap<std::vector<World> >::iterator DestIter;
    for (SourceIter s = edges.begin(); s != edges.end(); ++s) {
        HashMap<std::vector<World> >& outEdges = s->second;
        for (DestIter d = outEdges.begin(); d != outEdges.end(); ++d)
            simplifyEdge(d->second);
    }
}

void Automaton::freeMemory() {
    typedef HashMap<HashMap<std::vector<World> > >::iterator SourceIter;
    typedef HashMap<std::vector<World> >::iterator DestIter;
    for (SourceIter s = edges.begin(); s != edges.end(); ++s)
        (s->second).deleteFormulas();
    edges.deleteFormulas();

    accepting.deleteFormulas();

    typedef std::vector<Formula*>::iterator FormulaIter;
    for (FormulaIter f = initial.begin(); f != initial.end(); ++f)
        delete *f;
}

void Automaton::simplifyEdge(std::vector<World>& label) {
    std::vector<int> polarity(World::numProps(), 0);
    typedef std::vector<World>::const_iterator WorldIter;
    for (WorldIter wi = label.begin(); wi != label.end(); ++wi) {
        const World& w = *wi;
        for (unsigned int p = 0; p < World::numProps(); ++p)
            polarity[p] += (w[p] ? 1 : -1);
    }

    std::vector<World> newLabel;
    for (WorldIter wi = label.begin(); wi != label.end(); ++wi) {
        const World& w = *wi;
        World wSimp;
        for (unsigned int p = 0; p < World::numProps(); ++p) {
            if (polarity[p] != 0)
                wSimp[p] = w[p];
        }
        WorldIter wSimpLoc = std::find(newLabel.begin(), newLabel.end(), wSimp);
        if (wSimpLoc == newLabel.end())
            newLabel.push_back(wSimp);
    }
    label = newLabel;
}
