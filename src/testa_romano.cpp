// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.

// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "lib/romano.h"
namespace {
}
// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

  // test case.
  // Para todos os testes, dada uma entrada,
  // esperamos uma saida, no modelo abaixo
  // funcao_teste(<valor esperado da saida>, funcao_sendo_testada(minha entrada)

TEST(TestaROMANO, Conversao) {      // Testes da funcao de conversao
  EXPECT_EQ(1,    converte("I"));   // entrada I, saida 1
  EXPECT_EQ(5,    converte("V"));   // entrada V, saida 5
  EXPECT_EQ(10,   converte("X"));   //...
  EXPECT_EQ(50,   converte("L"));
  EXPECT_EQ(100,  converte("C"));
  EXPECT_EQ(500,  converte("D"));
  EXPECT_EQ(1000, converte("M"));
  EXPECT_EQ(-1,   converte("A"));
}

TEST(TestaROMANO, Avaliacao) {    // Testes da funcao de avaliacao
  EXPECT_EQ(1,      avalia("I"));
  EXPECT_EQ(5,      avalia("V"));
  EXPECT_EQ(10,     avalia("X"));
  EXPECT_EQ(50,     avalia("L"));
  EXPECT_EQ(100,    avalia("C"));
  EXPECT_EQ(500,    avalia("D"));
  EXPECT_EQ(1000,   avalia("M"));
  EXPECT_EQ(-1,     avalia("A"));
}

TEST(TestaROMANO, Unidades) {   // Testes da funcao de avaliacao com unidades
  EXPECT_EQ(2,  avalia("II"));
  EXPECT_EQ(3,  avalia("III"));
  EXPECT_EQ(4,  avalia("IV"));
  EXPECT_EQ(6,  avalia("VI"));
  EXPECT_EQ(7,  avalia("VII"));
  EXPECT_EQ(8,  avalia("VIII"));
  EXPECT_EQ(9,  avalia("IX"));
  EXPECT_EQ(-1, avalia("AB"));
}

TEST(TestaROMANO, Dezenas) {  // Testes da funcao de avaliacao com dezenas
  EXPECT_EQ(20,  avalia("XX"));
  EXPECT_EQ(30,  avalia("XXX"));
  EXPECT_EQ(40,  avalia("XL"));
  EXPECT_EQ(60,  avalia("LX"));
  EXPECT_EQ(70,  avalia("LXX"));
  EXPECT_EQ(80,  avalia("LXXX"));
  EXPECT_EQ(90,  avalia("XC"));
  EXPECT_EQ(-1,  avalia("ABE"));
}

TEST(TestaROMANO, Centenas) {      // Testes da funcao de avaliacao com centenas
  EXPECT_EQ(200,  avalia("CC"));
  EXPECT_EQ(300,  avalia("CCC"));
  EXPECT_EQ(400,  avalia("CD"));
  EXPECT_EQ(600,  avalia("DC"));
  EXPECT_EQ(700,  avalia("DCC"));
  EXPECT_EQ(800,  avalia("DCCC"));
  EXPECT_EQ(900,  avalia("CM"));
}
TEST(TestaROMANO, Milhares) {   // Testes da funcao de avaliacao com milhares
  EXPECT_EQ(2000,  avalia("MM"));
  EXPECT_EQ(3000,  avalia("MMM"));
}

TEST(TestaROMANO, NumerosAleatorios) {  // Testes da funcao de avaliacao com
  EXPECT_EQ(2852,  avalia("MMDCCCLII"));  // numero aleatorios
  EXPECT_EQ(2457,  avalia("MMCDLVII"));
  EXPECT_EQ(2013,  avalia("MMXIII"));
  EXPECT_EQ(1459,  avalia("MCDLIX"));
  EXPECT_EQ(1173,  avalia("MCLXXIII"));
  EXPECT_EQ(993,   avalia("CMXCIII"));
  EXPECT_EQ(736,   avalia("DCCXXXVI"));
  EXPECT_EQ(346,   avalia("CCCXLVI"));
  EXPECT_EQ(121,   avalia("CXXI"));
  EXPECT_EQ(69,    avalia("LXIX"));
  EXPECT_EQ(34,    avalia("XXXIV"));
}

TEST(TestaROMANO, Erros) {   // Testes da funcao em que esperamos -1
  EXPECT_EQ(-1,   avalia("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"));  // +30 chars
  EXPECT_EQ(-1,   avalia("XXXX"));        // Inicio de numeros invalidos
  EXPECT_EQ(-1,   avalia("LLLLLLLLLLL"));
  EXPECT_EQ(-1,   avalia("XXXLLLXXX"));
  EXPECT_EQ(383,  avalia("CCCLXXXIII"));
  EXPECT_EQ(-1,   avalia("IL"));
  EXPECT_EQ(-1,   avalia("IC"));
  EXPECT_EQ(-1,   avalia("ID"));
  EXPECT_EQ(-1,   avalia("IM"));
  EXPECT_EQ(-1,   avalia("VX"));
  EXPECT_EQ(-1,   avalia("VL"));
  EXPECT_EQ(-1,   avalia("VC"));
  EXPECT_EQ(-1,   avalia("VD"));
  EXPECT_EQ(-1,   avalia("VM"));
  EXPECT_EQ(40,   avalia("XL"));    // ...
  EXPECT_EQ(40,   avalia("XL"));
  EXPECT_EQ(90,   avalia("XC"));
  EXPECT_EQ(-1,   avalia("XD"));
  EXPECT_EQ(-1,   avalia("XM"));
  EXPECT_EQ(-1,   avalia("LC"));
  EXPECT_EQ(-1,   avalia("LD"));
  EXPECT_EQ(-1,   avalia("LM"));
  EXPECT_EQ(150,   avalia("CL"));
  EXPECT_EQ(400,   avalia("CD"));
  EXPECT_EQ(900,   avalia("CM"));
  EXPECT_EQ(-1,   avalia("DM"));    // Fim dos numeros invalidos
}
// <TechnicalDetails>
//
// EXPECT_EQ(expected, actual) is the same as
//
//   EXPECT_TRUE((expected) == (actual))
//
// except that it will print both the expected value and the actual
// value when the assertion fails.  This is very helpful for
// debugging.  Therefore in this case EXPECT_EQ is preferred.
//
// On the other hand, EXPECT_TRUE accepts any Boolean expression,
// and is thus more general.
//
// </TechnicalDetails>
// namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
