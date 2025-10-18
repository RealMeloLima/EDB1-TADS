##  Descrição Geral

### TAD Sequência
Implementado com **lista simplesmente encadeada**, trabalha com **índices 1-based** e permite:
- Inserção no início, fim ou em posição específica;
- Remoção no início, fim ou posição específica;
- Acesso a elementos (`get`);
- Impressão e contagem de elementos.

###  TAD Conjunto
Também implementado com **lista encadeada**, mas **sem repetição de elementos**.  
Inclui operações de:
- Inserção e remoção sem duplicatas;
- União, interseção e diferença entre conjuntos;
- Verificação de pertencimento e tamanho.

---

## Estrutura do projeto

tads-estruturas/
├── src/
│   ├── Main.cpp
│   ├── Sequence.cpp / Sequence.h
│   ├── Set.cpp / Set.h
│   └── Node.h
│
└── tests/
    ├── TestSequence.cpp
    └── TestSet.cpp



##  Compilação e Execução

###  Compilar e executar todos os testes
Execute no terminal dentro da pasta `tads-estruturas/`:

```bash
g++ -std=c++17 -Wall -Wextra -O2 \
  src/Sequence.cpp src/Set.cpp src/Main.cpp \
  -Isrc -o bin_all_tests
```

Depois rode o programa
```bash
./bin_all_tests
```
