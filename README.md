# Trabalho 1

## Informações

* 18/04/2019
* Brasília, DF, Brasil
* Métodos de Programação
* Turma: A - 01/2019
* Professor: Jan Correa

## Autor

* **Bruno Sanguinetti R. Barros** - *180046063* - GitHub -> [BrunoSNT](https://github.com/BrunoSNT)

## Getting Started

Essas instruções farão com que você tenha uma cópia deste projeto em sua máquina local para fins de desenvolvimento e teste.

### Pré-requisitos

Para roda esse software você precisa ter instalado em sua máquina o googletest, uma biblioteca de testes unitários para a linguagem de programação C ++.

Por favor leia [TUTORIAL GTEST INSTALL](https://github.com/google/googletest/blob/master/googletest/README.md) para mais detalhes sobre como instalar o gtest

Por favor leia [GTEST INFO](https://github.com/google/googletest/blob/master/googletest/docs/primer.md) para mais detalhes sobre o gtest

Tenha certeza que o gtest está incluido.
```
@include "gtest/gtest"
```

### Compilando e Executando


Entre no diretório ```../romano``` e execute o seguinte comando para compilar e executar:
```
~dir/romano user$ make run
```

Para apenas compilar

```
~dir/romano user$ make
```

## Testes

Todos os testes foram feitos com comparação binaria, não fatal (não interrompe o teste após detecção do erro), fornecida pelo googletest como pode ser observado no arquivo de testes [testa_romano.cpp](https://github.com/BrunoSNT/mp-trabalho1-180046063/blob/master/testa_romano.cpp)

Fatal assertion          | Nonfatal assertion       | Verifies
------------------------ | ------------------------ | --------------
`ASSERT_EQ(val1, val2);` | `EXPECT_EQ(val1, val2);` | `val1 == val2`

Os testes foram realizados em etapas previamente determidadas:

* teste de conversão de caractere - função converte()
* teste de conversão de strings - função avalia()
* teste de unidade na avaliação/conversao romano-arabico
* teste de dezena na avaliação/conversao romano-arabico
* teste de centena na avaliação/conversao romano-arabico
* teste de milhar na avaliação/conversao romano-arabico
* teste de avaliação/conversao geral romano-arabico
* teste de tratamento de erros na avaliação-conversao romano-arabico

O que se esperava do teste em todas as estapas era uma saída de valor correto em algarismos arabicos dada determinada entrada em algarismo romanos. Em caso de entradas inválidas a função deveria retornar -1.

## Testes de Coding Style

Durante todo o projeto, após cada aprovaçao nos teste, foram executados os comandos
```
cppcheck --enable=warning <file>
cpplint <file>
```
E em seguida feitas as devidas alterações para enquadrar o código nos padrões delimitados se nescessário

## Built With

* [Google Test](https://github.com/google/googletest) - Test framework
* [CPPLint](https://github.com/cpplint/cpplint) - Coding Style Guide
* [CPPCheck](cppcheck.sourceforge.net) - Static Code Analysis Tool
* [VSCode](https://code.visualstudio.com) - Code Editor

## License

This project is licensed under the MIT License - see the [LICENSE](https://opensource.org/licenses/MIT) file for details

