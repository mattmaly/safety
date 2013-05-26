#ifndef SAFETY_WORLD_H
#define SAFETY_WORLD_H

#include <map>
#include <ostream>
#include <string>

class World {
public:
    /** Returns a bool-reference corresponding to a given
        proposition name, which must already be registered with World.
        Initializes a new bool assignment for this World if one does not
        already exist. */
    bool& operator[](const std::string& p);

    /** Returns a bool-reference corresponding to a given proposition ID.
        Initializes a new bool assignment for this World if one does not
        already exist. */
    bool& operator[](int pid);

    /** Returns a bool-value corresponding to a given proposition name,
        which must already be registered with World.
        The proposition must already have a bool assignment for this World. */
    bool operator[](const std::string& p) const;

    /** Returns a bool-value corresponding to a given proposition ID.
        The proposition must already have a bool assignment for this World. */
    bool operator[](int pid) const;

    /** Prints this World to a given output stream. */
    void write(std::ostream& out) const;

    /** Clears the truth assignment associated with this World. */
    void clear();

    /** Returns whether this World is equivalent to another World,
        by comparing their corresponding truth assignments. */
    bool operator==(const World& w) const;

protected:
    std::map<int, bool> assignment;

public:
    /** Registers a given proposition name with World; returns
        an ID corresponding to the proposition name.
        If the proposition name has already been registered,
        then the original ID is returned. */
    static int registerProposition(const std::string& p);

    /** Returns the number of propositions registered with World. */
    static unsigned int numProps();

protected:
    static std::map<std::string, int> propByName;
};

#endif
