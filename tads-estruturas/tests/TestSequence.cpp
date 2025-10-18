#include <cassert>
#include <iostream>
#include "Sequence.h"

using namespace std;

void testinsertBegin() {
    Sequence* sequence = new Sequence();

    assert(sequence->isEmpty() == true);
    assert(sequence->getQuantity() == 0);

    sequence->insertBegin("a");
    assert(sequence->isEmpty() == false);
    assert(sequence->getQuantity() == 1);
    assert(sequence->get(1) == "a");

    sequence->insertBegin("b");
    assert(sequence->getQuantity() == 2);
    assert(sequence->get(1) == "b");
    assert(sequence->get(2) == "a");

    sequence->insertBegin("c");
    assert(sequence->getQuantity() == 3);
    assert(sequence->get(1) == "c");
    assert(sequence->get(2) == "b");
    assert(sequence->get(3) == "a");

    delete sequence;

    cout << "TestinsertBegin OK" << endl;
}

void testInsertEnd() {
    Sequence* sequence = new Sequence();
    assert(sequence->getQuantity() == 0);

    sequence->insertEnd("a");
    assert(sequence->getQuantity() == 1);
    assert(sequence->get(1) == "a");

    sequence->insertEnd("b");
    assert(sequence->getQuantity() == 2);
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "b");

    sequence->insertEnd("c");
    assert(sequence->getQuantity() == 3);
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "b");
    assert(sequence->get(3) == "c");

    sequence->insertEnd("x");
    assert(sequence->getQuantity() == 4);
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "b");
    assert(sequence->get(3) == "c");
    assert(sequence->get(4) == "x");

    delete sequence;

    cout << "TestInsertEnd OK" << endl;
}

void testRemoveBegin() {
    Sequence* sequence = new Sequence();
    sequence->insertEnd("a");
    sequence->insertEnd("b");
    sequence->insertEnd("c");

    std::string r1 = sequence->removeBegin();
    assert(r1 == "a");
    assert(sequence->getQuantity() == 2);
    assert(sequence->get(1) == "b");
    assert(sequence->get(2) == "c");

    std::string r2 = sequence->removeBegin();
    assert(r2 == "b");
    assert(sequence->getQuantity() == 1);
    assert(sequence->get(1) == "c");

    std::string r3 = sequence->removeBegin();
    assert(r3 == "c");
    assert(sequence->getQuantity() == 0);
    assert(sequence->isEmpty());

    cout << "TestRemoveBegin OK" << endl;
    delete sequence;
}

void testRemoveEnd() {
    Sequence* sequence = new Sequence();
    sequence->insertEnd("a");
    sequence->insertEnd("b");
    sequence->insertEnd("c");

    std::string r1 = sequence->removeEnd();
    assert(r1 == "c");
    assert(sequence->getQuantity() == 2);
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "b");

    std::string r2 = sequence->removeEnd();
    assert(r2 == "b");
    assert(sequence->getQuantity() == 1);
    assert(sequence->get(1) == "a");

    std::string r3 = sequence->removeEnd();
    assert(r3 == "a");
    assert(sequence->getQuantity() == 0);
    assert(sequence->isEmpty());

    cout << "TestRemoveEnd OK" << endl;
    delete sequence;
}

void testInsert() {
    Sequence* sequence = new Sequence();

    sequence->insertBegin("a");
    sequence->insert(1, "x");
    assert(sequence->get(1) == "x");
    assert(sequence->get(2) == "a");

    sequence->insert(2, "y");
    assert(sequence->get(1) == "x");
    assert(sequence->get(2) == "y");
    assert(sequence->get(3) == "a");

    sequence->insert(4, "z");
    assert(sequence->get(4) == "z");
    assert(sequence->getQuantity() == 4);

    cout << "TestInsert OK" << endl;
    delete sequence;
}

void testRemove() {
    Sequence* sequence = new Sequence();
    sequence->insertEnd("a");
    sequence->insertEnd("b");
    sequence->insertEnd("c");
    sequence->insertEnd("d");

    std::string r1 = sequence->remove(2);
    assert(r1 == "b");
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "c");
    assert(sequence->get(3) == "d");

    std::string r2 = sequence->remove(1);
    assert(r2 == "a");
    assert(sequence->get(1) == "c");
    assert(sequence->get(2) == "d");

    std::string r3 = sequence->remove(2);
    assert(r3 == "d");
    assert(sequence->get(1) == "c");
    assert(sequence->getQuantity() == 1);

    cout << "TestRemove OK" << endl;
    delete sequence;
}

int runSequenceTests() {
    testinsertBegin();
    testInsertEnd();
    testRemoveBegin();
    testRemoveEnd();
    testInsert();
    testRemove();

    std::cout << "TestAll OK" << std::endl;
    return 0;
}