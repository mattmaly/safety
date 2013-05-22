#ifndef SAFETY_UNTIL_H
#define SAFETY_UNTIL_H

#include <string>
#include "safety/formula.h"

class Until : public Formula {
public:
    Until(Formula* lChild = NULL, Formula* rChild = NULL);
    virtual ~Until();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
    virtual const Formula* getLeft() const;
    virtual const Formula* getRight() const;

protected:
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;

    Formula* left;
    Formula* right;
};

#endif
