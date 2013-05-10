#include <cassert>
#include <map>
#include <ostream>
#include <string>
#include "safety/world.h"

bool& World::operator[](const std::string& p) {
    std::map<std::string, int>::const_iterator piter = World::propByName.find(p);
    assert(piter != World::propByName.end());
    const int pid = piter->second;
    return this->operator[](pid);
}

bool& World::operator[](int pid) {
    return assignment[pid];
}

bool World::operator[](const std::string& p) const {
    std::map<std::string, int>::const_iterator piter = World::propByName.find(p);
    assert(piter != World::propByName.end());
    const int pid = piter->second;
    return this->operator[](pid);
}

bool World::operator[](int pid) const {
    std::map<int, bool>::const_iterator aiter = assignment.find(pid);
    assert(aiter != assignment.end());
    return aiter->second;
}

void World::write(std::ostream& out) const {
    typedef std::map<std::string, int>::const_iterator PropNameIter;
    typedef std::map<int, bool>::const_iterator AssignmentIter;

    if (assignment.empty()) {
        out << "true";
        return;
    }

    bool firstTerm = true;
    for (PropNameIter piter = propByName.begin(); piter != propByName.end(); ++piter) {
        AssignmentIter aiter = assignment.find(piter->second);
        if (aiter == assignment.end())
            continue;
        if (!firstTerm)
            out << " & ";
        firstTerm = false;
        out << (aiter->second ? "" : "!") << piter->first;
    }
}

void World::clear() {
    assignment.clear();
}

bool World::operator==(const World& w) const {
    return assignment == w.assignment;
}

std::map<std::string, int> World::propByName;

int World::registerProposition(const std::string& p) {
    if (propByName.find(p) == propByName.end()) {
        const int pid = propByName.size();
        propByName[p] = pid;
        return pid;
    }
    return propByName[p];
}

unsigned int World::numProps() {
    return propByName.size();
}
