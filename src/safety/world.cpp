#include <cassert>
#include <map>
#include <ostream>
#include <string>
#include "safety/world.h"

bool World::contains(const std::string& p) const {
    const auto piter = World::propByName.find(p);
    if (piter == World::propByName.end())
        return false;
    return contains(piter->second);
}

bool World::contains(int pid) const {
    return assignment.contains(pid);
}

bool& World::operator[](const std::string& p) {
    const int pid = World::propByName.at(p);
    return this->operator[](pid);
}

bool& World::operator[](int pid) {
    return assignment[pid];
}

bool World::operator[](const std::string& p) const {
    const int pid = World::propByName.at(p);
    return this->operator[](pid);
}

bool World::operator[](int pid) const {
    return assignment.at(pid);
}

void World::write(std::ostream& out) const {
    if (assignment.empty()) {
        out << "true";
        return;
    }

    bool firstTerm = true;
    for (const auto& kv : propByName) {
        const std::string& propName = kv.first;
        const int pid = kv.second;
        const auto aiter = assignment.find(pid);
        if (aiter == assignment.end())
            continue;
        const bool valueForProp = aiter->second;
        if (!firstTerm)
            out << " & ";
        firstTerm = false;
        out << (valueForProp ? "" : "!") << propName;
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
