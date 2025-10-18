int runSetTests() {
    Set A, B;
    assert(A.isEmpty());
    assert(A.add("a"));
    assert(!A.add("a"));
    assert(A.add("b"));
    assert(A.contains("a"));
    assert(A.contains("b"));
    assert(A.size() == 2);

    assert(B.add("b"));
    assert(B.add("c"));

    Set U = A.unionWith(B);
    Set I = A.intersectionWith(B);
    Set D = A.differenceWith(B);

    std::cout << "A="; A.print();
    std::cout << "B="; B.print();
    std::cout << "U="; U.print();
    std::cout << "I="; I.print();
    std::cout << "D="; D.print();

    assert(A.remove("a"));
    assert(!A.remove("z"));
    assert(A.size() == 1);

    std::cout << "TestSet OK" << std::endl;
    return 0;
}