#ifndef SAFETY_HASHMAP_H
#define SAFETY_HASHMAP_H

#include "safety/formula.h"
#include <limits>
#include <map>
#include <vector>

template <typename _T>
class HashMap {
public:
    HashMap() : buckets(std::numeric_limits<unsigned short>::max()) {
    }

    _T& operator[](const Formula* f) {
        return const_cast<_T&>(const_cast<const HashMap&>(*this)[f]);
    }

    const _T& operator[](const Formula* f) const {
        unsigned short index = hash(f);
        const std::map<Formula*, _T>& bucket = buckets[index];
        return bucket[f];
    }

protected:
    std::vector<std::map<Formula*, _T> > buckets;
};

#endif
