#ifndef SAFETY_PROPOSITION_H
#define SAFETY_PROPOSITION_H

#include <istream>
#include <ostream>
#include <string>
#include "formula.h"

class Proposition : public Formula {
public:
    Proposition(const std::string& n);
    virtual ~Proposition();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;

protected:
    std::string name;
};

#endif
