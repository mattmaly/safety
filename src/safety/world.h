#ifndef SAFETY_WORLD_H
#define SAFETY_WORLD_H

#include <map>
#include <ostream>
#include <string>

class World {
public:
    bool& operator[](const std::string& p);
    bool& operator[](int pid);

    bool operator[](const std::string& p) const;
    bool operator[](int pid) const;

    void write(std::ostream& out) const;
    void clear();

protected:
    std::map<int, bool> assignment;

public:
    static int registerProposition(const std::string& p);
    static unsigned int numProps();

protected:
    static std::map<std::string, int> propByName;
};

#endif
