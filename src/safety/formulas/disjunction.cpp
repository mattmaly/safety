#include <string>
#include "safety/formulas/disjunction.h"
#include "safety/world.h"
#include "safety/formulas/false.h"

Disjunction::Disjunction(const std::set<Formula*>& c) :
    CommutativeFormula(c) {
}

Disjunction::~Disjunction() {
}

Formula* Disjunction::copy() const {
    std::set<Formula*> copyChildren;
    typedef std::set<Formula*>::const_iterator ChildIter;
    for (ChildIter c = children.begin(); c != children.end(); ++c)
        copyChildren.insert((*c)->copy());
    return new Disjunction(copyChildren);
}

Formula* Disjunction::simplify() const {
    std::set<Formula*> simpChildren;
    typedef std::set<Formula*>::const_iterator ChildIter;
    for (ChildIter c = children.begin(); c != children.end(); ++c) {
        Formula* sc = (*c)->simplify();
        if (sc->isTrue()) {
            for (ChildIter cd = simpChildren.begin(); cd != simpChildren.end(); ++cd)
                delete *cd;
            return sc;
        }
        else if (sc->isFalse())
            delete sc;
        else {
            //if disjunction, pull its children up, and then delete it
            Disjunction* disChild = dynamic_cast<Disjunction*>(sc);
            if (disChild == NULL) {
                if (simpChildren.find(sc) == simpChildren.end())
                    simpChildren.insert(sc); //TODO memory leak if duplicate?
                else
                    delete sc;
            }
            else { //TODO memory leak?
                for (ChildIter dc = disChild->children.begin(); dc != disChild->children.end(); ++dc) {
                    if (simpChildren.find(*dc) == simpChildren.end())
                        simpChildren.insert(*dc);
                    else
                        delete *dc;
                }
                disChild->children.clear();
                delete disChild; //TODO does this prevent leak or is it overkill?
            }
        }
    }
    if (simpChildren.empty())
        return new False();
    if (simpChildren.size() == 1)
        return *simpChildren.begin();
    return new Disjunction(simpChildren);
}

Formula* Disjunction::evaluate(const World& w) const {
    std::set<Formula*> evalChildren;
    typedef std::set<Formula*>::const_iterator ChildIter;
    for (ChildIter c = children.begin(); c != children.end(); ++c) {
        Formula* evalChild = (*c)->evaluate(w);
        if (evalChildren.find(evalChild) == evalChildren.end())
            evalChildren.insert(evalChild);
        else
            delete evalChild;
    }
    return new Disjunction(evalChildren);
}

std::string Disjunction::getType() const {
    return std::string("|");
}
