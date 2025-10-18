#include "Set.h"
#include <iostream>

Set::Set() : head(nullptr), n(0) {}

Set::~Set() { clear(); }

void Set::clear() {
    Node<std::string>* cur = head;
    while (cur) {
        Node<std::string>* nx = cur->getNext();
        delete cur;
        cur = nx;
    }
    head = nullptr;
    n = 0;
}

bool Set::contains(const std::string& value) const {
    Node<std::string>* cur = head;
    while (cur) {
        if (cur->getValue() == value) return true;
        cur = cur->getNext();
    }
    return false;
}

bool Set::add(const std::string& value) {
    if (contains(value)) return false;
    Node<std::string>* node = new Node<std::string>(value, head);
    head = node;
    n++;
    return true;
}

bool Set::remove(const std::string& value) {
    Node<std::string>* cur = head;
    Node<std::string>* prev = nullptr;
    while (cur) {
        if (cur->getValue() == value) {
            if (prev) prev->setNext(cur->getNext());
            else head = cur->getNext();
            delete cur;
            n--;
            return true;
        }
        prev = cur;
        cur = cur->getNext();
    }
    return false;
}

Set Set::unionWith(const Set& other) const {
    Set out;
    for (Node<std::string>* cur = head; cur; cur = cur->getNext())
        out.add(cur->getValue());
    for (Node<std::string>* cur = other.head; cur; cur = cur->getNext())
        out.add(cur->getValue());
    return out;
}

Set Set::intersectionWith(const Set& other) const {
    Set out;
    for (Node<std::string>* cur = head; cur; cur = cur->getNext())
        if (other.contains(cur->getValue()))
            out.add(cur->getValue());
    return out;
}

Set Set::differenceWith(const Set& other) const {
    Set out;
    for (Node<std::string>* cur = head; cur; cur = cur->getNext())
        if (!other.contains(cur->getValue()))
            out.add(cur->getValue());
    return out;
}

void Set::print() const {
    Node<std::string>* cur = head;
    std::cout << "{ ";
    while (cur) {
        std::cout << cur->getValue();
        cur = cur->getNext();
        if (cur) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}