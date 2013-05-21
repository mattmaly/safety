#ifndef SAFETY_HASHMAP_H
#define SAFETY_HASHMAP_H

#include "safety/formula.h"
#include <cstddef>
#include <iterator>
#include <limits>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>

template <typename _T>
class HashMap {
    friend class HashMapIterator;
public:
    class HashMapIterator :
        public std::iterator<std::forward_iterator_tag, _T> {
    public:
        HashMapIterator(HashMap* hm = NULL) : hashmap(hm) {
            if (hashmap != NULL) {
                bucketIter = hashmap->buckets.begin();
                while (bucketIter != hashmap->buckets.end() && bucketIter->empty())
                    ++bucketIter;
                if (bucketIter != hashmap->buckets.end())
                    valueIter = bucketIter->begin();
            }
        }
        HashMapIterator(const HashMapIterator& h) :
            hashmap(h.hashmap),
            bucketIter(h.bucketIter),
            valueIter(h.valueIter) {
        }
        HashMapIterator& operator=(const HashMapIterator& h) {
            hashmap = h.hashmap;
            bucketIter = h.bucketIter;
            valueIter = h.valueIter;
            return *this;
        }
        bool operator==(const HashMapIterator& h) const {
            if (hashmap == NULL && h.hashmap == NULL)
                return true;
            return hashmap==h.hashmap &&
                bucketIter==h.bucketIter &&
                valueIter==h.valueIter;
        }
        bool operator!=(const HashMapIterator& h) const {
            return !operator==(h);
        }
        std::pair<Formula* const, _T>& operator*() {
            return *valueIter;
        }
        std::pair<Formula* const, _T>* operator->() {
            return &operator*();
        }
        HashMapIterator& operator++() {
            ++valueIter;
            if (valueIter == bucketIter->end()) {
                do {
                    ++bucketIter;
                } while (bucketIter != hashmap->buckets.end() && bucketIter->empty());
                if (bucketIter == hashmap->buckets.end())
                    hashmap = NULL;
                else
                    valueIter = bucketIter->begin();
            }
            return *this;
        }
        HashMapIterator& operator++(int) {
            HashMapIterator tmp(*this);
            operator++();
            return tmp;
        }
    private:
        HashMap* hashmap;
        typename std::vector<std::map<Formula*, _T> >::iterator bucketIter;
        typename std::map<Formula*, _T>::iterator valueIter;
    };

    typedef HashMapIterator iterator;

    //HashMap() : buckets(std::numeric_limits<unsigned short>::max()) {
    HashMap() : buckets(1024) {
    }

    HashMapIterator begin() {
        return HashMapIterator(this);
    }

    HashMapIterator end() {
        return HashMapIterator();
    }

    Formula* getKey(Formula* f) const {
        unsigned short index = hash(f) % buckets.size();
        const std::map<Formula*, _T>& b = buckets[index];
        return b.find(f)->first;
    }

    _T& operator[](Formula* f) {
        unsigned short index = hash(f) % buckets.size();
        std::map<Formula*, _T>& b = buckets[index];
        return b[f];
    }

    const _T& operator[](Formula* f) const {
        unsigned short index = hash(f) % buckets.size();
        const std::map<Formula*, _T>& b = buckets[index];
        return b.find(f)->second;
    }

    bool contains(Formula* f) const {
        unsigned short index = hash(f) % buckets.size();
        const std::map<Formula*, _T>& b = buckets[index];
        return b.find(f) != b.end();
    }

    void deleteFormulas() {
        for (iterator i = begin(); i != end(); ++i)
            delete i->first;
    }

    friend std::ostream& operator<<(std::ostream& out, const HashMap& h) {
        typedef typename std::map<Formula*, _T>::const_iterator ValueIter;
        for (unsigned int b = 0; b < h.buckets.size(); ++b) {
            if (h.buckets[b].empty())
                continue;
            out << b << ":";
            for (ValueIter v = h.buckets[b].begin(); v != h.buckets[b].end(); ++v) {
                out << " [" << v->first << "|->" << v->second << "]";
            }
        }
        return out;
    }

protected:
    std::vector<std::map<Formula*, _T> > buckets;
};

#endif
