#ifndef __TAD__SET__
#define __TAD__SET__

#include <string>
#include "Node.h"

class Set {
private:
    Node<std::string>* head;
    int n;

public:
    Set();
    ~Set();

    bool add(const std::string& value);
    bool remove(const std::string& value);
    bool contains(const std::string& value) const;

    int size() const { return n; }
    bool isEmpty() const { return n == 0; }

    Set unionWith(const Set& other) const;
    Set intersectionWith(const Set& other) const;
    Set differenceWith(const Set& other) const;

    void print() const;

private:
    void clear();
};

#endif