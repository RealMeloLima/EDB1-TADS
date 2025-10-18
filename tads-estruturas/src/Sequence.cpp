#include "Sequence.h"
#include "Node.h"
#include <string>
#include <stdexcept>
#include <iostream>

Sequence::Sequence() {
    this->first = nullptr;
    this->quantity = 0;
}

Sequence::~Sequence() {
    while (first != nullptr) {
        Node<std::string>* nx = first->getNext();
        delete first;
        first = nx;
    }
    quantity = 0;
}

bool Sequence::isEmpty() {
    return this->first == nullptr;
}

int Sequence::getQuantity() {
    return this->quantity;
}

void Sequence::insertBegin(std::string element) {
    Node<std::string>* node = new Node<std::string>(element, first);
    first = node;
    quantity++;
}

void Sequence::insertEnd(std::string element) {
    Node<std::string>* node = new Node<std::string>(element, nullptr);
    if (first == nullptr) {
        first = node;
    } else {
        Node<std::string>* curr = first;
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->setNext(node);
    }
    quantity++;
}

std::string Sequence::removeBegin() {
    if (first == nullptr) {
        throw std::out_of_range("Cannot removeBegin from empty Sequence");
    }
    Node<std::string>* aux = first;
    first = first->getNext();
    std::string value = aux->getValue();
    delete aux;
    quantity--;
    return value;
}

std::string Sequence::removeEnd() {
    if (first == nullptr) {
        throw std::out_of_range("Cannot removeEnd from empty Sequence");
    }
    Node<std::string>* curr = first;
    Node<std::string>* prev = nullptr;
    while (curr->getNext() != nullptr) {
        prev = curr;
        curr = curr->getNext();
    }
    if (prev == nullptr) {
        return removeBegin();
    }
    prev->setNext(nullptr);
    std::string result = curr->getValue();
    delete curr;
    quantity--;
    return result;
}

std::string Sequence::get(int i) {
    if (i < 1 || i > this->quantity) {
        throw std::out_of_range("Index out of range in Sequence::get");
    }
    Node<std::string>* curr = first;
    int pos = 1;
    while (pos < i) {
        curr = curr->getNext();
        pos++;
    }
    return curr->getValue();
}

void Sequence::insert(int i, std::string element) {
    if (i < 1 || i > this->quantity + 1) {
        throw std::out_of_range("Index out of range in Sequence::insert");
    }
    if (i == 1) {
        insertBegin(element);
        return;
    }
    if (i == this->quantity + 1) {
        insertEnd(element);
        return;
    }
    Node<std::string>* prev = first;
    int pos = 1;
    while (pos < i - 1) {
        prev = prev->getNext();
        pos++;
    }
    Node<std::string>* node = new Node<std::string>(element, prev->getNext());
    prev->setNext(node);
    this->quantity++;
}

std::string Sequence::remove(int i) {
    if (i < 1 || i > this->quantity) {
        throw std::out_of_range("Index out of range in Sequence::remove");
    }
    if (i == 1) {
        return removeBegin();
    }
    Node<std::string>* prev = first;
    int pos = 1;
    while (pos < i - 1) {
        prev = prev->getNext();
        pos++;
    }
    Node<std::string>* target = prev->getNext();
    prev->setNext(target->getNext());
    std::string result = target->getValue();
    delete target;
    this->quantity--;
    return result;
}

void Sequence::print() {
    Node<std::string>* curr = first;
    std::cout << "[";
    while (curr != nullptr) {
        std::cout << curr->getValue();
        curr = curr->getNext();
        if (curr != nullptr) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}