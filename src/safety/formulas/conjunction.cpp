#include <string>
#include "safety/formulas/conjunction.h"
#include "safety/world.h"
#include "safety/formulas/true.h"

Conjunction::Conjunction(const std::set<Formula*>& c) :
    CommutativeFormula(c) {
}

Conjunction::~Conjunction() {
}

Formula* Conjunction::copy() const {
    std::set<Formula*> copyChildren;
    for (Formula* c : children)
        copyChildren.insert(c->copy());
    return new Conjunction(copyChildren);
}

Formula* Conjunction::simplify() const {
    std::set<Formula*> simpChildren;
    for (Formula* c : children) {
        Formula* sc = c->simplify();
        if (sc->isFalse()) {
            for (Formula* cd : simpChildren)
                delete cd;
            return sc;
        }
        else if (sc->isTrue())
            delete sc;
        else {
            //if conjunction, pull its children up, and then delete it
            Conjunction* conChild = dynamic_cast<Conjunction*>(sc);
            if (conChild == NULL) {
                if (simpChildren.find(sc) == simpChildren.end())
                    simpChildren.insert(sc); //TODO memory leak if duplicate?
                else
                    delete sc;
            }
            else { //TODO memory leak?
                for (Formula* cc : conChild->children) {
                    if (simpChildren.find(cc) == simpChildren.end())
                        simpChildren.insert(cc);
                    else
                        delete cc;
                }
                conChild->children.clear();
                delete sc; //TODO does this prevent leak or is it overkill?
            }
        }
    }
    if (simpChildren.empty())
        return new True();
    if (simpChildren.size() == 1)
        return *simpChildren.begin();
    return new Conjunction(simpChildren);
}

Formula* Conjunction::evaluate(const World& w) const {
    std::set<Formula*> evalChildren;
    for (Formula* c : children) {
        Formula* evalChild = c->evaluate(w);
        if (evalChildren.find(evalChild) == evalChildren.end())
            evalChildren.insert(evalChild);
        else
            delete evalChild;
    }
    return new Conjunction(evalChildren);
}

std::string Conjunction::getType() const {
    return std::string("&");
}
