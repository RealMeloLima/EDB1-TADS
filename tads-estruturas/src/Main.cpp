#include <iostream>

int runSequenceTests();
int runSetTests();

#include "../tests/TestSequence.cpp"
#include "../tests/TestSet.cpp"

int main() {
    std::cout << "=== TESTES TAD SEQUENCE ===" << std::endl;
    runSequenceTests();

    std::cout << std::endl;
    std::cout << "=== TESTES TAD SET ===" << std::endl;
    runSetTests();

    std::cout << std::endl << "=== TODOS OS TESTES FINALIZADOS COM SUCESSO ===" << std::endl;
    return 0;
}