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

/**
	\mainpage
	\author Bruno Sanguinetti 18/0046063
	\date Realease: 18/04/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "lib/romano.h"

int converte(const char* romano) {  // Funcao converte char de uma string
  if (romano[0] == 'I') {       // em seus respectivos valores decimais arabicos
    return 1;
  }
  if (romano[0] == 'V') {
    return 5;
  }
  if (romano[0] == 'X') {
    return 10;
  }
  if (romano[0] == 'L') {
    return 50;
  }
  if (romano[0] == 'C') {
    return 100;
  }
  if (romano[0] == 'D') {
    return 500;
  }
  if (romano[0] == 'M') {
    return 1000;
  }
  return -1;
}

int avalia(const char* romano) {
  int tamanho = 0, numero = 0, anterior = 0, repeticoes = 0;

  while (romano[tamanho]) {   // Contamos o tamanho do vetor
    tamanho++;
  }
  if (tamanho > 30) {        // Tratamento de erro, string +30 chars
    return -1;
  }
  int posicao = tamanho-1;    // Comecamos a percores da ultima posicao -1
  while (romano[posicao]) {   // para nao lermos o \0
    if (converte(&romano[posicao]) >= anterior) {    // avalia se iremos somar
      if (converte(&romano[posicao]) == anterior) {
        repeticoes++;   // contador para tratar repeticoes invalidas
        numero = numero + converte(&romano[posicao]);
      } else {
        numero = numero + converte(&romano[posicao]);
        repeticoes = 0;
      }
    } else {                                        // avalia se iremos subtrair
        if (converte(&romano[posicao]) >= anterior/10
          && converte(&romano[posicao]) != 5
          && converte(&romano[posicao]) != 50      // trata chars invalidos
          && converte(&romano[posicao]) != 500) {
          numero = numero - converte(&romano[posicao]);
        } else {
          return  -1;
        }
    }
    anterior = converte(&romano[posicao]);
    posicao--;
  }
  if (repeticoes >= 3 && numero != 0) {  // retorna -1 se numero
    return -1;                         // repeticoes for invalida
  } else {
    return numero;
  }
}

