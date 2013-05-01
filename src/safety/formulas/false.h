#ifndef SAFETY_FALSE_H
#define SAFETY_FALSE_H

#include <istream>
#include <ostream>
#include "safety/formula.h"
#include "safety/world.h"

class False : public Formula {
public:
    virtual ~False();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
    virtual Formula* copy() const;
    virtual Formula* evaluate(const World& w) const;
    virtual bool isFalse() const;
};

#endif
