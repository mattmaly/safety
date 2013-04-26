#ifndef SAFETY_TRUE_H
#define SAFETY_TRUE_H

#include <istream>
#include <ostream>
#include "formula.h"

class True : public Formula {
public:
    virtual ~True();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
};

#endif
