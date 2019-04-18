# Trabalho 1

## Informações

* 18/04/2019
* Brasília, DF, Brasil
* Métodos de Programação
* TURMA A
* Professor: Jan Correa

## Autor

* **Bruno Sanguinetti R. Barros** - *180046063* - [BrunoSNT](https://github.com/BrunoSNT)

## Getting Started

Essas instruções farão com que você tenha uma cópia deste projeto em sua máquina local para fins de desenvolvimento e teste.

### Prerrequisitos

Para roda esse software você precisa ter instalado em sua maquina o googletest, uma biblioteca de testes unitários para a linguagem de programação C ++.

Por favor leia [TUTORIAL GTEST INSTALL](https://github.com/google/googletest/blob/master/googletest/README.md) para mais detalhes sobre como instalar o gtest

Por favor leia [GTEST INFO](https://github.com/google/googletest/blob/master/googletest/docs/primer.md) para mais detalhes sobre o gtest

Tenha certeza que o gtest está incluido.
```
@include "gtest/gtest"
```

### Compilando e Executando


Para compilar e executar o programa automaticamente, entre no diretorio /romano 
em que esta o arquivo Makefile e README e execute o seguinte comando:
```
~dir/romano user$ make run
```

Para apenas compilar

```
~dir/romano user$ make
```

## Testes

Os testes foram realizados em etapas previamente determidadas:

* teste de conversao de caractere - funcao converte()
* teste de conversao de strings - funcao avalia()
* teste de unidade na conversao romano-arabico
* teste de dezena na conversao romano-arabico
* teste de centena na conversao romano-arabico
* teste de milhar na conversao romano-arabico
* teste de conversao geral romano-arabico
* teste de tratamento de erros na conversao romano-arabico

Todos os testes foram feitos com comparação binaria fornecida pelo googletest
como pode ser observado no arquivo de testes [testa_romano.cpp](https://github.com/BrunoSNT/mp-trabalho1-180046063/blob/master/testa_romano.cc)

Fatal assertion          | Nonfatal assertion       | Verifies
------------------------ | ------------------------ | --------------
`ASSERT_EQ(val1, val2);` | `EXPECT_EQ(val1, val2);` | `val1 == val2`

## Testes de Coding Style

Durante todo o projeto, após cada aprovaçao nos teste, foram executados os comandos
```
cppcheck --enable=warning <file>
cpplint <file>
```
E em seguida feitas as devidas alterações para enquadrar o código nos padrões delimitados se nescessário

## Built With

* [Google Test](https://github.com/google/googletest) - Test framework
* [CPPLint]() - Coding Style Guide
* [CPPCheck]() - Static Code Analysis Tool
* [VSCode]() - Code Editor

## License

This project is licensed under the MIT License - see the [LICENSE](https://opensource.org/licenses/MIT) file for details

